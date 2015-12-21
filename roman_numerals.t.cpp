#include "roman_numerals.h"
#include <gtest/gtest.h>

TEST(RomanNumerals,to_rn_with_selected_values)
{
  EXPECT_EQ("I",1_roman);
  EXPECT_EQ("III",3_roman);
  EXPECT_EQ("XIX",19_roman);
  EXPECT_EQ("MCMXC",1990_roman);
  EXPECT_EQ("MMXV",2015_roman);
}

TEST(RN,from_rn_with_selected_values)
{
  EXPECT_EQ(1,"I"_roman);
  EXPECT_EQ(5,"V"_roman);
  EXPECT_EQ(10,"X"_roman);
  EXPECT_EQ(999,"CMXCIX"_roman);
  EXPECT_EQ(1990,"MCMXC"_roman);
}

TEST(RomanNumerals,converting_to_and_from_roman_numerals_for_natural_numbers_under_four_thousand_is_an_identity)
{
  for(unsigned i = 0; i < 4000; i++)
  {
    EXPECT_EQ(i,from_roman_numeral(to_roman_numeral(i)));
  }
}
