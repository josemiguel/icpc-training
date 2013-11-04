#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[1<<17],n,m,a[5][5];

bool can(int mask, int i, int j){
	return ((mask>>(i*m+j)) & 1);
}

int coge_der(int x, int y, int cant,int &mask){
	int res = 0;
	for(int i = y, cont = 0; cont < cant && i < m && !can(mask,x,i); i++, cont++) {
		res = res*10 + a[x][i];
		mask |= (1<<(x*m+i));
	}
	return res;
}

int coge_aba(int x, int y, int cant, int &mask){
	int res = 0;
	for(int i = x, cont = 0; cont < cant && i < n && !can(mask,i,y); i++, cont++) {
		res = res*10 + a[i][y];
		mask |= (1<<(i*m+y));
	}
	return res;
}

void p(int mask){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if (can(mask,i,j)) cout<<"1";
			else cout<<"0";
		}
		cout<<endl;
	}
}

int F(int mask){
	//p(mask);
	if (mask+1 == (1<<(n*m))) return 0;
	if (dp[mask] != -1) return dp[mask];
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if (can(mask,i,j)) continue;
			for(int c = 3; c <= 4; c++){
				p(mask);
				int na_mask = mask, tmpa = coge_der(i,j,c,na_mask);
				cout<<tmpa<<endl;
				p(na_mask);
				cout<<endl;
				int A = tmpa + F(na_mask);
				//int B = coge_aba(i,j,c,mask) + F(mask | (1<<(i*m+j)));
				res = max(res,A);
			}
		}
	}
	return dp[mask] = res;
	
}

int main(){
	cin>>n>>m;
	memset(dp,-1,sizeof dp);
 	for(int i = 0; i < n; i++){
 		for(int j = 0; j < m; j++){
 			cin>>a[i][j];
 		}
 	}
 	cout<<F(0)<<endl;
	return 0;
}
