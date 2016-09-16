/*
Insertion of N strings in a trie
Deletion Of String in a trie.
*/

#include<bits/stdc++.h>
using namespace std;

struct trie {
	int next[26];
	int flag;
	int prev;
}node[100000];

int allocated;


void del(string s){

   int current=0,cur;

   for(int i=0;i<s.length();++i){

       current=node[current].next[s[i]-'0'];
       if(i==s.length()-1){

          cur=current;
          break;
       }

   }

   while(cur!=0){

      if(node[cur].next[0]==0 && node[cur].next[1]==0){

          int prev=node[cur].prev;

          if(node[prev].next[0]==cur){
             
              node[prev].next[0]=0;
           
          }
          else if(node[prev].next[1]==cur){

              node[prev].next[1]=0;

          }        

          cur=prev;
  
      }

      else{

        break;
      }

   }
} 

void insert(string s) {
	int current = 0;  //so root node is node[0]
	for(int i = 0; i < s.length(); i++) {
		if(node[current].next[s[i]-'a'] == 0) { //no link --> so allocate it
			node[current].next[s[i]-'a'] = allocated;
			current = allocated;
			allocated++;
		}
		else current = node[current].next[s[i]-'a'];  //already present --> so just update current

		//setting flag for last character of string
		if(i == s.length()-1) {
			node[current].flag = 1;
		}
	}
}

int main() {
	string s;
	int n;
	cin>>n;  //input number of strings

	allocated = 1; //allocated to be started from 1

	memset(node, 0, sizeof node); //initialize node to 0 (each values in next[] array and flag will be 0 for each node)

	for(int i=0;i<n;i++) {
		cin>>s; //input string one by one
		insert(s); //insert the string in trie and mark the end of this string by setting flag to 1 for last character's node
	}
	return 0;
}
