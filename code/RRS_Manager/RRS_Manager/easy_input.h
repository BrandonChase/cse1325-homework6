#ifndef EASY_INPUT_H
#define EASY_INPUT_H 2016

#include <string>

std::string inputString(std::string prompt);
double inputDouble(std::string prompt);
int inputInt(std::string prompt);

int inputIntLessThan(std::string prompt, int upper_bound, std::string reminder);
int inputIntGreaterThan(std::string prompt, int lower_bound, std::string reminder);
int inputIntInRange(std::string prompt, int lower_bound, int upper_bound, std::string reminder);
int inputDoubleLessThan(std::string prompt, double upper_bound, std::string reminder);
int inputDoubleGreaterThan(std::string prompt, double lower_bound, std::string reminder);
int inputDoubleInRange(std::string prompt, double lower_bound, double upper_bound, std::string reminder);

#endif