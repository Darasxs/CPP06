/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:39:25 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/03/27 13:25:22 by dpaluszk         ###   ########.fr       */
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

static bool	handlePseudoLiterals(const std::string &literal)
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

static void	printIntChar(double value)
{
	if (value > std::numeric_limits<int>::min()
		&& value < std::numeric_limits<int>::max())
	{
		std::cout << "as int: " << static_cast<int>(value) << std::endl;
		if (value > 31 && value < 127)
			std::cout << "as char: " << static_cast<char>(value) << std::endl;
		else
			std::cout << "as char: non displayable." << std::endl;
	}
	else
	{
		std::cout << "Conversion to int is not possible." << std::endl;
		std::cout << "as char: non displayable." << std::endl;
	}
}

static bool	isValidLiteral(const std::string &literal)
{
	int	dotCounter;
	int	fCounter;
	int invalidCounter;

	dotCounter = 0;
	fCounter = 0;
	invalidCounter = 0;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
			continue ;
		if (literal[i] == '.')
			dotCounter++;
		if (literal[i] == 'f')
			fCounter++;
		if (literal[i] != '.' && literal[i] != 'f' && !std::isdigit(literal[i]))
			invalidCounter++;
	}
	if (dotCounter > 1 || fCounter > 1 || invalidCounter > 0)
		return (false);
	return (true);
}

void ScalarConverter::convert(const std::string &literal)
{
	double	myDouble;
	float	myFloat;
	int		myInt;

	if (literal.empty())
	{
		std::cout << "The literal input is empty." << std::endl;
		return ;
	}
	if (handleIfChar(literal))
		return ;
	if(!isValidLiteral(literal))
	{
		std::cout << "Error. Invalid literal." << std::endl;
		return ;
	}
	if (handlePseudoLiterals(literal))
		return ;
	try
	{
		if (literal.find('f') != std::string::npos)
		{
			myFloat = std::stof(literal);
			std::cout << "The literal is a float: " << myFloat << ".0f" << std::endl;
			std::cout << "as double: " << static_cast<double>(myFloat) << std::endl;
			printIntChar(myFloat);
		}
		else if (literal.find('.') != std::string::npos)
		{
			myDouble = std::stod(literal);
			std::cout << "The literal is a double: " << myDouble << std::endl;
			std::cout << "as float: " << static_cast<float>(myDouble) << ".0f" << std::endl;
			printIntChar(myDouble);
		}
		else if (literal.find('.') == std::string::npos
			&& literal.find('f') == std::string::npos)
		{
			myInt = std::stoi(literal);
			std::cout << "The literal is an int: " << myInt << std::endl;
			std::cout << "as float: " << static_cast<float>(myInt) << ".0f" << std::endl;
			std::cout << "as double: " << static_cast<double>(myInt) << std::endl;
			printIntChar(myInt);
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Error. Invalid literal." << std::endl;
	}
}
