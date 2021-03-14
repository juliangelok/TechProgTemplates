//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"


TEST_F(WeatherTestCase, testGetDifferenceStringGood) {
    cpr::Response ten;
    ten.status_code = 200;
    ten.text = "{\"list\":[{\"main\":{\"temp\": 10.0}}]}";

    cpr::Response twenty;
    twenty.status_code = 200;
    twenty.text = "{\"list\":[{\"main\":{\"temp\": 20.0}}]}";

    
    WeatherMock w;
    w.SetApiKey("");

    EXPECT_CALL(w, Get)
        .Times(2)
        .WillOnce(testing::Return(ten))
        .WillOnce(testing::Return(twenty));

    ASSERT_NO_THROW(w.GetDifferenceString("warsaw", "london"));
    
    EXPECT_CALL(w, Get)
        .Times(2)
        .WillOnce(testing::Return(twenty))
        .WillOnce(testing::Return(ten));

    ASSERT_NO_THROW(w.GetDifferenceString("london", "warsaw"));
}

TEST_F(WeatherTestCase, testGetGetDifferenceStringbad) {
    cpr::Response bad;
    bad.status_code = 400;
    
    WeatherMock w;
    EXPECT_CALL(w, Get)
        .Times(1)
        .WillOnce(testing::Return(bad));

    ASSERT_THROW(w.GetDifferenceString("asdf", "fdsa"), std::invalid_argument);
}
