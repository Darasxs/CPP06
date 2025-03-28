/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:17:44 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/03/27 16:25:01 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &copy) 
{
	*this = copy;
}

Serializer &Serializer::operator=(const Serializer &copy) 
{
	(void)copy;
	return *this;
}

Serializer::~Serializer(void) {}

