#include<iostream>
#include<cstring>
using namespace std;


class Car{
private:
    const int tyres;
    int seats;

public:
    int price;
    int model_no;
    char *name;
    static int count;

    //Constructor
    Car():tyres(4){
        cout<<"In car constructor "<<endl;
        count++;
    }
    Car(int p,int m):price(p),model_no(m),tyres(4){
        count++;
    }
    Car(int p,int m,char *n,int s):tyres(4){
        price =p;
        model_no = m;
        name = new char[strlen(n)+1];
        strcpy(name,n);
        seats = s;
        count++;

    }
    Car(Car &X):tyres(4){
        price = X.price;
        model_no = X.model_no;
        name = new char(strlen(X.name)+1);
        strcpy(name,X.name);
        seats = X.seats;
        count++;
    }
    void operator=(Car &X){

        //cout<<"In Equal To Function ";
        price = X.price;
        model_no = X.model_no;
        name = new char(strlen(X.name)+1);
        strcpy(name,X.name);
        seats = X.seats;

    }
    void operator+=(Car &X){
        price += X.price;
        seats += X.seats;
        model_no = 1111;
        int l1 = strlen(name);
        int l2 = strlen(X.name);

        char *name2 = new char(l1+l2+1);
        strcpy(name2,name);
        for(int i=0;i<=l2;i++){
            name2[i+l1] = X.name[i];
        }
        delete [] name;
        name = name2;
    }



    void setValues(int p,int m,char *n,int s){
        price =p;
        model_no = m;
        name = new char[strlen(n)+1];
        strcpy(name,n);
        seats = s;
    }
    void setName(char *n){
        name = new char[strlen(n)+1];
        strcpy(name,n);
    }
    void setSeats(int s){
        if(s>=2 && s<=12){
            seats = s;
        }
        else{
            seats = 4;
        }
    }
    int getSeats(){
        return seats;
    }


    void print(){
        cout<<"Name "<< name<<endl;
        cout<<"Model "<<model_no<<endl;
        cout<<"Price "<<price<<" $ "<<endl;
        cout<<"Seats "<<seats<<endl<<endl;
    }
    ~Car(){
        cout<<"Destroying Car "<<name<<endl;
        count--;
        if(name){
            delete [] name;
            name = NULL;
        }
    }
};

int Car::count = 0;

int main(){
    Car c;
    c.price = 100;
    c.model_no = 101;
    //c.tyres = 4;
    //strcpy(c.name,"Audi");
    c.setName("Audi");
    c.setSeats(-2);
    cout<< c.getSeats()<<endl;



    //Parametrized Constructor
    Car d(200,300,"BMW",9);

    Car d2(d);
    d2.name[0] = 'C';
    d2.price = 1000;

    d.print();
    d2.print();


    c.print();

    d2 = c;
    d2.name[0]='B';
    d2.print();
    c.print();

    d2+=d;

    //Count is in car Scope.
    cout<<"Count of Car is "<< Car::count <<endl;

    d2.print();
    Car *dynamicCar = new Car(1,2,"DC",3);
    delete dynamicCar;


    cout<<"Count of Car is "<< Car::count <<endl;


return 0;
}
