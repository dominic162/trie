/*Find shortest unique prefix for every word in a given list | Set 1 (Using Trie)
Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another.

Examples:

Input: arr[] = {"zebra", "dog", "duck", "dove"}
Output: dog, dov, du, z
Explanation: dog => dog
             dove = dov 
             duck = du
             z   => zebra 

Input: arr[] =  {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
Output: geeksf, geeksg, geeksq}*/

#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		bool terminal;
		int freq;
		map<char,node*> mp1;
		node(){
			terminal=false;
			freq=1;
		}
};

class trie{
	private:
		node *root;
	public:
		trie(){
			root=new node('\0');
		}

		void insert(string s){
			node* temp=root;
			for(i=0;s[i]!='\0';i++){
				if(temp->mp1.count(s[i])){
					temp->mp1[s[i]]++;
					temp=temp->mp1[s[i]];
				}
				else{
					temp->mp1[s[i]]=new node();
				}
			}

			return ;
		}


};

int main(){
	return 0;
}