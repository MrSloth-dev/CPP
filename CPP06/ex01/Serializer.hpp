/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:34:27 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/17 17:34:06 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdint.h>
#include <string>
#include <iostream>
#include <sys/types.h>
#include "Data.hpp"
class Serializer {
	private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& copy);
	Serializer& operator=(const Serializer& other);
	public:
	static uintptr_t serialize(Data *ptr);
	static Data* deserialize(uintptr_t raw);

};
