//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>


TEST_F(LeapTestCase, test1) {
    ASSERT_EQ(false, IsLeap(1));
}

TEST_F(LeapTestCase, test4) {
    ASSERT_EQ(true, IsLeap(4));
}

TEST_F(LeapTestCase, test100) {
    ASSERT_EQ(false, IsLeap(100));
}

TEST_F(LeapTestCase, test400) {
    ASSERT_EQ(true, IsLeap(400));
}

TEST_F(LeapTestCase, test0) {
    ASSERT_THROW(IsLeap(0), std::invalid_argument);
}