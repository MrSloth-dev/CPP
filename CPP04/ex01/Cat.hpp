/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:38:16 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 15:59:43 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
	Brain *brain;
	std::string _name;
	protected:
	public:
	Cat();
	Cat(const Cat&);
	~Cat();
	Cat& operator=(const Cat& other);

	std::string	getType() const;
	void		setType(std::string type);
	void	makeSound() const;
	void		setIdea(unsigned int index, std::string idea);
	std::string	getIdea(unsigned int index);
};
