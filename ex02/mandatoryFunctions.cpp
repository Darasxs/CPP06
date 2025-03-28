/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatoryFunctions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:51:45 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/03/28 16:57:11 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatoryFunctions.hpp"

Base *generate(void)
{
	int i = rand() % 3;
	if(i == 0)
		return new A();
	else if(i == 1)
		return new B();
	else
		return new C();
}

