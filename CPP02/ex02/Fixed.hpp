/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:48:06 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/28 15:55:42 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FIXED_HPP
#define FIXED_HPP
#pragma once
#include <iostream>
#include <cmath>

class Fixed {
private:
	int _fixedPoint;
	static const int _frac_bits;
public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	~Fixed();
	Fixed(const Fixed &other);

	Fixed& operator=(const Fixed &other);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int	toInt(void) const;
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif
