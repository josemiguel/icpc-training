#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const double PI = acos(-1);

int main(){
	int n;double A;int cas = 1;
	while(cin>>n>>A && n >=3){
		double alpha = (2.0*PI) / n;
		
		double comun = (2.0*A)/(sin(alpha)*n);

		double res1 = comun*PI  - A;
		double res2 = A - (PI*A*cos(PI/n))/(sin(PI/n)*n);

		
		printf("Case %d: %.5lf %.5lf\n",cas++,res1,res2);
	}
	return 0;
}
