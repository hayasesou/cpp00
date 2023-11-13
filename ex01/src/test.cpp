#include "Contact.hpp"
#include <iostream>

int main()
{
	Contact	test;

	test.set_contact("jonathan", "josetar", "jojo", 123456789, "Dio killed my father");
	//test.first_name = "fukushi";
	//std::cout << test.first_name << std::endl;
	//std::cout << test.last_name << std::endl;
	test.print_contact(test);
	return (0);
}

