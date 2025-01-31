/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:44:46 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/30 17:01:03 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP_
#define FRAGTRAP_HPP_
#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:

	FragTrap(void);


	FragTrap(const FragTrap& other);
	~FragTrap();
	FragTrap& operator=(const FragTrap& other);
	void	hightFivesGuys(void);
};
#endif
