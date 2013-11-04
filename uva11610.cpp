#include <algorithm>
#include <cstdio>
using namespace std;
int bit[2][78500],n,p[999998],pot[]={1,10,100,1000,10000,100000,1000000,10000000};
struct par{
	int x,y;
	par(){}
	par(int x,int y):x(x),y(y){}
	bool operator < (const par &a)const{return x < a.x;}
}a[78500];

int get(int x, int t){	int res = 0; for(; x ; x -= x & -x) res += bit[t][x];	return res;}
void update(int x, int v, int t){for(; x <= n; x += x & -x) bit[t][x] += v;}

void go(){
	p[0] = p[1] = 1;
	for(int i = 4; i < 999998; i+=2) p[i] = 2;
	for(int i = 3; i*i < 999998; i+=2){
		if (p[i]) continue;
		for(int j = i*i; j < 999998; j+=(i<<1)) p[j] = i;
	}
	for(int i = 0; i < 999998; i++){
		if (p[i]) continue;
		int k = i,tmp,rev = 0, ceros = 7,cnt=0;
		while(k){
			rev = rev*10 + k%10; k /= 10;
			ceros--;
		}
		int factores = 1 + ceros*2;
		tmp = rev;	while(p[tmp])	tmp /= p[tmp],factores++;
		a[n++] = (par(rev*pot[ceros],factores));
		
	}
	sort(a,a+n);
	for(int i = 0; i < n; i++){
		update(i+1,a[i].y,1);
		update(i+1,1,0);
	}
}

int real(int idx){
	int lo = 1, hi = n;
	while(lo < hi){
		int mid = (lo+hi)>>1;
		if ( get(mid,0) <  idx ) lo = mid+1;
		else hi = mid;
	}
	return lo;
}

int indice(int val){
	int lo = 0, hi = n;
	while(lo <= hi){
		int mid = (lo+hi)>>1;
		if ( a[mid].x == val ) return mid+1;
		if ( a[mid].x < val )	lo = mid + 1;
		else	hi = mid - 1;
	}
}

int main(){
	char c,q; int val,idx;
	go();
	while((q=getchar())!=-1){
		getchar();	
		val=0;while((c=getchar())&&c!=10)val=val*10+c-'0';
		if (q == 'q'){
			idx = real(val+1);
			printf("%d\n",get(idx,1));
		}else{
			idx = indice(val);
			update(idx,-a[idx-1].y,1);
			update(idx,-1,0);
		}

	}
	return 0;
}
