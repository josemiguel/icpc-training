#include<iostream>
#include<string>
#include<cstring>

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
			k = word[i] - 'A';
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
			k = word[i] - 'A';
			if (!tmp->edges[k]) return 0;
			tmp = tmp->edges[k];
		}
		return tmp->words;
	}

	int countPrefixes(string prefix){
		int len = prefix.size(),k;
		Trie *tmp = this;
		for(int i= 0; i < len; i++){
			k = prefix[i] - 'A';
			if (!tmp->edges[k]) return 0;
			tmp = tmp->edges[k];
		}
		return tmp->prefixes;
	}
	void _printAll(Trie* v, string s){
		if(v->words > 0) cout<<s<<endl;
		for(int k = 0; k < 58; k++)
			if(v->edges[k]) _printAll(v->edges[k],s+char(k+'A'));
	}

	void printAll(){_printAll(this,"");}
	
	Trie *find(string word){
		int len = word.size(),k;
		Trie *tmp = this;
		for(int i= 0; i < len; i++){
			k = word[i] - 'A';
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

	Trie *trie = new Trie();	
	string dic[] = {"trie","tree","also","assoc","all","algo"};
	for(int i = 0; i < 6; i++){
		trie->add(dic[i]);
	}
	trie->printAll();	
	cout<<trie->exist("tree")<<endl;
	return 0;
}
