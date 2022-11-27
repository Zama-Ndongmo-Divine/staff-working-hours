#include <iostream>
#include <sqlite3.h>

int main(int argc, char** argv)
{
	sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open("/home/wakanda/Desktop/Intro To MAD/management/database/ staff_management.db", &DB);
   
	if (exit) {
		std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
		return (-1);
	}
	else
		std::cout << "Opened Database Successfully!" << std::endl;
	sqlite3_close(DB);
	return (0);
}
