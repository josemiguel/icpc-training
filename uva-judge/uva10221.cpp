#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const double PI = acos(-1);
double f(int aa, char c){

/*	if (c == 'm'){
		if (aa/60 >= 180){
			aa -= 180;;
		}
	}else{
		if (aa >= 180){
			aa -= 180;
		}
	}*/

	double res = aa;
	if ( c == 'm'){
		res = aa / 60 + (aa % 60) / 60.0;
	}
	
	return (res*PI) / 180;
}
int main(){
	int s, a;
	char cad[100];
	while(cin>>s>>a>>cad){
		double ang = f(a,cad[0]);
		double R = 6440 + s;
		
		double res1 = (R * ang);
		if (a >= 180) res1 = R*(2*PI-ang);
		double res2 = 2 * R * sin(ang / 2.0);
		printf("%.6lf %.6lf\n",res1,res2);
	}
	
	return 0;
}
