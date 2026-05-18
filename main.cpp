#include <cassert>
#include <iostream>

#include "lexer/lexer.h"
#include "parser/parser.h"

using namespace math_parser::lexer;
using namespace math_parser::parser;

int main() {
  std::string_view expr = "10 + 2 * 3 - 4 / 2";

  Lexer lexer{expr};
  Parser parser{lexer};
  const auto ast_tree = parser.ParseExpression(0);

  assert(ast_tree->Evaluate() == 14);
  return 0;
}