#include "parser.h"

#include "../interpreter/unary_minus_node.h"
#include "arithmetic_parse.h"
#include "binding_power.h"
#include "misc_parse.h"
#include "number_parse.h"

namespace math_parser::parser {

using namespace lexer;
using namespace interpreter;

// Returns the current token and advances the lexer to the next one
Token Parser::Advance() {
  auto token = current;
  current = lexer.NextToken();
  return token;
}

std::unique_ptr<AstNode> Parser::ParseExpression(int32_t caller_binding_power) {
  // Get the current token and advance the lexer
  auto token = Advance();

  // Check if it has a NUD
  if (!nud_parse_fns.contains(token.type)) {
    throw std::runtime_error("Expected expression");
  }

  // Parse the first token using the NUD function associated with it
  auto nud_fn = nud_parse_fns.at(token.type);
  auto left = nud_fn(*this, token);

  // Peek at the upcoming token's binding power before looping
  auto [lbp, rbp] = GetLedBindingPower(current.type);

  // Continue consuming tokens as long as the upcoming operator's left binding
  // power exceeds the binding power of the context that called us
  while (caller_binding_power < lbp) {
    // Get the current token, advance the lexer and get the token's LED function
    token = Advance();
    auto led_fn = led_parse_fns.at(token.type);

    // Call the LED passing in the current token and the left operand
    // The lexer is now pointing at the token to the right of the operator
    left = led_fn(*this, token, std::move(left));

    // We gave a non-const Parser reference to led_fn, we expect it to have kept
    // parsing until it reached another token with lower binding power, so we
    // need to refresh lbp with the current token's binding power
    lbp = GetLedBindingPower(current.type).lbp;
  }

  return left;
}

void Parser::InitializeParseFns() {
  nud_parse_fns[TokenType::NUMBER] = NumberNudParseFn;
  nud_parse_fns[TokenType::LEFT_PARENTHESIS] = GroupingNudParseFn;

  // TokenType::MINUS has both a NUD and a LED function associated with it
  nud_parse_fns[TokenType::MINUS] = MinusNudParseFn;
  led_parse_fns[TokenType::MINUS] = MinusLedParseFn;

  led_parse_fns[TokenType::PLUS] = PlusLedParseFn;
  led_parse_fns[TokenType::MULTIPLICATION] = MultiplicationLedParseFn;
  led_parse_fns[TokenType::DIVISION] = DivisionLedParseFn;
}

}  // namespace math_parser::parser