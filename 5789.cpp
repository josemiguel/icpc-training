#include<iostream>
#include<cstdio>
using namespace std ;

int L[ 100005 ];
int R[ 100005 ];

void print( int k ){
	if ( k == -1 ) printf("*");
	else printf("%d",k);
}

int main(){
	int n , q;
	while( scanf("%d %d",&n,&q) && n+q ){
		for( int i = 1; i < n; i++) {
			L[i] = i - 1;
			R[i] = i + 1;
		}

		L[1] = -1, R[n] = -1;
		while(q--){
			int l ,r ;
			scanf("%d%d",&l,&r );
			print(L[l]);
			putchar(32);
			print(R[r]);
			putchar(10);
			int ll = L[l];
			int rr = R[r];
			
			R[ll] = rr, L[rr] = ll;
		}
		printf("-\n");

	}

	return 0;
}
