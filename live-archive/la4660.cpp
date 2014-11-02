#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int convert(int val, int base){
	int s = 0;
	int factor=1;
	while(val){
		if (val%10 >= base) return -1;
		s += (val%10)*factor;
		val/=10;
		factor*=base;
	}
	return s;
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int a,b;
		scanf("%d%d",&a,&b);
		int sa=-1,sb=-1;
		for(int i = 2;i<=10;i++){
			if (sa==-1) sa=convert(a,i);
			if (sb==-1) sb=convert(b,i);
			if (sa>=0 && sb>=0){
				printf("%d\n",sa+sb);
				break;					
			}
		}
	}		
}

