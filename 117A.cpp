#include<iostream>
using namespace std;
int n,m;
int F(int ini,int fin){
    if(ini == fin) return 0;
    if(ini > fin) return 2*(m-1) - ini + fin;
    return fin - ini;
}
int main(){

	cin>>n>>m;

	for(int i = 0; i < n; i++) {
		int s,f,t;
		cin>>s>>f>>t;
		int T = 2*(m-1);
		if (s == f){ cout<<t<<endl;
			continue;
		}
		int pos= t % T;
		int res = 0;
		
		if(F(pos,s - 1) < F(pos,T-s+1)){
		    res = F(pos,s-1);
		    pos = s - 1;
		}
		else{
		    res = F(pos,T - s + 1);
		    pos = T - s + 1;
		}
		
		res += min(F(pos,f - 1),F(pos,T - f + 1));; 
		res += t;
		cout<<res<<endl;
						
	}


	return 0;
}
/*
9
1
0
7
10
7
5*/
