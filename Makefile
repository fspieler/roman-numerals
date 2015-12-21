.PHONY: all run-test clean

all: clean run-test 

run-test: roman_numerals_test
	@\time -p ./roman_numerals_test --gtest_color=yes

roman_numerals_test: roman_numerals.cpp roman_numerals.t.cpp
	g++ -O2 -I. -pthread -W -Wall -Wextra -std=c++14 roman_numerals.t.cpp roman_numerals.cpp -lgtest_main -o roman_numerals_test

clean: 
	rm -f *.o roman_numerals_test
