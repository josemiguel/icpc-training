#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int row[55];
bool square(int xx){
	int x = (int) sqrt(xx);
	return x*x == xx;
}

int dfs(int u){
	int res = 0;
	bool base = false;
	for(int i = 0; i < n ; i++){
		if (row[i] == 0 || square(u + row[i])){
			row[i] = u;
			res = max( res, 1 + dfs(u+1) );
		}
	}
	return res;
}
int a[55];
int main(){
	int runs;
	cin >> runs;
	a[1] = 1;
	a[2] = 3;
	a[3] = 7;
	a[4] = 11;
	a[5] = 17;
	a[6] = 23;
	a[7] = 31;
	a[8] = 39;
	a[9] = 49;
	a[10] = 59;
	a[11] = 71;
	a[12] = 83;
	a[13] = 97;
	a[14] = 111;
	a[15] = 127;
	a[16] = 143;
	a[17] = 161;
	a[18] = 179;
	a[19] = 199;
	a[20] = 219;
	a[21] = 241;
	a[22] = 263;
	a[23] = 287;
	a[24] = 311;
	a[25] = 337;
	a[26] = 363;
	a[27] = 391;
	a[28] = 419;
	a[29] = 449;
	a[30] = 479;
	a[31] = 511;
	a[32] = 543;
	a[33] = 577;
	a[34] = 611;
	a[35] = 647;
	a[36] = 683;
	a[37] = 721;
	a[38] = 759;
	a[39] = 799;
	a[40] = 839;
	a[41] = 881;
	a[42] = 923;
	a[43] = 967;
	a[44] = 1011;
	a[45] = 1057;
	a[46] = 1103;
	a[47] = 1151;
	a[48] = 1199;
	a[49] = 1249;
	a[50] = 1299;


	while( runs-- ){
		cin >> n;
		cout << a[n] <<endl;
	}
	return 0;
}
