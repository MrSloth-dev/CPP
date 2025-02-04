/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:38:16 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 14:03:28 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : public Animal {
	protected:
	std::string _name;
	public:
	Cat();
	Cat(std::string _name);
	~Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);

	std::string	getType() const;
	void		setType(std::string type);
	void	makeSound() const;
};
