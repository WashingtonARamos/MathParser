#ifndef MATH_PARSER_UNARY_MINUS_NODE_H
#define MATH_PARSER_UNARY_MINUS_NODE_H
#include <memory>

#include "ast_node.h"

namespace math_parser::interpreter {

struct UnaryMinus : AstNode {
  UnaryMinus(std::unique_ptr<AstNode> right) : right(std::move(right)) {}

  double Evaluate() override {
    return -right->Evaluate();
  }

  std::unique_ptr<AstNode> right;
};

}

#endif
