/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:39:25 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/03/25 14:52:15 by dpaluszk         ###   ########.fr       */
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
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (true);
	}
	else if (literal == "+inf" || literal == "inf" || literal == "+inff"
		|| literal == "inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return (true);
	}
	else if (literal == "-inf" || literal == "-inff")
	{
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
		
	}
}
