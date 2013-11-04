#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<sstream>
#include<cstring>
#define count(x) __builtin_popcount((x))
using namespace std;
int buck[300];
int demo[105];
int tab[105][5];
void init(){
	buck['r'] = 0; buck['o'] = 1; buck['y'] = 2; buck['g'] = 3; buck['b'] = 4;
	buck['P'] = 1; buck['G'] = 2; buck['S'] = 3; buck['A'] = 4; buck['N'] = 5;	
}
int hash(char a, char b){
	return buck[a]*5 + buck[b];
}

int main(){
	init();
	while(true){
		bool exit = false, next = false;
		char s[300];
		int n = 0;
		while(fgets(s,sizeof s,stdin)){
			if (s[0] == 'e') break;
			if (s[0] == '#') return 0;
			char *p = strtok (s,",");
			int i = 0;
			while (p){
				tab[n][i++] = hash(p[0],p[2]);
				p = strtok (NULL, ",");
			}
			n++;
		}
		
		for(int i = 0; i < n; i++){
			demo[i] = 0; sort(tab[i], tab[i] + 5);
		}
		
		for(int k = 0; k < 5; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if (i == j) continue;
					if (tab[i][k] == tab[j][k])	demo[i]++;
				}
			}
		}
		int hi = 0, res = 0;
		for(int i = 0; i < n; i++){
			//cout<<demo[i]<<" ";
			if (demo[i] > hi) {hi = demo[i]; res = i;}
		}
		//cout<<endl;
		printf("%d\n",res+1);
	}
	return 0;
}

