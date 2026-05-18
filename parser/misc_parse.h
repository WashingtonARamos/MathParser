#ifndef MATH_PARSER_MISC_PARSE_H
#define MATH_PARSER_MISC_PARSE_H
#include <memory>

#include "../interpreter/ast_node.h"
#include "../lexer/token.h"
#include "parser.h"

namespace math_parser::parser {

std::unique_ptr<interpreter::AstNode> GroupingNudParseFn(Parser &parser,
                                                      lexer::Token &token);

}

#endif  // MATH_PARSER_MISC_PARSE_H
