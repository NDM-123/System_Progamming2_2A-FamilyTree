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
//     family::Tree T3 ("Tair"); 
// 	T3.addFather("Tair", "Aviel")   
// 	 .addMother("Tair", "Tohar")   
// 	 .addFather("Aviel", "Shlomo")
// 	 .addMother("Aviel", "Rachel")
// 	 .addFather("Tohar", "Shay")
//      .addMother("Tohar", "Lilach")
//      .addMother("Lilach", "Hana")
//      .addMother("Hana", "Sultana")
// 	 .addFather("Lilach", "Yair");
//     //CHECK( T3.relation("Sultana") ==string("great-great-grandmother"));
//    // T3.display();
//   //  printf("...............%s",T3.relation("Sultana").c_str());
//     CHECK( T3.relation("Aviel") ==string("father"));
//     CHECK( T3.relation("Tohar") ==string("mother"));
//     CHECK( T3.relation("Shlomo") ==string("grandfather"));
//     CHECK( T3.relation("Rachel") ==string("grandmother"));
//     CHECK( T3.relation("Yair") ==string("great-grandfather"));
//     CHECK( T3.relation("Hana") ==string("great-grandmother"));
//     CHECK(T3.relation("Tair")==string("me"));
//     CHECK(T3.find("mother")==string("Tohar"));
//     CHECK(T3.find("father")==string("Aviel"));
//     CHECK(T3.find("grandmother")==string("Lilach"));
//     CHECK(T3.find("grandfather")==string("Shlomo"));
//     CHECK(T3.find("me")==string("Tair")); 
//     CHECK(T3.find("great-grandmother")==string("Hana"));          
//     CHECK(T3.find("great-grandfather")==string("Yair"));
//      try{
//         T3.find("sister");
//     }
//     catch(exception &ex){
//         cout<<ex.what()<<endl;
//     }               
//     T3.remove("Lilach");               
//     CHECK(T3.relation("Yair")==string("unrelated"));
//     CHECK(T3.relation("Hana")==string("unrelated"));
//     CHECK(T3.relation("Lea")==string("unrelated"));		//21
//   //  T3.display();
 

//     family::Tree T4 ("Shlomo"); 
// 	T4.addFather("Shlomo", "David")   
// 	 .addMother("Shlomo", "Batsheva")   
// 	 .addFather("David", "Yishai")
// 	 .addMother("David", "Nitzevet")
// 	.addFather("Yishai", "Oved")
//     .addFather("Oved", "Boaz")
//     .addMother("Oved", "Ruth");
//     CHECK( T4.relation("David") ==string("father"));
//     CHECK( T4.relation("Batsheva") ==string("mother"));
//     CHECK( T4.relation("Yishai") ==string("grandfather"));
//     CHECK( T4.relation("Nitzevet") ==string("grandmother"));
//     CHECK( T4.relation("Oved") ==string("great-grandfather"));
//     CHECK( T4.relation("Boaz") ==string("great-great-grandfather"));
//     CHECK( T4.relation("Ruth") ==string("great-great-grandmother"));
//     CHECK(T4.relation("Shlomo")==string("me"));
//     CHECK(T4.relation("Avshalom")==string("unrelated"));
//     CHECK(T4.relation("Neomi")==string("unrelated"));
//     T4.addMother("Ruth", "Neomi");
//    // CHECK(T4.relation("Neomi")==string("great-great-great-grandmother"));
//     CHECK(T4.find("mother")==string("Batsheva"));
//     CHECK(T4.find("father")==string("David"));
//     CHECK(T4.find("grandmother")==string("Nitzevet"));
//     CHECK(T4.find("grandfather")==string("Yishai"));
//     CHECK(T4.find("me")==string("Shlomo")); 
//     CHECK(T4.find("great-grandfather")==string("Oved"));
//     CHECK(T4.find("great-great-grandfather")==string("Boaz"));
//     CHECK(T4.find("great-great-grandmother")==string("Ruth"));
//     CHECK(T4.find("great-great-great-grandmother")==string("Neomi"));
//     try{
//         T4.find("aunt");
//     }
//     catch(exception &ex){
//         cout<<ex.what()<<endl;
//     }
//     T4.remove("Yishai");
//     CHECK(T4.relation("Yishai")==string("unrelated"));
//     CHECK(T4.relation("Boaz")==string("unrelated"));
//     CHECK(T4.relation("Oved")==string("unrelated"));
//     CHECK(T4.relation("Ruth")==string("unrelated"));		//23
//    // T4.display();

//      family::Tree T5 ("Ido"); 
// 	T5.addFather("Ido", "Nati")   
// 	 .addMother("Ido", "Dana")   
// 	 .addFather("Nati", "Shayke")
// 	 .addMother("Nati", "Ruthi")
// 	.addFather("Shayke", "Elimelech")
//     .addMother("Dana", "Hava")
//     .addFather("Dana", "Aharon")
//     .addFather("Elimelech", "Haadmor hahaluzt")
//     .addMother("Aharon", "Hava")
//     .addMother("Elimelech", "Ruhama");
//     CHECK( T5.relation("Nati") ==string("father"));
//     CHECK( T5.relation("Dana") ==string("mother"));
//     CHECK( T5.relation("Shayke") ==string("grandfather"));
//     CHECK( T5.relation("Ruthi") ==string("grandmother"));
//     CHECK( T5.relation("Elimelech") ==string("great-grandfather"));
//     CHECK( T5.relation("Haadmor hahaluzt") ==string("great-great-grandfather"));
//     CHECK( T5.relation("Ruhama") ==string("great-great-grandmother"));
//     CHECK(T5.relation("Ido")==string("me"));
//     CHECK(T5.relation("Avshalom")==string("unrelated"));
//     CHECK(T5.relation("Aharon")==string("grandfather"));
//    //CHECK(T5.relation("Hava")==string("grandmother"));
//     //printf("%s",T5.relation("Hava").c_str());

//     CHECK(T5.find("mother")==string("Dana"));
//     CHECK(T5.find("father")==string("Nati"));
//     CHECK(T5.find("grandmother")==string("Hava"));
//     CHECK(T5.find("grandfather")==string("Shayke"));
//     CHECK(T5.find("me")==string("Ido")); 
//     CHECK(T5.find("great-grandfather")==string("Elimelech"));
//     CHECK(T5.find("great-great-grandfather")==string("Haadmor hahaluzt"));
//     CHECK(T5.find("grandmother")==string("Hava"));
//     CHECK(T5.find("grandfather")==string("Shayke"));
//     CHECK(T5.find("great-great-grandmother")==string("Ruhama"));		//20
//     try{
//         T5.find("uncle");
//     }
//     catch(exception &ex){
//         cout<<ex.what()<<endl;
//     }
//     T5.display();
//     printf("................................................\n\n\n");
//     T5.remove("Aharon");
//   //  T5.display();
// }














