#include <iostream>
#include <string>

#include "db_proxy/db_proxy.h"


int main()
{
	const std::string FILE_NAME = "data/data.csv";
	
	std::cout << "main - beginning" << std::endl;

	UsersManager users_manager;
	DBProxy db_proxy(FILE_NAME, users_manager);

	// Here's where the user does his magics

	std::cout << "main - end" << std::endl;

	return 0;
}

