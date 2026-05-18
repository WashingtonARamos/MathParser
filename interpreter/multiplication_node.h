#ifndef MATH_PARSER_MULTIPLICATION_NODE_H
#define MATH_PARSER_MULTIPLICATION_NODE_H
#include <memory>

#include "ast_node.h"
namespace math_parser::interpreter {

struct MultiplicationNode : AstNode {
  MultiplicationNode(std::unique_ptr<AstNode> left, std::unique_ptr<AstNode> right)
      : left(std::move(left)), right(std::move(right)) {}

  double Evaluate() override { return left->Evaluate() * right->Evaluate(); }

  std::unique_ptr<AstNode> left;
  std::unique_ptr<AstNode> right;
};

}  // namespace math_parser::interpreter
#endif
