/*
    Implements phone dictionary;
*/

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        map< char , node* > mp;
        bool terminal;
        node():terminal(false){
        }
};

class Solution{

    public:

        void put(node* root, string s);
    
        void help(node* root , vector<string> &v1 , string r);
    
        vector<vector<string>> displayContacts(int n, string contact[], string s);
    
};

int main(){

    int n;
    cout<<"Enter no of words: ";
    cin>>n;

    string str[n];
    cout<<"Enter words: ";

    for(int i = 0 ; i < n ; ++i){
        
        cin>>str[i];

    }

    string r;
    cout<<"Enter word to search: ";
    cin>>r;

    Solution sl;
    vector < vector < string > > ans = sl.displayContacts(n , str , r);

    for(int i = 0 ; i < ans.size() ; ++i){

        for(int j = 0 ; j < ans[i].size() ; ++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;

    }

    return 0;
}

void Solution::put(node* root, string s){
        
        for(int i = 0 ; i < s.size() ; ++i){
            
            if(root->mp.find(s[i]) == root->mp.end()){
                root->mp[s[i]] = new node();
            }
            
            root = root->mp[s[i]];
        }
        
        root->terminal = true;
        
    }
    
void Solution::help(node* root , vector<string> &v1 , string r){
        
    if(root->terminal == true){
        v1.push_back(r);
    }
        
    map < char , node* > :: iterator it1 = root->mp.begin();
        
    for( ; it1 != root->mp.end() ; ++it1){
            
        help( it1->second , v1 , r + it1->first);
            
    }
    return ;
        
}
    
vector<vector<string>> Solution:: displayContacts(int n, string contact[], string s)
{
    // code here
    node* root = new node();
    for(int i = 0 ; i < n ; ++i){
        put(root, contact[i]);
    }
    
    vector < vector < string > > ans;
    
    string r ="";
    for(int i = 0 ; i < s.size() ; ++i ){
        vector<string> v1;
        if(root == NULL || root->mp.find(s[i]) == root->mp.end()){
            root = NULL;
            v1.push_back("0");
            ans.push_back(v1);
        }
        else{
            
            r+=s[i];
            root = root->mp[s[i]];
            
            help(root , v1, r);
            
            ans.push_back(v1);
            
        }
        
    }
        
    return ans;
        
}

