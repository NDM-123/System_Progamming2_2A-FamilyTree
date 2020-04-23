#pragma once
#include <iostream>
#include <string>
#include <stdbool.h>
#include <vector>

	using namespace std;
	namespace family{
class node {

public:
	string name;
	 string Gender; 
	node *father;
	node *mother;
	node (string n);
	~node();		
};


class Tree{
public:
	
        node* head;
	Tree (string s);
	 ~Tree();
	Tree addFather(std::string a,std::string b);
	Tree addMother(std::string a,std::string b);
	void display();
	std::string relation(std::string a);
	std::string find(std::string a);
	bool remove(std::string a);
	bool searchF(node* root,std::string a,std::string b);
	bool searchM(node* root,std::string a,std::string b);
	void print2DUtil(node *root,int space);
	bool erase(node* root,std::string a);
	void deleteBranch(node* root);
	bool printPath(node* root,std::string a,vector<node*> &path);
int countFreq(string &pat, string &txt) ;
void find(node *root, int level, int &maxLevel, string &res,string g) ;
bool ifNodeExists( node* Node, string key,node* &dest) ;
void deleteTree(node* node)  ;
int isSubstring(string s1, string s2) ;
};
}
