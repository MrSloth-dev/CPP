/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:38:16 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 14:01:19 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	protected:
	std::string _name;
	public:
	WrongCat();
	WrongCat(std::string _name);
	WrongCat(const WrongCat& other);
	~WrongCat();
	WrongCat& operator=(const WrongCat& other);
	std::string	getType() const;
	void		setType(std::string type);
	void	makeSound() const;
};
