#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
  private:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const &copy);
	ScalarConverter &operator=(ScalarConverter const &copy);
	~ScalarConverter(void);

  public:
	static void convert(const std::string &literal);
};

#endif