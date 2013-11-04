#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<queue>
#include<cstring>
using namespace std ;
char dic[20][25150][20];
int pai[25150];
int ndic[20];
bool F(char *a, char *b){
	int dif =0;
	for(int i = 0; a[i]; i++){
		if (a[i]^b[i] ) dif++;
		if (dif == 2) return false;
	}
	return true;
}
int len;
int find(char *s){
	for(int i = 0; i < ndic[len]; i++){
		if (!strcmp(dic[len][i],s)) return i;
	}
	return -1;
}
void track( int fin ){
	if ( fin == -2 ) return;
	track( pai[fin]);
	puts( dic[len][fin] );
}

int main(){
	char s[20];
	while(scanf("%s",s)){
		int len = strlen(s);
		cin.ignore();
		if (cin.peek() == '\n') break;
		strcpy(dic[len][ ndic[len]++ ], s );
	}
	char a[20],b[20];
	bool r = false;
	while( scanf("%s %s",a,b) != -1 ){
		if ( r ) putchar( 10 );
		r = true;
		len = strlen(a);
		int s = find(a), e = find(b);
		if ( s == -1 || e == -1 || len != strlen(b)){
			puts("No solution.");
			continue;
		}
		memset(pai,-1,sizeof pai);
		queue<int> Q;
		Q.push(s); 
		pai[s] = -2;
		while( !Q.empty() ){
			int v = Q.front(); Q.pop();
			for(int i = 0; i < ndic[len]; i++){
				if (pai[i] != -1) continue;
				if (F(dic[len][v],dic[len][i])){
					pai[i] = v;
					if ( i == e ) goto hell;
					Q.push(i);
				}
			}
		}
		hell:
		int pos = pai[e];
		if ( pos == -1 ) puts("No solution.");
		else{
			track(e);
		}
		
	}

	return 0;
}
