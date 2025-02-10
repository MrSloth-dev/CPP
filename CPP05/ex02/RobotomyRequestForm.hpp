/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:07:23 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/10 16:14:52 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <random>
#include <cstdlib>
class RobotomyRequestForm: public AForm {
	private:
		RobotomyRequestForm();
		void PrinTree(std::ostream& os);
	protected:
		int const _minGradeSign;
		int const _minGradeExec;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
};
