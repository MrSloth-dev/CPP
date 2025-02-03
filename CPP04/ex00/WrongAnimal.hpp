/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:08:21 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 14:03:49 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class WrongAnimal {
	private:
	protected:
	std::string _type;
	public:
	WrongAnimal(void);
	WrongAnimal(std::string _name);
	virtual ~WrongAnimal();

	WrongAnimal&		operator=(const WrongAnimal& other);
	std::string	getType() const;
	void		setType(std::string type);
	virtual void	makeSound() const;
};
