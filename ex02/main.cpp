/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:31:20 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/03/29 15:03:44 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatoryFunctions.hpp"
#include "classA.hpp"
#include "classB.hpp"
#include "classC.hpp"

int	main(void)
{
	srand(time(NULL));
	Base *ptr1 = generate();
	Base *ptr2 = generate();
	Base *ptr3 = generate();

	std::cout << "Identifying by pointer:" << std::endl;

	identify(ptr1);
	identify(ptr2);
	identify(ptr3);
	
	std::cout << "Identifying by reference:" << std::endl;

	identify(*ptr1);
	identify(*ptr2);
	identify(*ptr3);

	delete ptr1;
	delete ptr2;
	delete ptr3;

	return (0);
}