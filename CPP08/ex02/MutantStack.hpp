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

template <typename T>
class MutantStack : public std::stack<T> {

	public:
	MutantStack();
	MutantStack(const MutantStack<T>& copy);
	~MutantStack();
	MutantStack<T>& operator=(const MutantStack<T>& copy);
};

