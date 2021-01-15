#include <string>
#include "gtest/gtest.h"
#include "rpn.h"

using namespace std;

TEST(libRPN, SimpleTest) {
    string line = "2+3^4+(48*4)";
    std::string rpn = rpn::convert(line);
    double res = rpn::calculate(rpn);
    ASSERT_EQ(res, 275.0);
}

TEST(libRPN, TestDivusion) {
    std::string line = "32+450/45";
    std::string rpn = rpn::convert(line);
    ASSERT_EQ(rpn::calculate(rpn), 42);
}

TEST(libRPN, TestMultiply) {
    string line = "1235*212*(21-12)";
    std::string rpn = rpn::convert(line);
    double res = rpn::calculate(rpn);
    ASSERT_EQ(res, 2356380);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
