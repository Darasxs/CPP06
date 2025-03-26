/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:39:25 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/03/26 18:49:40 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy)
{
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

bool ScalarConverter::handlePseudoLiterals(const std::string &literal)
{
	if (literal == "nanf" || literal == "nan")
	{
		std::cout << "Conversion to char is not possible." << std::endl;
		std::cout << "Conversion to int is not possible." << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (true);
	}
	else if (literal == "+inf" || literal == "inf" || literal == "+inff"
		|| literal == "inff")
	{
		std::cout << "Conversion to char is not possible." << std::endl;
		std::cout << "Conversion to int is not possible." << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return (true);
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "Conversion to char is not possible." << std::endl;
		std::cout << "Conversion to int is not possible." << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (true);
	}
	return (false);
}

static bool	handleIfChar(const std::string &literal)
{
	char	c;		

	if (literal.length() == 1 && std::isprint(literal[0])
		&& !std::isdigit(literal[0]))
	{
		c = literal[0];
		std::cout << "The literal input is a char: '" << c << "'" << std::endl;
		std::cout << "As int: " << static_cast<int>(c) << std::endl;
		std::cout << "As float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "As double: " << static_cast<double>(c) << ".0" << std::endl;
		return (true);
	}
	return (false);
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cout << "The literal input is empty." << std::endl;
		return ;
	}
	if (handleIfChar(literal))
		return ;
	if (handlePseudoLiterals(literal))
		return ;
	try
	{
		if(literal.find('.') != std::string::npos)	
		{
			double myDouble = std::stod(literal);
			std::cout << "The literal is a double: " << myDouble << std::endl;
			std::cout << "as float: " << static_cast<float>(myDouble) << "f" << std::endl;
			if(myDouble > std::numeric_limits<int>::min() && myDouble < std::numeric_limits<int>::max())
			{
				std::cout << "as int: " << static_cast<int>(myDouble) << std::endl;
				if(myDouble > std::numeric_limits<char>::min() && myDouble < std::numeric_limits<char>::max())
					std::cout << "as char: " << static_cast<char>(myDouble) << std::endl;
				else
					std::cout << "Conversion to char is not possible." << std::endl;
			}
			else
			{
				std::cout << "Conversion to int is not possible." << std::endl;
				std::cout << "Conversion to char is not possible." << std::endl;
			}
		}
		else if(literal.find('f') != std::string::npos)
		{
			float myFloat = std::stof(literal);
			std::cout << "The literal is a float: " << myFloat << "f" << std::endl;
			if(myFloat > std::numeric_limits<int>::min() && myFloat < std::numeric_limits<int>::max())
			{
				std::cout << "as int: " << static_cast<int>(myFloat) << std::endl;
				if(myFloat > std::numeric_limits<char>::min() && myFloat < std::numeric_limits<char>::max())
					std::cout << "as char: " << static_cast<char>(myFloat) << std::endl;
				else
					std::cout << "Conversion to char is not possible." << std::endl;
			}
			else
			{
				std::cout << "Conversion to int is not possible." << std::endl;
				std::cout << "Conversion to char is not possible." << std::endl;
			}
			
		}
		else if(literal.find('.')  == std::string::npos && literal.find('f') == std::string::npos)
		{
			int myInt = std::stoi(literal);
			std::cout << "The literal is an int: " << myInt << std::endl;
			if(myInt > std::numeric_limits<char>::min() && myInt < std::numeric_limits<char>::max())
				std::cout << "as char: " << static_cast<char>(myInt) << std::endl;
			else
				std::cout << "Conversion to char is not possible." << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Error. Invalid literal." << std::endl;
	}
}
