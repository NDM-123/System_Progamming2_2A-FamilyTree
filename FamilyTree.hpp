#ifndef FAMILYTREE_H_
#define FAMILYTREE_H_
#include <string>

namespace family {
	bool addFather(std::string a,std::string b);
	bool addMother(std::string a,std::string b);
	void display();
	std::string relation(std::string a);
	std::string find(std::string a);
	bool remove(std::string a);
}
	
#endif
