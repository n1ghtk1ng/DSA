#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string, vector<int> > phonebook;

    phonebook["Shikha"].push_back(9988);
    phonebook["Shikha"].push_back(9977);

    auto it = phonebook.find("Shikha");
    for(auto vit = (it->second).begin();vit!=(it->second).end();vit++){
        cout<< *vit <<endl;
    }


}
