#include "../interpreter/number_node.h"
#include "number_parse.h"

namespace math_parser::parser {
using namespace lexer;
using namespace interpreter;

std::unique_ptr<AstNode> NumberNudParseFn(Parser & /*parser*/, Token &token) {
  return std::make_unique<NumberNode>(token.value);
}

}  // namespace math_parser::parser