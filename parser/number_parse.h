#ifndef MATH_PARSER_NUMBER_PARSE_H
#define MATH_PARSER_NUMBER_PARSE_H
#include <memory>

#include "../interpreter/ast_node.h"
#include "../lexer/token.h"
#include "parser.h"

namespace math_parser::parser {

std::unique_ptr<interpreter::AstNode> NumberNudParseFn(Parser &parser,
                                                   lexer::Token &token);

}

#endif
