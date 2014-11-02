#include<cstdio>
#include<iostream>
using namespace std;

double area(double x1, double y1, double x2,double y2, double x3, double y3){

    return (x2*y3 + x1*y2 + y1*x3 - x2*y1 - x3*y2 - y3*x1) / 2;
    
}

int main(){
	int n;
	while(scanf("%d",&n) && n){
		double res = 0.0;
		for(int i = 0; i < n; i++){
			double x1,x2,y1,y2,x3,y3,x4,y4;
			scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
			
			x3 = x1;
			y3 = y2;
			
			x4 = x2;
			y4 = y1;
			
			res += area(x1,y1,x2,y2,x3,y3) + area(x4,y4,x2,y2,x3,y3);
		}
		cout<<res<<endl;
	}
	
	return 0;
}
