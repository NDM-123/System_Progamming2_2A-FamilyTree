#pragma once
#include <iostream>
#include <string>
#include <stdbool.h>
using namespace std;
	namespace family{

class Tree{
public:
	Tree(string s){
	this->name=s;
	this->left=this->right=nullptr;
	this->head=nullptr;
}
	string name;
	Tree* father;
	Tree* mother;
        Tree* head;
	Tree& addFather(std::string a,std::string b);
	Tree& addMother(std::string a,std::string b);
	void display();
	std::string relation(std::string a);
	std::string find(std::string a);
	bool remove(std::string a);
 

};
}
