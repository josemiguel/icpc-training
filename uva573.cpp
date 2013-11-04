#include<cstdio>
using namespace std;

int main(){
	int H,U,D,F;
	while(scanf("%d%d%d%d",&H,&U,&D,&F) && H+U+D+F){
		F *= U;	H *= 100; U *= 100; D *= 100;
		int h = 0, days = 0;
		while(true){
			h += U;	days++;
			if (h > H) {printf("success on day %d\n",days); break;}
			h -= D;
			if (h < 0) {printf("failure on day %d\n",days);break;}
			U -= U <= 0 ? 0 : F;
		}
	}
	return 0;
}

