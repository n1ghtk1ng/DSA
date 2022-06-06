#include<iostream>
using namespace std;

class Vector{
private:
    int *arr;
    int i;
    int max_size;

public:
    Vector(){
        arr = new int[2];
        i = 0;
        max_size = 2;
    }
    Vector(const int init_size){
        arr = new int[init_size];
        i = 0;
        max_size = init_size;
    }
    Vector(Vector &X){
        i = 0;
        max_size = X.size();
        arr = new int[max_size];

        for(int j=0;j<X.size();j++){
                arr[i] = X[j];
                /// X[j] , X.at(j), X.arr(j)
                i++;
                //push_back(X.at(j));
        }
    }
    void push_back(const int data){
        ///Check if vector is full, double its size
        if(i==max_size){
                cout<<"Doubling the size to"<<2*max_size<<endl;
                int *newArr = new int[2*max_size];
                for(int j=0;j<max_size;j++){
                    newArr[j] = arr[j];
                }
                max_size *= 2;

                delete [] arr;
                arr = newArr;
        }
        arr[i] = data;
        i++;
    }
    void pop_back(){
        if(i>0){
            i--;

        }
    }
    int getLast()const{
        return arr[i-1];
    }
    int at(const int index)const{
        if(index<i && index>=0){
            return arr[index];
        }
    }
    int size()const{
        return i;
    }
    int operator[](int index){
        return arr[index];
    }
    void print() const{
        for(int j=0;j<i;j++){
            cout<< arr[j] <<" ";
        }
        cout<<endl;
    }
    void operator+(Vector &v2){
        for(int j=0;j<v2.size();j++){
            push_back(v2[j]);
        }
    }
    ~Vector(){
        if(arr!=NULL){
            delete [] arr;
            arr = NULL;
        }
    }

};

void operator<<(ostream &os, Vector &v ){

    for(int j=0;j<v.size();j++){
         cout<<v[j] ;
    }

}


int main(){

Vector v1;
Vector v(6);
for(int i=0;i<=5;i++){
    v.push_back(i);
}
v.pop_back();
v.push_back(6);

//Deep copy is created.
Vector v2(v);
v.pop_back();

v2.print();
v.print();

for(int i=0;i<v.size();i++){
    cout<< v[i];
}

v+v2;
v.print();

cout<< v ;

return 0;
}
