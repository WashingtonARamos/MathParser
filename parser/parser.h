#ifndef MATH_PARSER_PARSER_H
#define MATH_PARSER_PARSER_H
#include <functional>
#include <memory>

#include "../interpreter/ast_node.h"
#include "../lexer/lexer.h"

namespace math_parser::parser {
struct Parser;

using Led = std::function<std::unique_ptr<interpreter::AstNode>(
    Parser &, lexer::Token &, std::unique_ptr<interpreter::AstNode>)>;
using Nud = std::function<std::unique_ptr<interpreter::AstNode>(
    Parser &, lexer::Token &)>;

struct Parser {
  Parser(lexer::Lexer &lexer) : lexer(lexer) {
    current = lexer.NextToken();
    InitializeParseFns();
  }
  std::unique_ptr<interpreter::AstNode> ParseExpression(
      int32_t caller_binding_power);
  lexer::Token Advance();

 private:
  lexer::Token current;
  lexer::Lexer &lexer;
  std::unordered_map<lexer::TokenType, Led> led_parse_fns;
  std::unordered_map<lexer::TokenType, Nud> nud_parse_fns;
  void InitializeParseFns();
};

}  // namespace math_parser::parser

#endif
