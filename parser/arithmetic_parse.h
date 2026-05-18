#ifndef MATH_PARSER_ARITHMETIC_PARSE_H
#define MATH_PARSER_ARITHMETIC_PARSE_H
#include <memory>

#include "../interpreter/ast_node.h"
#include "../lexer/token.h"
#include "parser.h"

namespace math_parser::parser {
std::unique_ptr<interpreter::AstNode> MinusLedParseFn(
    Parser &parser, lexer::Token &token,
    std::unique_ptr<interpreter::AstNode> left);
std::unique_ptr<interpreter::AstNode> PlusLedParseFn(
    Parser &parser, lexer::Token &token,
    std::unique_ptr<interpreter::AstNode> left);
std::unique_ptr<interpreter::AstNode> MultiplicationLedParseFn(
    Parser &parser, lexer::Token &token,
    std::unique_ptr<interpreter::AstNode> left);
std::unique_ptr<interpreter::AstNode> DivisionLedParseFn(
    Parser &parser, lexer::Token &token,
    std::unique_ptr<interpreter::AstNode> left);

std::unique_ptr<interpreter::AstNode> MinusNudParseFn(Parser &parser,
                                                   lexer::Token &token);
}  // namespace math_parser::parser

#endif
