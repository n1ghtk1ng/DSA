#include <iostream>
#include <cstring>
using namespace std;
class Person{
private:
    char name[20];
    char gender;
    int phone;
public:
    //Person();
    Person(char g, char* s, int p){
        gender = g;
        strcpy(name, s);
        if (p > 10000)
            phone = 0;  //Classes provide data checking
        else phone = p;
    }

    char getGender(){
        return getGender();
    }

    void showDetails() const {
        cout << gender << " " << name << " "
            << phone << endl;
    }
};

class Engineer : public Person{
private:
    char branch[20], clg[20];
public:
    Engineer(
        char *name, char g, int p,
        char *b, char *c
             ):Person(g, name, p){
                strcpy(branch, b);
                strcpy(clg, c);
    }

    void showDetails(){
        Person::showDetails();
        cout << branch << " " << clg << endl;
    }

};

int main(){
    Engineer E("Apurv", 'M', 123, "CSE", "DTU");
    E.showDetails();
}






