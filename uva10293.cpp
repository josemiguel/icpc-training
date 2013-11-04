#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#define MAX 85
int H[MAX];
using namespace std;
int main(){
	char c;

	while(1){
		memset(H,0,sizeof H);
		string T = "";		
		while((c = getchar()) && c != '#'){
			if (c == -1) goto sale;
			char a = 0;
			if (c == '-' && (a = getchar()) == '\n') continue;
			if (a) T+=a;			
			if (c == '-' || c == '\'') continue;
			if (!isalpha(c)) c = ' ';
			T += c;

		}
		istringstream is(T);
		
		string tok;
		while(is>>tok) H[tok.size()]++;
		for(int i = 0; i < MAX; i++){
			if (H[i]) cout<<i<<" "<<H[i]<<endl;		
		}
		cout<<endl;
	}
	sale: ;
	return 0;
}
