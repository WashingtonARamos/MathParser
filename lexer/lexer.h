#ifndef MATH_PARSER_LEXER_H
#define MATH_PARSER_LEXER_H
#include <cstdint>
#include <string_view>

#include "token.h"

namespace math_parser::lexer {

struct Lexer {
  Lexer(std::string_view &string_view) : string_view(string_view) {}
  Token NextToken();

 private:
  uint32_t pos = 0;
  std::string_view &string_view;
  char Peek() const;
};

}  // namespace math_parser::lexer
#endif  // MATH_PARSER_LEXER_H
