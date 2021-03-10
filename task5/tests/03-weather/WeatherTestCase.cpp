//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

const std::string kApiKey = "...";

TEST_F(WeatherTestCase, testGetDifferenceStringGood) {
    Weather w;
    w.SetApiKey(kApiKey);

    ASSERT_NO_THROW(w.GetDifferenceString("warsaw", "london"));
}

TEST_F(WeatherTestCase, testGetGetDifferenceStringbad) {
    Weather w;
    w.SetApiKey(kApiKey);
    ASSERT_THROW(w.GetDifferenceString("asdf", "fdsa"), std::invalid_argument);
}
