
#include "Animal.hpp"


class Dog : public Animal {
	private:
	protected:
	std::string _name;
	public:
	Dog();
	Dog(std::string _name);
	~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);

	std::string	getType() const;
	void		setType(std::string type);
	void	makeSound() const;
};
