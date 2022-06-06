#include<iostream>
#include<cstring>
#include<unordered_map>
#include<map>
using namespace std;

class Car{
    public:

    int price;
    string name;

    Car(){
    }

    Car(string n,int p){
        price = p;
        name = n;
    }
    void print(){
        cout<<name<<endl;
        cout<<price<<endl;
    }
};

int main(){
    Car c1("BMW",100);
    Car c2("Audi",200);
    Car c3("Ferrari",300);
    Car c4("CodingCar",500);
    ///Insertion -1 or Initialisation

    unordered_map<string,Car> myMap = { {"Deepak",c1} };

    ///map<string,Car> myMap = { {"Deepak",c1} };

    ///Insertion -2
    pair<string,Car> p("Mayank",c2);
    myMap.insert(p);

    ///Insert - 3
 //myMap.insert(make_pair<string,Car>("Prateek",c3) );

    ///Insert -4
   myMap["Vibhav"] = c3;
   myMap["CB"] = c4;

   ///Searching using Count Fn
   if(myMap.count("Vibhav")==1){
    myMap["Vibhav"].print();
   }
   ///Deletion from Map
   myMap.erase("CB");


   ///Search using Find Fn
   auto it = myMap.find("CB");
   if(it==myMap.end()){
    cout<<"CB has no Car "<<endl;
   }
   else{
        (it->second).print();
   }


   ///Print All The Entries in Your Map.
   //unordered_map<string,Car>:: iterator it;
   for(auto it = myMap.begin();it!=myMap.end();it++){
        cout<<it->first <<endl; ///Key
        Car c = it->second; ///Value
        c.print();
        cout<<endl;
   }





return 0;
}
