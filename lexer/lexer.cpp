#include "lexer.h"

#include <stdexcept>
#include <utility>

namespace math_parser::lexer {

char Lexer::Peek() const {
  if (pos >= string_view.size()) return '\0';

  return string_view[pos];
}

Token Lexer::NextToken() {
  while (pos < string_view.size() &&
         std::isspace(static_cast<unsigned char>(Peek()))) {
    ++pos;
  }

  if (pos >= string_view.size())
    return Token(TokenType::END_OF_FILE, "");

  const char c = Peek();

  if (std::isdigit(static_cast<unsigned char>(c))) {
    std::string val;
    while (std::isdigit(static_cast<unsigned char>(Peek())) || Peek() == '.') {
      val += Peek();
      ++pos;
    }
    return Token(TokenType::NUMBER, val);
  }

  ++pos;
  switch (c) {
    case '+':
      return Token(TokenType::PLUS, "+");
    case '-':
      return Token(TokenType::MINUS, "-");
    case '*':
      return Token(TokenType::MULTIPLICATION, "*");
    case '/':
      return Token(TokenType::DIVISION, "/");
    case '(':
      return Token(TokenType::LEFT_PARENTHESIS, "(");
    case ')':
      return Token(TokenType::RIGHT_PARENTHESIS, ")");
    default:
      throw std::runtime_error("Unexpected character");
  }
}

}  // namespace math_parser::lexer
