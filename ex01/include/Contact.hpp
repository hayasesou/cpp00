#ifndef CONTACT_HPP
#define  CONTACT_HPP


#include <iostream>
#include <string>

class Contact {
	private	:
		std::string 	first_name;
		std::string 	last_name;
		std::string 	nick_name;
		unsigned int	phone_number;
		std::string		darkest_secret;
	
	public	:
		void	set_contact(std::string f_name, std::string l_name, std::string n_name, unsigned int p_number,  std::string d_secret)
		{
			first_name =  f_name;
			last_name = l_name;
			nick_name = n_name;
			phone_number = p_number;
			darkest_secret = d_secret;
		}
		
		void	print_contact(Contact contact)
		{
			std::cout << contact.first_name << std:: endl;
		}

};

#endif
