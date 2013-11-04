#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ALPH_SIZE = 58;  // tamaño del alfabeto

struct Node{
    int words;              // número de palabras que terminan en el nodo
    int prefixes;           // número de palabras que tienen como prefijo el camino al nodo
    vector<Node*> links;    // enlaces a los nodos hijos
    
    Node();
};

Node::Node(){
    words = prefixes = 0;
    links.resize(ALPH_SIZE,NULL);
}

class Trie{
    public :
    
    Trie();
    
    bool contains(const string& s) const;
    int nodeCount() const;
    int countWords(const string& s) const;
    int countPrefixes(const string& s) const;
    int countRepeated() const;
    void printAllWords() const;
    
    void insert(const string s);
    
    private :
    
    Node* myRoot;       // raíz del trie
    int myCount;        // # nodos del trie
    
    int countRepeated(Node* t) const;
    void printAllWords(const Node* t, const string& s) const;
};

Trie::Trie(){
    myRoot = new Node();
    myCount = 1;
}

bool Trie::contains(const string& s) const{
    Node* t = myRoot;
    int len = s.size();
    
    for(int k=0;k<len;++k){
        if(t==NULL) return false;
        t = t->links[s[k]];
    }
    
    return (t->words > 0);
}

int Trie::nodeCount() const{
    return myCount;
}

int Trie::countWords(const string& s) const{
    int len = s.size();
    Node* t = myRoot;
    
    for(int k=0;k<len;++k){
        if(t->links[s[k]-'A']==NULL) return 0;
        t = t->links[s[k]-'A'];
    }
    
    return t->words;
}

int Trie::countPrefixes(const string& s) const{
    int len = s.size();
    Node* t = myRoot;
    
    for(int k=0;k<len;++k){
        if(t->links[s[k]-'A']==NULL) return 0;
        t = t->links[s[k]-'A'];
    }
    
    return t->prefixes;
}

void Trie::printAllWords(const Node* t, const string& s) const{
    if(t->words > 0) cout<<s<<endl;
    
    for(int k=0;k<ALPH_SIZE;++k)
        if(t->links[k]) printAllWords(t->links[k],s+char(k+'A'));
}

void Trie::printAllWords() const{
    printAllWords(myRoot,"");
}

void Trie::insert(const string s){
    int len = s.size();
    Node* t = myRoot;
    
    for(int k=0;k<len;++k){
        if(t->links[s[k]-'A']==NULL){
            t->links[s[k]-'A'] = new Node();
            ++myCount;
        }
        t = t->links[s[k]-'A'];
        ++(t->prefixes);
    }
    
    ++(t->words);
}

int Trie::countRepeated(Node* t) const{
    int aux = 0;
    
    if((t->words)>1) ++aux;
    
    for(int k=0;k<ALPH_SIZE;++k)
        if(t->links[k]) aux += countRepeated(t->links[k]);
    
    return aux;
}

int Trie::countRepeated() const{
    return countRepeated(myRoot);
}

string test[] = {"tree","trie","algo","assoc","all","also"};

int main(){
    Trie* myTrie;
    myTrie = new Trie();
    
    for(int i=0;i<6;++i){
        myTrie->insert(test[i]);
        cout<<myTrie->nodeCount()<<endl;
        myTrie->printAllWords();
        cout<<endl;
    }
    
    delete myTrie;
        
    return 0;   
}
