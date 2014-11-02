#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	int runs;
	scanf("%d", &runs);
	while(runs--){
		int r,n;
		scanf("%d%d", &r, &n);
		int res = -1;
		for (int i = 1; n > 0; i++){
			n -= i;
			if (n % i == 0)	res++;
		}
		
		printf("%d %d\n", r, res);
	}
}
