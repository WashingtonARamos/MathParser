#ifndef MATH_PARSER_NUMBER_NODE_H
#define MATH_PARSER_NUMBER_NODE_H
#include <string>

#include "ast_node.h"

namespace math_parser::interpreter {

struct NumberNode : AstNode {
  NumberNode(const std::string &value) : value(std::stod(value)) {}

  double Evaluate() override { return value; }

  double value;
};

}  // namespace math_parser::interpreter

#endif
