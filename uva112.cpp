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
int  sum;
bool res;
const int INF = 1<<30;
int getRoot(string s, int &pos){
	int r = 0;
	bool neg = false, vacio = true;
	for(int i=1; isdigit(s[i]) || s[i] == '-';i++, pos++){
		vacio = false;	
		if (s[i] =='-'){
			neg = true;			
		}else
			r = r*10 + s[i] - '0';

	}
	if (neg) r = -r;
	if (vacio) r = INF;
	pos++;
	return r;
}

string sacaHijo(string s,int &i){
	string hijo = "";
	int p = 0;
	do{
		if (s[i]=='(') p++;
		else if (s[i]==')') p--;
		hijo += s[i];
		i++;
	}while(p);
	return hijo;
}

bool hijos(string s, int suma){
	int pos = 0;
	int root = getRoot(s,pos);
	if (root != INF){
		suma += root;
		string izq = sacaHijo(s,pos);
		string der = sacaHijo(s,pos);
		if (izq == "()" && der =="()"){
			res |= (suma == sum);
		}else{
			if (izq != "()") hijos(izq,suma);
			if (der != "()") hijos(der,suma);
		}
	}
	
}


int main(){
	
	while(scanf("%d",&sum) != -1){

		char c; int p = 0;
		string s = "";
		while(cin>>c){
			if (c=='(') p++;
			else if (c==')') p--;
			s +=c;
			if (!p) break;
		}
		res = false;
		hijos(s,0);
		if (res){
			puts("yes");
		}else{
			puts("no");
		}
	}
	
	
	return 0;
}
