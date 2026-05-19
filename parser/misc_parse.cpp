#include "misc_parse.h"

#include "binding_power.h"

namespace math_parser::parser {
using namespace lexer;
using namespace interpreter;

constexpr auto left_parenthesis_rbp =
    GetNudRightBindingPower(TokenType::LEFT_PARENTHESIS);

std::unique_ptr<AstNode> GroupingNudParseFn(Parser &parser, Token &token) {
  auto right = parser.ParseExpression(left_parenthesis_rbp);
  // Eat the closing parenthesis
  parser.Advance();
  return right;
}

}  // namespace math_parser::parser