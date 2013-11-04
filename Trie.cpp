#include<iostream>
#include<string>
#include<cstring>

using namespace std;

struct Trie{
	int words;
	int prefixes;
	int nodes;
	Trie *edges[58];
	Trie(){
		words = 0;
		prefixes = 0;
		nodes = 1;
		for(int i = 0; i < 58; i++) edges[i] = NULL;
	}
	
	void add(char *word){
		int len = strlen(word),k;
		Trie *tmp = this;
		for(int i = 0; i < len; i++){
			tmp->prefixes++;
			//k = word[i] - 'A'; uppercase
			k = word[i] - 'A';
			if (!tmp->edges[k]){
				tmp->edges[k] = new Trie();
				this->nodes++;
			}
			tmp = tmp->edges[k];
		}
		tmp->words++;
	}
	void add(string word){
		int len = word.size(),k;
		Trie *tmp = this;
		for(int i = 0; i < len; i++){
			tmp->prefixes++;
			//k = word[i] - 'A'; uppercase
			k = word[i] - 'A';
			if (!tmp->edges[k]){
				tmp->edges[k] = new Trie();
				this->nodes++;
			}
			tmp = tmp->edges[k];
		}	
		tmp->words++;					
	}
	int countWords(char *word){
		int len = strlen(word),k;
		Trie *tmp = this;
		for(int i = 0; i < len; i++){
			k = word[i] - 'A';
			if (!tmp->edges[k])	return 0;
			tmp = tmp->edges[k];
		}
		return tmp->words;
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

	int countPrefixes(char *prefix){
		int len = strlen(prefix),k;
		Trie *tmp = this;
		for(int i = 0; i < len; i++){
			k = prefix[i] - 'A';
			if (!tmp->edges[k])	return 0;
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
	
	void printAll(Trie* vertex, string s){
	
	
		if(vertex->words > 0) cout<<s<<endl;
		for(int k = 0; k < 58; k++)
		    if(vertex->edges[k]) printAll(vertex->edges[k],s+char(k+'A'));
	}
	
	void printAll(){
		printAll(this,"");
	}
	
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
	
};

int main(){

	Trie *trie = new Trie();	
	string dic[] = {"tree","trie","algo","assoc","all","also"};
	for(int i = 0; i < 6; i++){
		trie->add(dic[i]);
		cout<<trie->nodes<<endl;
		trie->printAll();
	}
	cout<<trie->find("treea")<<endl;
	return 0;
}
