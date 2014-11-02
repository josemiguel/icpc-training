#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	double m1,m2,m3;

	while(scanf("%lf %lf %lf",&m1,&m2,&m3)!=-1){
		double o = (m1+m2+m3)/2;
		if (o*(o-m1)*(o-m2)*(o-m3) <= 0){
			printf("-1.000\n");
		}else{
			printf("%.3lf\n",(4*sqrt(o*(o-m1)*(o-m2)*(o-m3)))/3);
		}
		
	}
	return 0;
}
