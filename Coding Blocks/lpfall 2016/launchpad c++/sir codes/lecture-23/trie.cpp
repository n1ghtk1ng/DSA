#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode{
public:
    char data;
    bool isTerminal;
    unordered_map<char,TrieNode* > children;

    TrieNode(char d){
        data = d;
        isTerminal = false;
    }
};

class Trie{

    TrieNode* root;
    int numWords;

public:
    Trie(){
        root = new TrieNode('\0');
        numWords = 0;
    }
    void addWordsHelper(char *word,TrieNode*node){
        if(word[0]=='\0'){
            node->isTerminal = true;
            return ;
        }
        char currentChar = word[0];
        ///Find if a node exists or not
        TrieNode* childNode = NULL;
        if(node->children.find(currentChar)==node->children.end()){
            ///Nahi mili node vo vali
            childNode = new TrieNode(currentChar);
            node->children[currentChar]= childNode;

        }
        else{
            childNode = node->children.find(currentChar)->second;
        }
        addWordsHelper(word+1,childNode);

    }

    void addWord(char *word){
        addWordsHelper(word,root);
        numWords++;
    }

    bool findWord(char *word){
        TrieNode*node = root;

        for(int i=0;word[i]!='\0';i++){

            char currentChar = word[i];
            auto temp = node->children.find(currentChar);
            if(temp==node->children.end()){
                ///Nahi mila to return false;
                return false;
            }
            else{

                node = temp->second;
            }
        }
        return node->isTerminal;
    }

};

int main(){

char words[][100] ={"Apple","Are","Nope","Not","Pineapple","Coding","Try","Google"};
char searchWords[][100] = {"Nope","No","apple","Blocks","Coding"};

Trie t;
for(int i=0;i<6;i++){
    t.addWord(words[i]);
}

for(int j=0;j<5;j++){
    if(t.findWord(searchWords[j])==true){
        cout<<"Found "<<searchWords[j]<<endl;
    }
}



}
