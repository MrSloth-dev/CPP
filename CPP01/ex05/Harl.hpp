/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:53:24 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/23 16:34:07 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#pragma once
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Harl {
	private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	public:
	void	complain(std::string level);
};
#endif
