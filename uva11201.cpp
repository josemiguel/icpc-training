#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long Int;


int P[] = {1253,142,468,586,1368,69,101,70,625,44,0,497,315,671,868,251,88,687,798,463,393,90,2,22,90,52};

string a = "aeiou";
string b = "bcdfghjklmnpqrstvwxyz";
Int SBC[10][27];
int nSBC[10][27];
int usd[30];
Int F(int pos, int c){
	if (pos == 8) return 0;
	string tmp = b;
	if (pos % 2 == 0) tmp = a;
	Int res = 0;
	for(int i = 0; i < tmp.size(); i++){
		int idx = tmp[i] - 'a';
		if (usd[idx] == 2) continue;
		usd[idx]++;
		Int x = P[idx]*pos + F(pos+1,c);
		SBC[c][pos] += x;
		nSBC[c][pos]++;
		usd[idx]--;
	}
	return res;
}

int main(){
	for(int c = 0; c < 27; c++) F(2,c);
	for(int i = 2; i < 8; i++){
		for(int j = 0; j < b.size(); j++){
			SBC[i][b[i]-'a'] += P[b[i]-'a'];
		}
	}


	int T;
	scanf("%d",&T);
	while( T-- ){
		char cad[10];
		scanf("%s",cad);
		Int we = 0;
		int N = strlen(cad);
		for(int i = 0; i < N; i++) we += (i+1)*P[cad[i]-'a'];
		Int total = SBC[N][cad[0]-'a'];
		long double X = we;
		X *= nSBC[N][cad[0]-'a'];
		if (X < total) puts("below");
		else puts("above or equal");
	}

	return 0;
}
