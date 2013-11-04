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
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define INF 1<<30

int ternarySearch(int f, int  left,int  right,int  absolutePrecision){

    if ((right - left) < absolutePrecision)
        return (left + right)/2;
 
    int leftThird = (2*left + right)/3;
    int rightThird = (left + 2*right)/3;
 
    if (f*(leftThird) < f*(rightThird))
        return ternarySearch(f, leftThird, right, absolutePrecision);
 
    return ternarySearch(f, left, rightThird, absolutePrecision);
    
}

int main(){
	int runs;
	scanf("%d",&runs);
	int a,b,c;
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d%d%d",&a,&b,&c);
		cout<<ternarySearch(a,b,c,10)<<endl;
	}
	
	return 0;
}
