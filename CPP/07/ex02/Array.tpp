/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:03:29 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/12 15:35:59 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _elem(NULL), _size(0) {}

template <typename T>
Array<T>::Array(const Array &other) : _elem(NULL), _size(0) {
    _size = other._size;
    _elem = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _elem[i] = other._elem[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
	if (this != &other) {
		delete[] this->_elem;
		_size = other._size;
		_elem = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_elem[i] = other._elem[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](const unsigned int i) {
	if (i >= _size) {
		throw OutOfBoundsException();
	}
	return _elem[i];
}

template <typename T>
Array<T>::~Array() {
	delete [] _elem;
}

template <typename T>
Array<T>::Array(const unsigned int n) {
	_elem = new T[n];
	_size = n;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	return "index is out of bounds";
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}
