/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:45:41 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/17 14:49:05 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>


class ScalarConverter {
	private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);
	ScalarConverter(const ScalarConverter& copy);
	public:
	static void	convert(const std::string& literal);
};
