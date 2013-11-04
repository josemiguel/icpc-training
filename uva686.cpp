#include<iostream>
#include<set>
#include<vector>
#include<sstream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;
#define MAX 32800
vector<bool> b(MAX+4,true);
vector<int> p;
void criba(){
	b[0] = b[1] = false;
	for(int i = 2; i <= MAX; i++){
		if (b[i]){
			p.push_back(i);
			for(int j = i*i; j <= MAX; j+=i) b[j] = false;
		}
	}
}

int main(){

	int n;
	criba();
	while(cin>>n && n){
		int res = 0;
		for(int i = 0; p[i] <= n; i++){
			for(int j = i; p[j] <= n; j++){
				if (p[j] + p[i] == n) { res++;break;}
			}
		}
		cout<<res<<endl;
	}

	return 0;
}

