#include "ex01.hpp"

int main()
{
	std::cout<< "This is PhoneBook. Please input one of the three bcommands below."<< std::endl;
	std::cout << " ADD    : save a new contact" <<std :: endl;
	std::cout << " SEARCH : display a specific contacts" << std::endl;
	std::cout << " EXIT   : The program quits and the contacts are lost forever!" << std::endl;

	Contact	test;

	test.set_contact("jonathan", "josetar", "jojo", 123456789, "Dio killed my father");
	//test.first_name = "fukushi";
	//std::cout << test.first_name << std::endl;
	//std::cout << test.last_name << std::endl;
	test.print_contact(test);
	return (0);
}

