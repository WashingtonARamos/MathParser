#include "arithmetic_parse.h"

#include "../interpreter/division_node.h"
#include "../interpreter/multiplication_node.h"
#include "../interpreter/subtraction_node.h"
#include "../interpreter/sum_node.h"
#include "../interpreter/unary_minus_node.h"
#include "../lexer/token.h"
#include "binding_power.h"
#include "parser.h"

namespace math_parser::parser {
using namespace interpreter;
using namespace lexer;

constexpr auto plus_rbp = GetLedBindingPower(TokenType::PLUS).rbp;
constexpr auto div_rbp = GetLedBindingPower(TokenType::DIVISION).rbp;
constexpr auto mul_rbp = GetLedBindingPower(TokenType::MULTIPLICATION).rbp;
constexpr auto sub_rbp = GetLedBindingPower(TokenType::MINUS).rbp;
constexpr auto unary_minus_rbp = GetNudRightBindingPower(TokenType::MINUS);

std::unique_ptr<AstNode> MinusNudParseFn(Parser &parser, Token & /*token*/) {
  auto right = parser.ParseExpression(unary_minus_rbp);
  return std::make_unique<UnaryMinus>(std::move(right));
}

std::unique_ptr<AstNode> MinusLedParseFn(Parser &parser, Token & /*token*/,
                                         std::unique_ptr<AstNode> left) {
  auto right = parser.ParseExpression(sub_rbp);
  return std::make_unique<SubtractionNode>(std::move(left), std::move(right));
}

std::unique_ptr<AstNode> PlusLedParseFn(Parser &parser, Token & /*token*/,
                                        std::unique_ptr<AstNode> left) {
  auto right = parser.ParseExpression(plus_rbp);
  return std::make_unique<SumNode>(std::move(left), std::move(right));
}

std::unique_ptr<AstNode> MultiplicationLedParseFn(
    Parser &parser, Token & /*token*/, std::unique_ptr<AstNode> left) {
  auto right = parser.ParseExpression(mul_rbp);
  return std::make_unique<MultiplicationNode>(std::move(left),
                                              std::move(right));
}

std::unique_ptr<AstNode> DivisionLedParseFn(Parser &parser, Token & /*token*/,
                                            std::unique_ptr<AstNode> left) {
  auto right = parser.ParseExpression(div_rbp);
  return std::make_unique<DivisionNode>(std::move(left), std::move(right));
}

}  // namespace math_parser::parser