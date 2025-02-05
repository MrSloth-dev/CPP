/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:25:47 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 15:42:19 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Brain {
private:
	static const unsigned int n_idea = 100;
public:
	Brain();
	Brain(std::string idea);
	~Brain();
	Brain& operator=(const Brain &other);

	std::string ideas[n_idea];
};
