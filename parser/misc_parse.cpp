#include "misc_parse.h"

#include "../interpreter/grouping_node.h"

namespace math_parser::parser {
using namespace lexer;
using namespace interpreter;

std::unique_ptr<AstNode> GroupingNudParseFn(Parser &parser, Token &token) {
  auto right = parser.ParseExpression(0);
  // Eat the closing parenthesis
  parser.Advance();
  return std::make_unique<GroupingNode>(std::move(right));
}

}  // namespace math_parser::parser