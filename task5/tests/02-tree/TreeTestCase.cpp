//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"

TEST_F(TreeTestCase, testDirsOnly) {
    ASSERT_NO_THROW(GetTree("..", false));
}

TEST_F(TreeTestCase, testDirs) {
    ASSERT_NO_THROW(GetTree("..", true));
}

TEST_F(TreeTestCase, testNotFound) {
    ASSERT_THROW(GetTree("kek", false), std::invalid_argument);
}

TEST_F(TreeTestCase, testNotDir) {
    ASSERT_THROW(GetTree("/etc/passwd", false), std::invalid_argument);
}

TEST_F(TreeTestCase, TestEQ) {
    auto a = GetTree(".", true);
    auto b = GetTree(".", true);
    ASSERT_EQ(true, a == b);
}
