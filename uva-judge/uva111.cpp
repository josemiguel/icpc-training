#include<iostream>
#include<string>
#include<sstream>
#include<cstring>
#include<cmath>
using namespace std;
#define MAX 100
int m[MAX][MAX];
int a[MAX], r[MAX];

int solve(int n){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if (a[i] == r[j]){
				m[i][j] = 1 + m[i-1][j-1]; 
			}else{
				m[i][j] = max(m[i-1][j], m[i][j-1]);
			}
			
		}
	}
	return m[n][n];
}

int main(){
	int n;
	cin>>n;
	memset(r,0,sizeof(r));
	for(int i = 1; i <= n; i++) {
		int tmp;
		cin>>tmp;
		r[tmp] = i;
	}
	cin.ignore();
	string s;
	bool b;
	while(getline(cin,s) && s!=""){
		istringstream is(s);
		int k = 0;		
		memset(a,0,sizeof(a));			
		memset(m,0,sizeof(m));
		for(int j = 1; j <= n; j++){
			int tmp;
			is>>tmp;
			a[tmp] = j;
		}
		cout<<solve(n)<<endl;
	}
	return 0;
}
