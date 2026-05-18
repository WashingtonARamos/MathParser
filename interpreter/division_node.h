#ifndef MATH_PARSER_DIVISION_NODE_H
#define MATH_PARSER_DIVISION_NODE_H
#include <memory>

#include "ast_node.h"

namespace math_parser::interpreter {
struct DivisionNode : AstNode {
  DivisionNode(std::unique_ptr<AstNode> left, std::unique_ptr<AstNode> right)
      : left(std::move(left)), right(std::move(right)) {}

  // Explodes in production with a big ball of fire if right evaluates to 0 :)
  double Evaluate() override { return left->Evaluate() / right->Evaluate(); }

  std::unique_ptr<AstNode> left;
  std::unique_ptr<AstNode> right;
};
}  // namespace math_parser::interpreter

#endif
