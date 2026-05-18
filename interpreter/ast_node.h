#ifndef MATH_PARSER_AST_NODE_H
#define MATH_PARSER_AST_NODE_H

namespace math_parser::interpreter {

struct AstNode {
  virtual ~AstNode() = default;
  virtual double Evaluate() = 0;
};

}  // namespace math_parser::interpreter

#endif
