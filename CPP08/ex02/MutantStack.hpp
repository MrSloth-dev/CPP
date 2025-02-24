/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:47:09 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/19 15:54:05 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <deque>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	iterator begin(){ return this->c.begin(); }
	iterator end(){ return this->c.end(); }
	reverse_iterator rbegin(){ return this->c.rbegin(); }
	reverse_iterator rend(){ return this->c.rend(); }
	const_iterator cbegin() const{ return this->c.begin(); }
	const_iterator cend() const{ return this->c.end(); }
	const_reverse_iterator crbegin() const{ return this->c.rbegin(); }
	const_reverse_iterator crend() const{ return this->c.rend(); }

};

