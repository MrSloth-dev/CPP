/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:22:00 by joao-pol          #+#    #+#             */
/*   Updated: 2025/03/07 12:31:28 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T, template <typename, typename> class Container>
class sequence {
public:
  typedef Container<T, std::allocator<T> > ContainerType;
  sequence() {};
  void push_back(const T& element) { data.push_back(element); }
  void pop_back() {
    if (!data.empty())
      data.pop_back();
  }
  void printElements() const {
    for (typename ContainerType::const_iterator it = data.begin();
         it != data.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }

private:
  ContainerType data;
};

template <typename T, template <typename, typename> class OuterContainer, 
template <typename, typename> class InnerContainer>
pairUp(const)

bool IsNumber(const std::string& str) {
    if (str.empty())
        return false;

    size_t start = 0;
    if (str.length() > 1 && (str[0] == '-' || str[0] == '+'))
        start = 1;

    for (size_t i = start; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

template <typename T, template <typename, typename> class Container>
bool parseInput(sequence<T, Container >& sequence, char *argv[]) {
	++argv;
	while (argv && *argv) {
		if (!IsNumber(*argv))
			return false;
		else {
			int value = std::atoi(*argv);
			if (value < 0)
				return false;
			sequence.push_back(value);
		}
		argv++;
	}
	return true;
}

int main(int argc, char*argv[]) {
	try {
		if (argc < 2) {
			std::cerr <<"Error: Usage : ./PmergeMe <sequence> <of> <positive> <numbers> " << std::endl;
			return 1;
		}
		sequence<int, std::vector> vector;
		sequence<int, std::deque> deque;
		if (!parseInput(vector, argv) || !parseInput(deque, argv)) {
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
