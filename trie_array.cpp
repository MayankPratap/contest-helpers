/*
Insertion of N strings in a trie
*/

#include<bits/stdc++.h>
using namespace std;

struct trie {
	int next[26];
	int flag;
}node[10000];

int allocated;

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
