#ifndef MATH_PARSER_GROUPING_NODE_H
#define MATH_PARSER_GROUPING_NODE_H
#include <memory>

#include "ast_node.h"

namespace math_parser::interpreter {

struct GroupingNode : AstNode {
  GroupingNode(std::unique_ptr<AstNode> node) : node(std::move(node)) {}

  double Evaluate() override { return node->Evaluate(); }

  std::unique_ptr<AstNode> node;
};

}  // namespace math_parser::interpreter

#endif  // MATH_PARSER_GROUPING_NODE_H
