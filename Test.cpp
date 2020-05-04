//Naor Maoz_Oz Klingel

#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>

using namespace std;
using namespace family;

/*This function dosent work now only when i add the implementation*/
// TEST_CASE("check addFather")
// {
//     Tree tree("Yosef");

//     tree.addFather("Yosef", "Yaakov").addFather("Yaakov", "Yitzak").addFather("Yitzak", "Avraham");
//     CHECK((tree.head->father->name).compare("Yaakov") == 0);
//     CHECK((tree.head->father->father->name).compare("Yitzak") == 0);
//     CHECK((tree.head->father->father->father->name).compare("Avraham") == 0);
// }
/*This function dosent work now only when i add the implementation*/
// TEST_CASE("check addMother")
// {
//     Tree tree("Dina");

//     tree.addMother("Dina", "Leah").addMother("Leah", "Rivka").addMother("Rivka", "Sara");
//     CHECK((tree.head->mother->name).compare("Leah") == 0);
//     CHECK((tree.head->mother->mother->name).compare("Rivka") == 0);
//     CHECK((tree.head->mother->mother->mother->name).compare("Sara") == 0);
// }
TEST_CASE("check find")
{
    Tree T("Dan");
    T.addFather("Dan", "Yaakov")
     .addFather("Yaakov", "Yitzak")
     .addFather("Yitzak", "Avraham")
     .addMother("Yitzak", "Sara")	    
     .addMother("Dan", "Bilhaa")	    
     .addMother("Bilhaa", "Ricky")	    
     .addMother("Yaakov", "Tova")	    	    
     .addMother("Lavan", "Hagar")
     .addFather("Lavan", "Yishmael")
     .addFather("Bilhaa","Lavan");
	T.display();
    CHECK(T.find("me") == "Dan");
    CHECK(T.find("mother") == "Bilhaa");
    CHECK(T.find("father") == "Yaakov");
    CHECK(T.find("grandfather") == "Yitzak");
    CHECK(T.find("grandfather") == "Lavan");	
    CHECK(T.find("grandmother") == "Ricky");
    CHECK(T.find("grandmother") == "Tova");
    CHECK(T.find("great-grandmother") == "Hagar");
    CHECK(T.find("great-grandmother") == "Sara");
    CHECK(T.find("great-grandfather") == "Yishmael");
    CHECK(T.find("great-grandfather") == "Avraham");		//17
}

TEST_CASE("check relation"){
    Tree T("Dan");
    T.display();
    T.addFather("Dan", "Yaakov")
     .addFather("Yaakov", "Yitzak")
     .addFather("Yitzak", "Avraham")
     .addMother("Yitzak", "Sara")	    
     .addMother("Dan", "Bilhaa")	    
     .addMother("Bilhaa", "Ricky")	    
     .addMother("Yaakov", "Tova")	    	    
     .addMother("Lavan", "Hagar")
     .addFather("Lavan", "Yishmael")
     .addFather("Bilhaa","Lavan");
    CHECK(T.relation("Dan").compare("me") == 0);
    CHECK(T.relation("Yaakov").compare("father") == 0);
    CHECK(T.relation("Bilhaa").compare("mother") == 0);
    CHECK(T.relation("Yitzak").compare("grandfather") == 0);
    CHECK(T.relation("Lavan").compare("grandfather") == 0);
    CHECK(T.relation("Ricky").compare("grandmother") == 0);
    CHECK(T.relation("Tova").compare("grandmother") == 0);
    CHECK(T.relation("Avraham").compare("great-grandfather") == 0);
    CHECK(T.relation("Yishmael").compare("great-grandfather") == 0);
    CHECK(T.relation("Sara").compare("great-grandmother") == 0);
    CHECK(T.relation("Hagar").compare("great-grandmother") == 0);		//28
}
/*This function dosent work now only when i add the implementation*/
// TEST_CASE("check remove")
// {
//     Tree T("Dan");
//     T.addFather("Dan", "Yaakov").addFather("Yaakov", "Yitzak").addMother("Dan", "Bilhaa").addFather("Yitzak", "Avraham");
//     T.remove("Avraham");
//     CHECK(T.relation("Avraham") == nullptr);
//     T.remove("Bilhaa");
//     CHECK(T.relation("Bilhaa") == nullptr);
//     T.remove("Yitzak");
//     CHECK(T.relation("Yitzak") == nullptr);
//     T.remove("Yaakov");
//     CHECK(T.relation("Yaakov") == nullptr);
//     T.remove("Dan");	
//     CHECK(T.relation("Dan") == nullptr);
// }
TEST_CASE("Test Tree 1") {
family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov");   // Tells the tree that the father of Yosef is Yaakov.
	 T.addMother("Yosef", "Rachel");   // Tells the tree that the mother of Yosef is Rachel.
	 T.display();
	 T.addFather("Yaakov", "Isaac");
	 T.addMother("Yaakov", "Rivka");
	 T.addFather("Isaac", "Avraham");
         T.addMother("Isaac", "Sarah");
	 T.addFather("Avraham", "Terah");
	 T.display();
    CHECK( T.relation("Yaakov") ==string("father"));
    CHECK( T.relation("Rachel") ==string("mother"));
    CHECK( T.relation("Isaac") ==string("grandfather"));
    CHECK( T.relation("Rivka") ==string("grandmother"));
    CHECK( T.relation("Avraham") ==string("great-grandfather"));
    CHECK( T.relation("Sarah") ==string("great-grandmother"));
    CHECK( T.relation("Terah") ==string("great-great-grandfather"));
    CHECK(T.relation("Yosef")==string("me"));
    CHECK(T.find("father")==string("Yaakov"));
    CHECK(T.find("mother")==string("Rachel"));
    CHECK(T.find("grandfather")==string("Isaac"));
    CHECK(T.find("grandmother")==string("Rivka"));
    CHECK(T.find("me")==string("Yosef")); 
    CHECK(T.find("great-grandfather")==string("Avraham"));          
    CHECK(T.find("great-grandmother")==string("Sarah"));               
    CHECK(T.find("great-great-grandfather")==string("Terah"));
    T.remove("Avraham");  
	T.display();             
    CHECK(T.relation("Avraham")==string("unrelated"));
    CHECK(T.relation("Terah")==string("unrelated"));
    CHECK(T.relation("Hagar")==string("unrelated"));
    T.addFather("Isaac", "Nachor");
    CHECK( T.relation("Nachor") ==string("great-grandfather"));				//48
	T.display();
}



TEST_CASE("Test Tree 2") {
family::Tree T2 ("George"); 
	T2.addFather("George", "William");   
	 T2.addMother("George", "Catherine"); 
         T2.display();  
	 T2.addFather("William", "Charles");
	 T2.addMother("William", "Diana");
	 T2.addFather("Charles", "Philip");
         T2.display();
     T2.addMother("Charles", "Elizabeth");
	 T2.addFather("Elizabeth", "George VI");
         T2.display();
    CHECK( T2.relation("William") ==string("father"));
    CHECK( T2.relation("Catherine") ==string("mother"));
    CHECK( T2.relation("Charles") ==string("grandfather"));
    CHECK( T2.relation("Diana") ==string("grandmother"));
    CHECK( T2.relation("Philip") ==string("great-grandfather"));
    CHECK( T2.relation("Elizabeth") ==string("great-grandmother"));
    CHECK( T2.relation("George VI") ==string("great-great-grandfather"));
    CHECK(T2.relation("George")==string("me"));
    CHECK(T2.find("mother")==string("Catherine"));
    CHECK(T2.find("father")==string("William"));
    CHECK(T2.find("grandmother")==string("Diana"));
    CHECK(T2.find("grandfather")==string("Charles"));
    CHECK(T2.find("me")==string("George")); 
    CHECK(T2.find("great-grandmother")==string("Elizabeth"));          
    CHECK(T2.find("great-grandfather")==string("Philip"));               
    CHECK(T2.find("great-great-grandfather")==string("George VI"));		
    T2.remove("Philip"); 
    T2.display();
    CHECK(T2.relation("George VI")==string("unrelated"));
    CHECK(T2.relation("Philip")==string("unrelated"));
    CHECK(T2.relation("Andrew")==string("unrelated"));
    T2.addFather("Charles", "Edward");
    CHECK( T2.relation("Edward") ==string("great-grandFather"));	//68
    T2.display();
/*test wrong input that throws exception*/
	try{
        T2.addMother("George", "Meghan");
    }
    catch(exception &ex){
        cout<<ex.what()<<endl;
    }    
     try{
        T2.addFather("George", "Harry");
    }
    catch(exception &ex){
        cout<<ex.what()<<endl;
    }           
     try{
        T2.find("Andrew");
    }
    catch(exception &ex){
        cout<<ex.what()<<endl;
    }
    
}



TEST_CASE("Test Tree 3") {
family::Tree T3 ("naor"); // Yosef is the "root" of the tree (the youngest person).
	T3.addFather("naor", "shimon");   // Tells the tree that the father of Yosef is Yaakov.
	 T3.addMother("naor", "Rachel");   // Tells the tree that the mother of Yosef is Rachel.
	T3.display();
	 T3.addFather("Rachel", "betuel");
	 T3.addMother("Rachel", "mishi");
	  T3.addFather("shimon", "Isaac");
	 T3.addMother("shimon", "Rivka");
	T3.display();
    CHECK( T3.relation("shimon") ==string("father"));
    CHECK( T3.relation("Rachel") ==string("mother"));
    CHECK( T3.relation("Isaac") ==string("grandfather"));
    CHECK( T3.relation("Rivka") ==string("grandmother"));
///add more
         T3.addFather("Isaac", "Avraham");
         T3.addMother("Isaac", "Sarah");
	 T3.addFather("Avraham", "Terah");
	 T3.display();
    CHECK( T3.relation("Avraham") ==string("great-grandfather"));
    CHECK( T3.relation("Sarah") ==string("great-grandmother"));
    CHECK( T3.relation("Terah") ==string("great-great-grandfather"));
    CHECK(T3.relation("naor")==string("me"));
    CHECK(T3.find("father")==string("shimon"));
    CHECK(T3.find("mother")==string("Rachel"));
    CHECK(T3.find("grandfather")==string("Isaac"));
    CHECK(T3.find("grandmother")==string("Rivka"));
    CHECK(T3.find("me")==string("Yosef")); 
    CHECK(T3.find("great-grandfather")==string("Avraham"));          
    CHECK(T3.find("great-grandmother")==string("Sarah"));               
    CHECK(T3.find("great-great-grandfather")==string("Terah"));
    T3.remove("Avraham");  
	T3.display();             
    CHECK(T3.relation("Avraham")==string("unrelated"));
    CHECK(T3.relation("Terah")==string("unrelated"));
    CHECK(T3.relation("Hagar")==string("unrelated"));
    T3.addFather("Rachel", "Nachor");
    CHECK( T3.relation("Nachor") ==string("great-grandfather"));				//88
	T3.display();
    T3.remove("shimon"); 
    CHECK(T3.relation("Rachel")==string("unrelated")); 
 T3.remove("Rachel"); 
    CHECK(T3.relation("betuel")==string("unrelated"));
    CHECK(T3.relation("mishi")==string("unrelated"));
	T3.display();

}
	TEST_CASE("Test Tree 4") {
     family::Tree T4 ("Nachshon"); 
 	T4.addFather("Nachshon", "Oz")   
 	 .addMother("Nachshon", "Ella")   
 	 .addFather("Oz", "Moshe")
 	 .addMother("Oz", "Bracha")
 	.addFather("Moshe", "Yaakov")
     .addFather("Yaakov", "Yosef")
     .addMother("Yaakov", "Rivka");
     CHECK( T4.relation("Nachshon") ==string("me"));
     CHECK( T4.relation("Batsheva") ==string("mother"));
     CHECK( T4.relation("Oz") ==string("father"));
     CHECK( T4.relation("Moshe") ==string("grandfather"));
     CHECK( T4.relation("Bracha") ==string("grandmother"));
     CHECK( T4.relation("Yaakov") ==string("great-grandfather"));
     CHECK( T4.relation("Rivka") ==string("great-great-grandmother"));
     CHECK(T4.relation("Yosef")==string("great-great-grandfather"));
     CHECK(T4.relation("Eli")==string("unrelated"));
     CHECK(T4.relation("Shachar")==string("unrelated"));
     T4.addMother("Yosef", "Sara");
     CHECK(T4.relation("Sara")==string("great-great-great-grandmother"));
     CHECK(T4.find("mother")==string("Ella"));
	     CHECK(T4.find("father")==string("Oz"));
     CHECK(T4.find("grandmother")==string("Bracha"));
     CHECK(T4.find("grandfather")==string("Moshe"));
     CHECK(T4.find("me")==string("Nachshon")); 
     CHECK(T4.find("great-grandfather")==string("Yaakov"));
     CHECK(T4.find("great-great-grandfather")==string("Yosef"));
     CHECK(T4.find("great-great-grandmother")==string("Rivka"));
     CHECK(T4.find("great-great-great-grandmother")==string("Sara"));
     T4.remove("Yaakov");
     CHECK(T4.relation("Yosef")==string("unrelated"));
     CHECK(T4.relation("Rivka")==string("unrelated"));
     CHECK(T4.relation("Sara")==string("unrelated"));
     CHECK(T4.relation("Uriya")==string("unrelated"));		//113
     T4.display();
		try{
        CHECK(T4.find("mother") == string("Alice"));		//fails
     }
     catch(exception &ex){
         cout<<ex.what()<<endl;
     }

}
	TEST_CASE("Test Tree 5") {
      family::Tree T5 ("Nave"); 
 	T5.addFather("Nave", "Shlomo")   
 	 .addMother("Nave", "Miri")   
 	 .addFather("Miri", "Shimon")
 	 .addMother("Miri", "Rachel")
 	 .addFather("Shimon", "Moshe")
     .addMother("Shimon", "Dvora")
     .addFather("Moshe", "Dov")
     .addFather("Dov", "Yoel")
     .addMother("Dov", "Ann")
	 .addMother("Ann", "Rose");
		       CHECK( T5.relation("Nave") ==string("me"));
		       CHECK( T5.relation("Shlomo") ==string("father"));
		       CHECK( T5.relation("Miri") ==string("mother"));
		       CHECK( T5.relation("Shimon") ==string("grandfather"));
		       CHECK( T5.relation("Rachel") ==string("grandmother"));
		       CHECK( T5.relation("Moshe") ==string("great-grandfather"));
		       CHECK( T5.relation("Dov") ==string("great-great-grandfather"));
		       CHECK( T5.relation("Ann") ==string("great-great-great-grandfather"));
		       CHECK(T5.relation("Nave")==string("me"));
		       CHECK(T5.relation("Yagil")==string("unrelated"));
		       CHECK(T5.relation("Shimon")==string("grandfather"));
		       CHECK(T5.relation("Rachel")==string("grandmother"));
		       CHECK(T5.find("mother")==string("Miri"));
		       CHECK(T5.find("father")==string("Shlomo"));
		       CHECK(T5.find("grandmother")==string("Rachel"));
		       CHECK(T5.find("grandfather")==string("Shimon"));
		       CHECK(T5.find("me")==string("Nave")); 
		       CHECK(T5.find("great-grandfather")==string("Moshe"));
		       CHECK(T5.find("great-great-grandfather")==string("Dov"));
		       CHECK(T5.find("great-great-great-grandmother")==string("Ann"));		//105
		       try{
		           T5.find("Ori");
		       }
		       catch(exception &ex){
		           cout<<ex.what()<<endl;
		       }
		 T5.display();
		cout << endl;
     T5.remove("Dov");
     T5.display();
 }
