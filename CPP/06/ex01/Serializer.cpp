/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:11:27 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/10 16:22:04 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer &Serializer::operator=(const Serializer &other) {
	(void)other;
	return *this;
}
Serializer::Serializer(const Serializer &other) {
	(void)other;
}

uintptr_t Serializer::serialize(Data* ptr) {
	if (ptr == NULL)
		throw NullPointerException();
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

const char *Serializer::NullPointerException::what() const throw() {
	return "null pointer detected";
}
