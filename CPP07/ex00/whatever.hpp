/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:42:33 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/17 23:03:44 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
void swap(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
T min(T x, T y) {
	if (x < y)
		return x;
	else
		return y;
}

template <typename T>
T max(T x, T y) {
	if (x > y)
		return x;
	else
		return y;
}
