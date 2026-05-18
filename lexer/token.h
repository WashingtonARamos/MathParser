#ifndef MATH_PARSER_TOKEN_H
#define MATH_PARSER_TOKEN_H
#include <string>

namespace math_parser::lexer {

enum class TokenType {
  NUMBER,
  PLUS,
  MINUS,
  DIVISION,
  MULTIPLICATION,
  LEFT_PARENTHESIS,
  RIGHT_PARENTHESIS,
  END_OF_FILE
};

struct Token {
  TokenType type;
  std::string value;
};

}  // namespace math_parser::lexer

#endif