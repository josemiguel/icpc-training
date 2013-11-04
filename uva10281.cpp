#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>


using namespace std;

int main(){
	double distance = 0.0;
	int h,m,s,hf,mf,sf,fspeed,speed,iseg;
	char in[80];
	bool b = false, c = false;
	while(fgets(in,sizeof(in),stdin)){
		int q = sscanf(in,"%d:%d:%d %d",&h,&m,&s,&speed);
		if (q == 3){
			if (b){
				int fseg = h*60*60 + m * 60 + s;
				distance += ((fseg - iseg)*(double)fspeed)/3600.0;
				printf("%02d:%02d:%02d %.2lf km\n",h,m,s,distance);
				iseg = fseg;
				c = true;
			}else{
				printf("%02d:%02d:%02d %.2lf km\n",h,m,s,0.0);
			}
		}else if (q == 4){
			if (c){
				distance += ((h * 60 * 60 + m * 60 + s - iseg)*(double)fspeed)/3600.0;
			}
			b= true;
			iseg = h*60*60 + m *60 + s;
			fspeed = speed;
		}
	}
	return 0;
}
