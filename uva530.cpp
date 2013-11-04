#include <cstdio>
using namespace std;
typedef long double ll;

#define MAX 1005
ll C[MAX+5][MAX+5];

int main(){
	for(int i = 0; i < MAX; i++) C[i][i] = C[i][0] = 1;
	for(int i = 1; i < MAX; i++) for(int j = 1; j < i; j++)	C[i][j] = C[i-1][j-1] + C[i-1][j];
	
	for(int n,k ; scanf("%d%d",&n,&k) && n ; printf("%.Lf\n",C[n][k]));
	
	return 0;
}
