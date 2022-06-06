#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    char data;
    bool isTerminal;
    unordered_map<char,TrieNode*> children;

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
        if(node->children[currentChar]==NULL){
            ///Nahi mili node vo vali
            childNode = new TrieNode(currentChar);
            node->children[currentChar]= childNode;

        }
        else{
            childNode = node->children[currentChar];
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
            //cout<<currentChar<<endl;
            if(node->children[currentChar]==NULL){
                ///Nahi mila to return false;
                return false;
            }
            else{

                node = node->children[currentChar];
            }
        }
        return node->isTerminal;
    }

    bool deletewordhelper(char *word,int index,TrieNode*node){
        //base case
        if(index==strlen(word)){
            if(node->isTerminal==false)
            return false;

            node->isTerminal=false;
            numWords--;
            for(int i=0;i<26;i++){
                if(node->children[char(97+i)]!=NULL)
                    return false;
            }
            //cout<<"u can delete me"<<endl;
            return true;
        }
        //recursive case
        char ch=word[index];
        if(node->children[ch]==NULL)
            return false;
        bool shoulddeletecurrnode=deletewordhelper(word,index+1,node->children[ch]);
        if(shoulddeletecurrnode==true){
            TrieNode*temp=node->children[ch];
            node->children[ch]=NULL;
            delete temp;
            temp=NULL;
            for(int i=0;i<26;i++){
                if(node->children[char(97+i)]!=NULL)
                    return false;
            }
            //cout<<"u can delete me"<<endl;
            return true;
        }
        else
        return false;

    }
    void deleteword(char *word){
        deletewordhelper(word,0,root);
    }

};

int main(){

char words[][100] ={"Apple","Are","Nope","Not","Pineapple","Coding","Try","Google","Goof","Googte"};
char searchWords[][100] = {"Nope","No","apple","Blocks","Coding","Apple","Google","Try","Goof"};
char deleteWords[][100]={"Appl","Google","Try"};
Trie t;
for(int i=0;i<9;i++){
    t.addWord(words[i]);
}

for(int j=0;j<5;j++){
    if(t.findWord(searchWords[j])==true){
        cout<<"Found "<<searchWords[j]<<endl;
    }
}

for(int j=0;j<=2;j++){
    {
        t.deleteword(deleteWords[j]);
    }
}
for(int j=5;j<=8;j++){
    if(t.findWord(searchWords[j])==true){
        cout<<"Found "<<searchWords[j]<<endl;
    }
    else
        cout<<"Not Found "<<searchWords[j]<<endl;
}

return 0;
}

