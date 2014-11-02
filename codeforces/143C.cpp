#include<iostream>
#include<algorithm>
using namespace std;
typedef long long Int;


int F(int N,int M){
    int m, n, res;
    m = M < N ? M : N;
    n = M + N - m;
    if(m == 1)
        res = n;
    else if(m == 2)
        res = 4 * (n / 4) + (n % 4 <= 2 ? 2 * (n % 4) : 4);
    else
        res = (m * n + 1) / 2;
	return res;
}

int main(){
	int N, M;
  	cin >> N >> M;
	cout << F( N,M) << endl;
}
