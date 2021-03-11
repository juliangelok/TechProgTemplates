//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "cpr/cpr.h"
#include "WeatherMock.h"


cpr::Response WeatherMockGood::Get(const std::string& city) {
  cpr::Response r;
  float h = (float)city[0];

  std::stringstream ss;
  ss << "{\"list\":[{\"main\":{\"temp\": " << h << "}}]}";

  r.status_code = 200;
  r.text = ss.str();
  std::cerr << r.text << std::endl;
  return r;
}


cpr::Response WeatherMockBad::Get(const std::string& city) {
  cpr::Response r;
  r.status_code = 400;
  r.text = "{\"list\":[{\"main\":{\"temp\": 12.3}}]}";
  return r;
}
