//prefix tree trie ds example . for finding the words is present or not
#include<iostream>
#include<unordered_map>
using namespace std;

class node{//datatype which contains the data
    public:
        char data;
        unordered_map<char,node*> children;
        bool terminal;
        
        node(char d){
            data=d;
            terminal=false;
        }
};

class trie{//trie ds class
    node* root;
    
    public:
        trie(){
            root=new node('\0');
        }
        void insert(char* w){//insert string into trie
            int i=0;
            node* temp=root;
            for(i=0;w[i]!='\0';i++){
                if(temp->children.count(w[i])==0){
                    node* nn=new node('\0');
                    temp->children[w[i]]=nn;
                    temp=nn;
                }
                else{
                    temp=temp->children[w[i]];
                }
            }
            temp->terminal=true;//it makes the node a terminal node that represents that the word ends here
        }
        bool find(char *w){
            node* temp=root;
            int i=0;
            for(i=0;w[i]!='\0';i++){
                if(temp->children.count(w[i])==0){
                    return false;
                }
                else{
                    temp=temp->children[w[i]];
                }
            }
            return temp->terminal;
        }
};

int main(){
    trie tds;
    int i,n,number;
    char words[10][10];
    cout<<"enter number of words:- ";
    cin>>number;
    cout<<"enter words:-\n";
    for(i=0;i<number;i++){
        cin>>words[i];
    }
    for(i=0;i<number;i++){
        tds.insert(words[i]);
    }
    cout<<"Enter number of word to be searched:- ";
    cin>>n;
    cout<<"Enter words to be searched:- ";
    for(i=0;i<n;i++){
        char word[10];
        cin>>word;
        if(tds.find(word)){
            cout<<"Word is present\n";
        }
        else{
            cout<<"Word is absent\n";
        }
    }
    return 0;
}