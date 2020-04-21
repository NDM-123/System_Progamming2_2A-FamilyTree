#include "FamilyTree.hpp"
#include <iostream>
#include <string>
#include <stdbool.h>
#include <memory>
#include <algorithm>
#include <iterator>
#include <vector>
#include <stdio.h>
#include <string.h>

#include<bits/stdc++.h>  

using namespace std;
using namespace family;
#define COUNT 10





node ::node(string n)
{ // Constructor with parameters
	this->name = n;
	this->father = this->mother = nullptr;
}
node::~node(){
	 delete this->father;
	 delete this->mother;


}
Tree ::Tree(string s)
{
	this->head = new node(s);
}
Tree::~Tree(){
	//deleteBranch(head);
	//free(head);
//	delete head;
}	
Tree Tree::addMother(std::string a, std::string b)
{
 
	if (this->head == nullptr)
	{
		return *this;
	}
	bool flag = searchM(this->head, a,b);
	

	return *this;
}

Tree Tree::addFather(std::string a, std::string b)
{
	if (this->head == nullptr)
	{
		return *this;
	}
	bool flag = searchF(this->head, a,b);

	return *this;
}

void Tree::display()
{
	print2DUtil(this->head, 0);
}

std::string Tree::relation(std::string a)
{
	string me="me";
	string f="father";
	string m="mother";
	string gf="grandfather";
	string gm = "grandmother";
	string gr = "great-";

	if(this->head->name==a)return me;
	if(this->head->father!=NULL&&this->head->father->name==a)return f;
	if(this->head->mother!=NULL&&this->head->mother->name==a)return m;
	if(this->head->father->father!=NULL&&this->head->father->father->name==a)return gf;
	if(this->head->father->mother!=NULL&&this->head->father->mother->name==a)return gm;
	if(this->head->mother->father!=NULL&&this->head->mother->father->name==a)return gf;
	if(this->head->mother->mother!=NULL&&this->head->mother->mother->name==a)return gm;
		cout<<this->head->name+"as"<<endl;
	 vector<node*> path;
	Tree::printPath(this->head,a,path);
	std::reverse(path.begin(), path.end());	//reverse vector
	string output="";
	int vec_size=path.size();

cout<<vec_size<<endl;
	  for (int i=3; i < vec_size; i++){ 

    if(i==(vec_size-1) ){
	output+=gr;
		if(path.at(vec_size-1)->Gender=="Female"){

return output+=gm;
}
		if(path.at(vec_size-1)->Gender=="Male"){

return output+=gf;}
	}

	output+=gr;
  }

		return output;
}


bool Tree::printPath(node* root,std::string a,vector<node*> &path){

		if(root==nullptr){ 
		//cout<<"1"<<endl;
		return false;}
		if(root->name==a){
		cout<<root->name<<endl;
			path.push_back(root);
			return true ;
		}
				//cout<<"3"<<endl;
				cout<<root->name<<endl;
		if(printPath(root->father,a,path)||printPath(root->mother,a,path)){
		path.push_back(root);
		return true;
		}
		return false;

	}




std::string Tree::find(std::string a)
{
	string me="me";
	string f="father";
	string m="mother";
	string gf="grandfather";
	string gm = "grandmother";
	string gr = "great-";
	if(me==a)return this->head->name;
	if(f==a)return this->head->father->name;
	if(m==a)return this->head->mother->name;
	if(gf==a)return this->head->father->father->name;
	if(gm==a)return this->head->father->mother->name;
	if(gf==a)return this->head->mother->father->name;
	if(gm==a)return this->head->mother->mother->name;

char* great="great-";
int i=countOccurences(great, a);   
    string res =""; 
    int maxLevel = i+4; 
char* grandfather="grandfather";
  if (countOccurences(grandfather, a)){
    find(this->head, 0, maxLevel, res,"Male");
return res; 
}

    find(this->head, 0, maxLevel, res,"Female");
return res; 

}


bool Tree::remove(std::string a)
{

struct node* ans=new node("new");
if(ifNodeExists(this->head, a,ans)){

deleteTree(ans);  


return true;
}
	return false;
}

bool Tree::searchF(node *root, std::string a,std::string b)
{
	if (root != nullptr)
	{
		if (root->name == a)
		{
			if (root->father != nullptr)
	{
		throw std::runtime_error(std::string("Exception - Son has father"));
	}
			root->father = new node(b);
			root->father->Gender="Male";
			return true;
		}
		else
		{
			searchF(root->father, a,b);
			searchF(root->mother, a,b);
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool Tree::searchM(node *root, std::string a,std::string b)
{
	if (root != nullptr)
	{
		if (root->name == a)
		{
			if (root->mother != nullptr)
	{
		throw std::runtime_error(std::string("Exception - Son has mother"));
	}
			root->mother = new node(b);
			root->mother->Gender="Female";
			return true;
		}
		else
		{
			searchM(root->father, a,b);
			searchM(root->mother, a,b);
			return false;
		}
	}
	else
	{
		return false;
	}
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void Tree::print2DUtil(node *root, int space)			/*Geeks for Geeks - */
{
	// Base case
	if (root == nullptr)return;
	

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	print2DUtil(root->mother, space);

	// Print current node after space
	// count
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->name << "\n";

	// Process left child
	print2DUtil(root->father, space);
}


bool Tree::ifNodeExists( node* Node, string key,node* &dest) 
{ 

    if (Node == NULL) 
        return false; 
  
    if (Node->name == key){
	dest=Node; 
        return true; 
  }
    /* then recur on left sutree */
    bool res1 = ifNodeExists(Node->mother, key,dest); 
  
    if(res1) return true; // node found, no need to look further 
  
    /* node is not found in left, so recur on right subtree */
    bool res2 = ifNodeExists(Node->father, key,dest); 
  
    return res2; 
} 


void Tree::deleteTree(node* node)  
{  

    if (node == NULL) return;  
     // cout << "\n Det node: " << node->name;
    /* first delete both subtrees */

    deleteTree(node->mother);  
    deleteTree(node->father);  
      
    /* then delete the node */
    //cout << "\n Deleting node: " << node->name;
    free(&node->name);    
    free(node);  
}  

void Tree::find(node *root, int level, int &maxLevel, string &res,string g) 
{ 
    if (root != NULL) 
    { 
        find(root->father, ++level, maxLevel, res,g); 
  
        // Update level and resue 
        if (level == maxLevel&&root->Gender==g) 
        { 
            res = root->name;; 
            maxLevel = level; 

        } 
  
        find(root->mother, level, maxLevel, res,g); 
    } 
} 



int Tree::countOccurences(char *str,  
                    string word) 
{ 
    char *p; 
  
    // split the string by spaces in a 
    vector<string> a; 
  
    p = strtok(str, " "); 
    while (p != NULL) 
    { 
        a.push_back(p); 
        p = strtok(NULL, " "); 
    } 
  
    // search for pattern in a 
    int c = 0; 
    for (int i = 0; i < a.size(); i++) 
  
        // if match found increase count 
        if (word == a[i]) 
            c++; 
    return c; 
} 
