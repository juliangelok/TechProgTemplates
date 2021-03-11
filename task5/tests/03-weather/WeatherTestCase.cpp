//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"


TEST_F(WeatherTestCase, testGetDifferenceStringGood) {
    WeatherMockGood w;
    w.SetApiKey("");

    ASSERT_NO_THROW(w.GetDifferenceString("warsaw", "london"));
    ASSERT_NO_THROW(w.GetDifferenceString("london", "warsaw"));
}

TEST_F(WeatherTestCase, testGetGetDifferenceStringbad) {
    WeatherMockBad w;
    ASSERT_THROW(w.GetDifferenceString("asdf", "fdsa"), std::invalid_argument);
}
