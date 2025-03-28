/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:17:42 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/03/28 14:16:13 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data original = {42, "Hello World!", 42};
	uintptr_t raw = Serializer::serialize(&original);
	Data *ptr = Serializer::deserialize(raw);

	std::cout << "Original address: " << &original << std::endl;
	std::cout << "Serialized address: " << raw << std::endl;
	std::cout << "Deserialized address: " << ptr << std::endl;
	std::cout << "Original index: " << original.index << std::endl;
	std::cout << "Deserialized index: " << ptr->index << std::endl;
	std::cout << "Original message: " << original.message << std::endl;
	std::cout << "Deserialized message: " << ptr->message << std::endl;
	std::cout << "Original other_value: " << original.other_value << std::endl;
	std::cout << "Deserialized other_value: " << ptr->other_value << std::endl;

	return (0);
}