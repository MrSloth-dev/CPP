/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:20:58 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/17 23:57:01 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <cctype>
#include <iostream>

template <typename T, typename F> void	iter(T array, unsigned int size, F fun) {
	unsigned int i = 0;
	while (i < size) {
		fun(array[i++]);
	}
}
