/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:44:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/18 11:47:04 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <string>
#include <iostream>

template<typename T> 
class Array {

	private:
	unsigned int _size;
	T* _array;

	public:
	Array() :_size(0), _array(0) {};

	Array(unsigned int size) :_size(size) {
		_array = new T[size];
	};

	Array(const Array& copy) : _size(copy._size) {
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = copy._array[i];
	};

	Array& operator=(const Array& copy) {
		if (this != &copy) {
			_size = copy._size;
			delete[] _array;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = copy._array[i];
		}
		return *this;
	};

	~Array() {
		delete[] _array;
	};

	T& operator[](unsigned int index) {
		if (index >= _size)
			throw std::exception();
		return _array[index];
	};
	int size() { return this->_size; }

};

