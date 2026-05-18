cmake_minimum_required(VERSION 4.2)
project(math_parser)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(math_parser main.cpp
        interpreter/ast_node.h
        lexer/lexer.h
        lexer/token.h
        lexer/lexer.cpp
        interpreter/sum_node.h
        interpreter/number_node.h
        interpreter/unary_minus_node.h
        parser/arithmetic_parse.h
        interpreter/subtraction_node.h
        parser/arithmetic_parse.cpp
        parser/parser.h
        parser/number_parse.h
        parser/number_parse.cpp
        parser/parser.cpp
        parser/misc_parse.h
        parser/binding_power.h
        parser/misc_parse.cpp
        interpreter/grouping_node.h
        interpreter/multiplication_node.h
        interpreter/division_node.h)

enable_testing()

add_executable(math_parser_test
        test/parser_test.cpp
        lexer/lexer.cpp
        parser/arithmetic_parse.cpp
        parser/number_parse.cpp
        parser/parser.cpp
        parser/misc_parse.cpp
)
target_link_libraries(math_parser_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(math_parser_test)