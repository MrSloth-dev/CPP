/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:26:05 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/18 15:47:05 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T container,int n) {
	if (std::find(container.begin(), container.end(), n) != container.end())
		return std::find(container.begin(), container.end(), n);
	else
		throw std::exception();
}
