#include "FamilyTree.hpp"
#include <iostream>
#include <string>
#include <stdbool.h>

using namespace std;
using namespace family;



node ::node(string n) {		// Constructor with parameters
this->name =n;
this->father=this->mother=nullptr;
}
Tree ::Tree(string s){
	this->head=new node(s);
	
}

	Tree Tree::addMother(std::string a,std::string b)
    {
//Tree n;
return *this;
}



	Tree Tree::addFather(std::string a,std::string b){
//Tree n;
return *this;
}

	void Tree::display(){
}


	std::string Tree::relation(std::string a){
std::string s;
return s;
}


	std::string Tree::find(std::string a){
std::string s;
return s;
}


	bool Tree::remove(std::string a){
bool f;
return f;
}

