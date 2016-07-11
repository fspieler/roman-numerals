#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <iostream>

namespace _roman_numeral_impl
{
  using namespace std;
  const vector<pair<unsigned, std::string> > to_map =
  {
    {1,"I"},
    {4,"IV"},
    {5,"V"},
    {9,"IX"},
    {10,"X"},
    {40,"XL"},
    {50,"L"},
    {90,"XC"},
    {100,"C"},
    {400,"CD"},
    {500,"D"},
    {900,"CM"},
    {1000,"M"}
  };


  const map<char, unsigned> from_map =
  {
    {'I',1},
    {'V',5},
    {'X',10},
    {'L',50},
    {'C',100},
    {'D',500},
    {'M',1000}
  };

}

std::string to_roman_numeral (unsigned long long int i)
{
  
  std::string ret = "";
  for(auto it = _roman_numeral_impl::to_map.crbegin(); it != _roman_numeral_impl::to_map.crend() && i>0; it++)
  {
    while( i >= std::get<0>(*it))
    {
      ret += std::get<1>(*it);
      i -= std::get<0>(*it);
    }
  }

  return ret;
}

unsigned int from_roman_numeral(const char* s, std::size_t sz)
{
  unsigned int ret = 0;
  unsigned last_val = 1001;
  for(unsigned i = 0; i < sz; i++)
  {
    unsigned val = _roman_numeral_impl::from_map.at(s[i]);
    if(last_val < val)
    {
      ret += val - 2 * last_val;
    }
    else
    {
      ret += val;
    }
    last_val = val;
  }
  return ret;
}

unsigned int from_roman_numeral(const std::string& s)
{
  return from_roman_numeral(s.c_str(), s.size());
}

std::string operator ""_roman (unsigned long long int i)
{
  return to_roman_numeral(i);
}

unsigned int operator ""_roman (const char* s, std::size_t sz)
{
  return from_roman_numeral(s,sz);
}
