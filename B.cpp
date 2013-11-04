#include <cmath>
#include <vector>
#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

const double EPS=(1e-10);
const double pi=acos(-1);
#define foreach(it,a,b) for(typeof(a) it=(a); it!=(b); it++)
#define all(x) (x).begin(), (x).end()


inline int cmp(double a, double b=0)
{
    if(fabs(a-b)<=EPS) return 0;
    if(a<b) return -1;
    return 1;
}

struct punto
{
    double x,y;
    punto(double x=0, double y=0):x(x), y(y){}
    punto operator +(punto p) { return punto(x+p.x,y+p.y);}
    punto operator -(punto p) {return punto(x-p.x,y-p.y);}
    punto operator *(double t){return punto(x*t,y*t);}
    punto operator /(double t){return punto(x/t,y/t);}
    double operator *(punto p){return x*p.x+y*p.y;}
    double operator %(punto p){return x*p.y-y*p.x;}

    int cmp(punto p) const
    {
        if(int t=::cmp(x,p.x)) return t;
        return ::cmp(y,p.y);
    }

    bool operator ==(punto p) const {return cmp(p)==0;}
    bool operator !=(punto p) const {return cmp(p)!=0;}
    bool operator < (punto p) const {return cmp(p)<0;}

};


int between3(punto p, punto q, punto r)
{
    if(cmp((q-p)%(r-p))==0)//colineares
        if(cmp((q-p)*(r-p))<=0) // usar '<' si los extremos no cuentan
            return 1;

    return 0;
}

int ccw(punto a, punto b, punto c)
{

    return cmp((b-a)%(c-a));
}

int enTriangulo(punto k, punto a, punto b, punto c)
{
    int a1, a2, a3;

    a1=ccw(a,k,b);
    a2=ccw(b,k,c);
    a3=ccw(c,k,a);

    if((a1*a2)>0 && (a2*a3)>0) return 1;//dentro
    if(between3(k,a,b)|| between3(k,b,c) || between3(k,c,a))
        return 2; //en el borde

    return 0; //no ta!
}

typedef vector<punto> poligono;



int enPoligonoConvexo(punto k, poligono &p){
    int val=ccw(p[0],p[1],p[2]);

    int esq, dir, medio, n=p.size();

    esq=1;
    dir=n-1;

    while(dir>esq++)
    {
        medio=(esq+dir)/2;
        if(ccw(p[0],p[medio],k)==val) esq=medio;
        else dir=medio;
    }
    return enTriangulo(k,p[0],p[esq],p[dir]) ;

}

poligono read(){
	int na;
	cin >> na;
	poligono A;
	for( int i = 0; i < na; i++){
		punto p;
		cin >> p.x >> p.y;
		A.push_back( p);
	}
	return A;
}

int main(){
	

	poligono A = read();

	poligono B = read();
	bool cagao = false;
	for( int i = 0; i < B.size(); i++){
		if ( !enPoligonoConvexo( B[i], A ) ) {
			cout <<"\t\t"<< B[i].x<< " " << B[i].y << endl;
			cagao = true;
			break;
		}
	}
	if ( cagao ){
		cout <<"NO"<<endl;
	}else{
		cout <<"YES"<<endl;
	}
	return 0;
}

