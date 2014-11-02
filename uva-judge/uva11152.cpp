#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	double s,a,b,c,v,acs,acb,at,y;
	while(scanf("%lf%lf%lf",&a,&b,&c)!=-1){
		s = (a+b+c)/2;
		at = sqrt(s*(s-a)*(s-b)*(s-c));
		acs = 3.141592653589793*pow((at/s),2);
		v = at-acs;
		acb = 3.141592653589793*pow(((a*b*c)/(4*at)),2);
		y = acb-(v+acs);
		printf("%.4lf %.4lf %.4lf\n",y,v,acs);
	}
	return 0;
}

