#include<iostream>
#include<cstdio>
using namespace std;
typedef long long Int;
int main(){
	Int a,b,MOD;
	cin >> a >> b >> MOD;
	if(MOD-b <= 0) cout<<2<<endl;
	else{
   		Int MOD2= 1000000000LL , we;
   		MOD2 %= MOD;
   		Int x = min( MOD - 1, a );
   		for(Int i = 0; i <= x; i++){        
       		we = ( ( i % MOD ) * ( MOD2 ) ) % MOD;    
        	if(we > 0 && we < MOD - b){
        	   	printf("1 %09lld\n",i);
        	   	return 0;
       		}	
   		}
	    cout<<2<<endl;
    
	}
	return 0;
}
