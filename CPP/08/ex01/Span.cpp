/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:44:46 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/18 17:30:07 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}
Span::Span(const Span &s) {
	*this = s;
}
Span &Span::operator=(const Span &s) {
	if (this != &s) {
		_N = s._N;
		_vector = s._vector;
	}
	return *this;
}
Span::~Span() {}

Span::Span(const unsigned int N) : _N(N) {}

void Span::addNumber(int n) {
	if (_vector.size() < _N) {
		_vector.push_back(n);
	}
	else
		throw std::runtime_error("Caught exception: span object full");
}

unsigned int Span::shortestSpan() const {
	if (_vector.size() < 2)
		throw std::runtime_error("Caught exception: one element or less in vector");

	std::vector<int> cpy = _vector;
	std::sort(cpy.begin(), cpy.end());

	unsigned int shortest = UINT_MAX;

	for (size_t i = 0; i < cpy.size() - 1; i++) {
		unsigned int diff = cpy[i + 1] - cpy[i];
		if (diff < shortest) {
			shortest = diff;
		}
	}

	return shortest;
}
unsigned int Span::longestSpan() const {
	if (_vector.size() < 2)
		throw std::runtime_error("Caught exception: one element or less in vector");

	int min = *std::min_element(_vector.begin(), _vector.end());
	int max = *std::max_element(_vector.begin(), _vector.end());

	return max - min;
}

void Span::addMore(const unsigned int i) {
	try {
		for (unsigned int j = 0; j < i; j++) {

			std::ifstream urandom("/dev/urandom", std::ios::binary);
            if (!urandom) {
                throw std::runtime_error("Unable to open /dev/urandom");
            }

            unsigned int seed;
            urandom.read(reinterpret_cast<char*>(&seed), sizeof(seed));
            if (!urandom) {
                throw std::runtime_error("Failed to read from /dev/urandom");
            }
            
			srand(seed);

            urandom.close();
			int random = rand() % INT_MAX;
			addNumber(random);
		}
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
