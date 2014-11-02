#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
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
			k = word[i] - 'a';
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
			k = word[i] - 'a';
			if (!tmp->edges[k]) return 0;
			tmp = tmp->edges[k];
		}
		return tmp->words;
	}

	int countPrefixes(string prefix){
		int len = prefix.size(),k;
		Trie *tmp = this;
		for(int i= 0; i < len; i++){
			k = prefix[i] - 'a';
			if (!tmp->edges[k]) return 0;
			tmp = tmp->edges[k];
		}
		return tmp->prefixes;
	}
	void _printAll(Trie* v, string s){
		if(v->words > 0) cout<<s<<endl;
		for(int k = 0; k < 58; k++)
			if(v->edges[k]) _printAll(v->edges[k],s+char(k+'a'));
	}

	void printAll(){_printAll(this,"");}
	
	Trie *find(string word){
		int len = word.size(),k;
		Trie *tmp = this;
		for(int i= 0; i < len; i++){
			k = word[i] - 'a';
			if (!tmp->edges[k]) return NULL;
			tmp = tmp->edges[k];
		}
		if (tmp->words > 0)
			return tmp;
		return NULL;
	}
	
	bool exist(string word){//match exactly
		return find(word)!=NULL;
	}
	string misspelling(string s){
		if (exist(s)) return "1";
		for(int j = 0; j < s.size(); j++){ 
			for(int i = 0; i < 26; i++){
				char tmp = s[j];
				s[j] = (char)(i+'a');
				if (exist(s)) return s;
				s[j] = tmp;
			}
		}
		Trie *tmp = this;
		int k = 0, kk = 0;
		bool b = false;
		string miss = "";

		for(int i = 0; i < s.size(); i++){
			bool salto = false;
			if (!tmp->edges[s[i]-'a']){
				k++;
				if (k > 1) {b = true;break;}
				bool bb = false;
				for(int j = 0; j < 27; j++){
					if (tmp->edges[j] && tmp->edges[j]->edges[s[i]-'a']){
						salto = true;
						bb = true;
						break;
					}
				}
				if (!bb){
					kk++;
					if (kk > 1){b = true; break;}
					continue;
				}
							
			}
			if (salto){
				tmp = tmp->edges[s[i]-'a'];
				miss += s[i];
			}
		}
		if (!b) return miss;
		return "0";

	}
};


int main(){
	int r,n;
	string s;	
	cin>>r;
	Trie *trie = new Trie();
	while(r--){
		cin>>s;
		trie->add(s);
	}
	
	cin>>n;
	while(n--){
		cin>>s;
		string res = trie->misspelling(s);
		if (res != "1" && res != "0"){
			cout<<s<<" is a misspelling of "<<res<<endl;
		}else{
			if (res == "0")
				cout<<s<<" is unknown"<<endl;
			else
				cout<<s<<" is correct"<<endl;
		}
	}
	return 0;
}
