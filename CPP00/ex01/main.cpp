#include "phonebook.hpp"


int	main()
{
	Phonebook phonebook;
	Contact jao;

	jao.set_first_name("Joao");
	jao.set_last_name("Barbosa");
	phonebook.add(jao);
	phonebook.print(jao);
}
