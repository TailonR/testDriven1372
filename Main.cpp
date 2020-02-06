#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <sstream>

using std::string;

int strings(string dummy) { 
	if (dummy == "")
	{
		return 0;
	}
	else
	{
		std::istringstream num(dummy);
		string x;
		int total = 0;
		if (num.str().length() == 1)
		{
			int one;
			num >> one;
			return one;
		}
		else
		{
			for (int i = 0; i < num.str().length(); i++)
			{
				if (num.str()[i] != ',')
				{
					x += num.str()[i];
				}
				else
				{
					dummy = x;
					x = "";
					continue;
				}
			}
			std::istringstream num1(x);
			int one;
			num1 >> one;
			total += one;
		}
		return total;
	}
};

TEST_CASE("An empty string returns zero") {
	CHECK(strings("") == 0);
}

TEST_CASE("A single number returns the value") {
	CHECK(strings("1") == 1);
	CHECK(strings("2") == 2);
	CHECK(strings("10") == 10);
	CHECK(strings("100") == 100);
	CHECK(strings("1000") == 1000);
	CHECK(strings("0,1") == 1);
	CHECK(strings("1,2") == 3);
	CHECK(strings("10,0") == 10);
	CHECK(strings("10,1") == 11);
}
