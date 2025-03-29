/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatoryFunctions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:51:45 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/03/29 14:55:16 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatoryFunctions.hpp"

Base	*generate(void)
{
	int	i;

	i = rand() % 3;
	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class A object." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B object." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C object." << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base &p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Class A object." << std::endl;
		return;
	} catch (std::bad_cast &) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Class B object." << std::endl;
		return;
	} catch (std::bad_cast &) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Class C object." << std::endl;
		return;
	} catch (std::bad_cast &) {}

	std::cout << "Unknown" << std::endl;
}
