//Naor Maoz_Oz Klingel

#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>

using namespace std;
using namespace family;


TEST_CASE("Test 1") {
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
    CHECK( T.relation("Nachor") ==string("great-grandfather"));				//20
	T.display();
}



TEST_CASE("Test 2") {
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
    CHECK(T2.find("great-great-grandfather")==string("George VI"));		//16
    T2.remove("Philip"); 
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
    CHECK(T2.relation("George VI")==string("unrelated"));
    CHECK(T2.relation("Philip")==string("unrelated"));
    CHECK(T2.relation("Andrew")==string("unrelated"));
    T2.addFather("Charles", "Edward");
    CHECK( T2.relation("Edward") ==string("great-grandFather"));
         T2.display();
}



TEST_CASE("Test 3") {
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
    CHECK( T3.relation("Nachor") ==string("great-grandfather"));				//20
	T3.display();
    T3.remove("shimon"); 
    CHECK(T3.relation("Rachel")==string("unrelated")); 
 T3.remove("Rachel"); 
    CHECK(T3.relation("betuel")==string("unrelated"));
    CHECK(T3.relation("mishi")==string("unrelated"));
	T3.display();

}
