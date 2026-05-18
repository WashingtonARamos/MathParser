#ifndef MATH_PARSER_BINDING_POWER_H
#define MATH_PARSER_BINDING_POWER_H
#include <cstdint>

#include "../lexer/token.h"

namespace math_parser::lexer {
enum class TokenType;
}
namespace math_parser::parser {

struct BindingPower {
  int32_t lbp;
  int32_t rbp;
};

constexpr int32_t GetNudRightBindingPower(lexer::TokenType type) {
  switch (type) {
    case lexer::TokenType::MINUS:
      return 30;
    default:
      return -1;
  }
}

constexpr BindingPower GetLedBindingPower(lexer::TokenType type) {
  switch (type) {
    case lexer::TokenType::MINUS:
    case lexer::TokenType::PLUS:
      return {10, 10};
    case lexer::TokenType::MULTIPLICATION:
    case lexer::TokenType::DIVISION:
      return {20, 20};
    case lexer::TokenType::LEFT_PARENTHESIS:
      return {40, 0};
    default:
      return {-1, -1};
  }
}

}  // namespace math_parser::parser

#endif
