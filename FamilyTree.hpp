#pragma once
#include <iostream>
#include <string>
#include <stdbool.h>

	using namespace std;
	namespace family{
class node {

public:
	string name;
	node *father;
	node *mother;
	node (string n);		
};


class Tree{
public:
	
        node* head;
	Tree (string s);
	Tree addFather(std::string a,std::string b);
	Tree addMother(std::string a,std::string b);
	void display();
	std::string relation(std::string a);
	std::string find(std::string a);
	bool remove(std::string a);


};
}
