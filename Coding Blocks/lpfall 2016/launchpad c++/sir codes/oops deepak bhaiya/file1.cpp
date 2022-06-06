#include <iostream>
#include <cstring>
using namespace std;
char * destructorTesting;

class Person{
private:
    //char name[20]; //static array
    char * name;    //ptr to a char
    char gender;
    int phone;
public:
    Person();
    Person(char, char*);
    Person(char, char*, int);
    Person(const Person&);
    char getGender();
    char* getName();
    void showDetails() const ;
    //ostream& operator<<(ostream& out);
    void updateName(char * s);
    void updateDetails(Person &P) const;
    ~Person();
    friend ostream& operator<<(
            ostream& out, const Person& P
                               );


};
ostream& operator<<(ostream& out, const Person& P){
    out << P.gender << " " << P.name << " " << P.phone << endl;
    return out;
}


char Person::getGender(){
    return gender;
}
char* Person::getName(){
    return name;
}
void Person::showDetails()const {
    cout << gender << " " << name << " "
        << phone << endl;
}
Person::Person(){
    gender = '\0';
    name = NULL;
    phone = 0;
}

Person::Person(char g, char* s){
    gender =g;
    name = new char[strlen(s) + 1];
    strcpy(name, s);
    phone = 0;
}
Person::Person(char g, char* s, int p){
    gender =g;
    name = new char[strlen(s) + 1];
    strcpy(name, s);
    if (p > 10000)
        phone = 0;  //Classes provide data checking
    else phone = p;
}

void Person::updateDetails(Person& p)const{
    p.gender = 'F';
}

void Person::updateName(char * s){
    strcpy(name, s);
    //name[0] = 'a';
}

Person::Person(const Person& P){
    gender = P.gender;
    //The following line make current
    //constructor work as deep copy constructor
    name = new char[strlen(P.name) + 1];
    strcpy(name, P.name);
    //name = P.name;
    phone = P.phone;
}

Person::~Person(){
    delete [] name;
}



int test(const Person& P){
//fun with destruction

    Person A = P;
    destructorTesting = A.getName();

}
int main(){
    Person B('M', "ABC", 123);
    Person A(B);
    cout << A;


    //B.showDetails();
    //test(B);
    //cout << destructorTesting;

    //A.updateName("XYZ");
    //A.showDetails();
    //B.showDetails();
    //A.updateDetails(B);
    //B.showDetails();
}
