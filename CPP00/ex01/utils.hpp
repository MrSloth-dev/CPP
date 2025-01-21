/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:21:13 by joao-pol          #+#    #+#             */
/*   Updated: 2024/12/12 17:22:23 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP_
#define UTILS_HPP_

# include <iostream>
# include <csignal>
# include <sstream>

void	HandleSignal(void);
int		Stoi(std::string & s);
bool	IsNumber(std::string str);
void	Display(void);
#endif 
