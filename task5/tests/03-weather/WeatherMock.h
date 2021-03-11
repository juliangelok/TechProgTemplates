//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include <Weather.h>

class WeatherMockGood : public Weather {
    cpr::Response Get(const std::string& city);
};

class WeatherMockBad : public Weather {
    cpr::Response Get(const std::string& city);
};
