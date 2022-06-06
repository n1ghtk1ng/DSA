#include <iostream>
#include <cstring>
using namespace std;

class Person{
private :
    //char name[20];
    char *name;
    char gender;
    int phone;
    static int cnt;
public:
    /*static init(){
        //initialiser
        cnt = 0;
    }*/
    static int howManyPersons(){
            return cnt;
    }

    Person(){
        //name[0] = '\0';
        cout << "Inside Person ctor\n";
        gender = '\0';
        phone = 0;
        cnt++;
    };
    Person(char* n, char g, int p){
        //ctor 1
        cout << "Inside Person ctor\n";
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        gender = g;
        phone = p;
        cnt++;
    }
    Person(char*n , char g){
        //ctor 2
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        gender = g;
        cnt++;
    }

    Person(const Person& P){
        //strcpy(name, P.name);
        name = new char[strlen(P.name) + 1];
        strcpy(name, P.name);
        gender = P.gender;
        phone = P.phone;
        cnt++;
    }

    void showDetails(){
        cout << name << " " << gender << " "
            << phone << endl;

    }
    void updatePerson(){
        name[0] = 'z';
    }
    char * getName(){
        return name;
    }

    ~Person(){
        delete [] name;
        cnt--;
    }

    /*ostream& operator<< (ostream& out){
        out << name << " " << gender << " "<<
            phone << endl;
        return out;
    }*/
    friend ostream& operator<<(ostream& out,
                               const Person& P);
};

ostream& operator<<(ostream& out, const Person& P)
{
    out << P.name << " " << P.gender << " "<<
            P.phone << endl;
    return out;
}





int Person::cnt = 0;

char * destructorName;
int test(Person& P){
    Person A(P);
    destructorName = A.getName();
}

class Engineer:public Person{
private:
    char clg[20], branch[20];
public :
    Engineer(
        char * name, char g, int p,
        char * b, char* c
             ){

                 cout << "Inside Eng ctor\n";

                 strcpy(branch, b);
                 strcpy(clg, c);
        }

        void showDetails(){
            Person::showDetails();
            cout << branch << " " << clg << endl;

        }


};





//int Person::cnt = 0;
int main(){
    //Person x;
    //Person P("ABC", 'M', 123);
       //instance of a class
    //Person::init();
    Engineer E("Raju", 'M', 123,"CSE",  "DTU");
    E.showDetails();
    //Person B("XYZ", 'F', 123);
    //Person C(B);
    //cout << B << C << "Hello BLocks" << " " << 1.23;

    //cout << Person::howManyPersons();
    //cout << C.howManyPersons();
    return 0;
}
