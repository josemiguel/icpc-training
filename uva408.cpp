#include<iostream>
#include<cstdio>
#include<numeric>
#include<cstring>
using namespace std;

bool F(int s, int m){
	bool h[m];
	memset(h,0,sizeof h);
	int ant = 0;
	h[0] = true;
	while(1){
		ant = (ant + s) % m;
		if (h[ant]) break;
		h[ant] = true;
		
	}
	return accumulate(h,h+m,0) == m;
}

int main(){
	int step,mod;
	while(cin>>step>>mod){
		if (F(step,mod)) printf("%10d%10d    Good Choice\n\n",step,mod);
		else			 printf("%10d%10d    Bad Choice\n\n",step,mod);
	}
	return 0;
}
