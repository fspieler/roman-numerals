#include <string>


std::string operator ""_roman(unsigned long long int);
unsigned int operator ""_roman(const char*, size_t);

std::string to_roman_numeral(unsigned long long int);
unsigned int from_roman_numeral(const char*, size_t);
unsigned int from_roman_numeral(const std::string&);
