#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>


using namespace std;
struct Trie{
	int words,prefixes,nodes;
	Trie *edges[58];
	
	Trie(){
		words = prefixes = 0;
		nodes = 1; // root -> ""
		for(int i = 0; i < 58; i++) edges[i] = NULL;
	}
	
	void add(string word){
		int len = word.size(),k;
		Trie *tmp = this;
		for(int i = 0; i < len; i++){
			tmp->prefixes++;
			k = word[i] - '0';
			if (!tmp->edges[k]){
				tmp->edges[k] = new Trie();
				this->nodes++;
			}
			tmp = tmp->edges[k];
		}	
		tmp->words++;					
	}

	int countWords(string word){
		int len = word.size(),k;
		Trie *tmp = this;
		for(int i= 0; i < len; i++){
			k = word[i] - '0';
			if (!tmp->edges[k]) return 0;
			tmp = tmp->edges[k];
		}
		return tmp->words;
	}

	int countPrefixes(string prefix){
		int len = prefix.size(),k;
		Trie *tmp = this;
		for(int i= 0; i < len; i++){
			k = prefix[i] - '0';
			if (!tmp->edges[k]) return 0;
			tmp = tmp->edges[k];
		}
		return tmp->prefixes;
	}
	void _printAll(Trie* v, string s){
		if(v->words > 0) cout<<s<<endl;
		for(int k = 0; k < 58; k++)
			if(v->edges[k]) _printAll(v->edges[k],s+char(k+'0'));
	}

	void printAll(){_printAll(this,"");}
	
	Trie *find(string word){
		int len = word.size(),k;
		Trie *tmp = this;
		for(int i= 0; i < len; i++){
			k = word[i] - '0';
			if (!tmp->edges[k]) return NULL;
			tmp = tmp->edges[k];
		}
		return tmp;
	}
	
	bool exist(string word){//match exactly
		return find(word)!=NULL;
	}
	
};


int main(){
	int r = 1;
	while(1){
		string s;
		Trie *trie = new Trie();		
		if (!(cin>>s)) break;
		vector<string> v;
		v.push_back(s);
		trie->add(s);
		while(cin>>s && s!="9"){
			v.push_back(s);	
			trie->add(s);
		}
		bool b = false;
		for(int i = 0; i < v.size(); i++){
			if (trie->countPrefixes(v[i])>0) {b=true;break;}
		}
		if (!b){
			printf("Set %d is immediately decodable\n",r);
		}else{
			printf("Set %d is not immediately decodable\n",r);
		}
		r++;
	}	
	return 0;
}
