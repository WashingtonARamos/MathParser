#include "../parser/parser.h"

#include <gtest/gtest.h>

#include <string>

#include "../lexer/lexer.h"

using namespace math_parser::lexer;
using namespace math_parser::parser;

struct ParserTestCase {
  std::string_view expression;
  int expected_value;
};

class ParserParamTest : public ::testing::TestWithParam<ParserTestCase> {};

TEST_P(ParserParamTest, EvaluatesCorrectly) {
  const ParserTestCase &test_case = GetParam();

  std::string_view expr = test_case.expression;
  Lexer lexer{expr};
  Parser parser{lexer};
  auto ast = parser.ParseExpression(0);

  EXPECT_EQ(ast->Evaluate(), test_case.expected_value);
}

INSTANTIATE_TEST_SUITE_P(
    MathExpressions, ParserParamTest,
    ::testing::Values(
        // 1. Basic Arithmetic Operations
        ParserTestCase{"5 + 3 * 2", 11},
        ParserTestCase{"10 - 4 / 2", 8},
        ParserTestCase{"2 * 3 * 4", 24},
        ParserTestCase{"20 / 2 / 2", 5},

        // 2. Parentheses
        ParserTestCase{"(5 + 3) * 2", 16},
        ParserTestCase{"2 * (10 - 4) / 3", 4},
        ParserTestCase{"((1 + 2) * 3) + 1", 10},

        // 3. Negative Numbers and Unary Operators
        ParserTestCase{"-5 + 10", 5}, ParserTestCase{"5 + -3", 2},
        ParserTestCase{"-(5 + 5)", -10},

        // 4. Multi-digit Numbers & Spacing
        ParserTestCase{"123", 123}, ParserTestCase{"  45  +  55  ", 100},
        ParserTestCase{"1000 - 1", 999},

        // 5. Complex, Mixed Expressions
        ParserTestCase{"3 + 4 * 2 / ( 1 - 5 )", 1},
        ParserTestCase{"10 + 2 * 3 - 4 / 2", 14}));