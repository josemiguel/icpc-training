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
#define foreach(it,a,b) for(typeof(a) it=(a); it!=(b); it++)
#define all(x) (x).begin(), (x).end()

const double pi=acos(-1);

inline int cmp(double a, double b=0)
{
    if(fabs(a-b)<=EPS) return 0;
    if(a<b) return -1;
    return 1;
}
/*
 estructura y operaciones basicas de un punto
 */
struct point
{
    double x,y;
    point(double x=0, double y=0):x(x), y(y){}
    point operator +(point p) { return point(x+p.x,y+p.y);}
    point operator -(point p) {return point(x-p.x,y-p.y);}
    point operator *(double t){return point(x*t,y*t);}
    point operator /(double t){return point(x/t,y/t);}
    double operator *(point p){return x*p.x+y*p.y;}
    double operator %(point p){return x*p.y-y*p.x;}

    int cmp(point p) const
    {
        if(int t=::cmp(x,p.x)) return t;
        return ::cmp(y,p.y);
    }

    bool operator ==(point p) const {return cmp(p)==0;}
    bool operator !=(point p) const {return cmp(p)!=0;}
    bool operator < (point p) const {return cmp(p)<0;}

};

int ccw(point a, point b, point c)
{
    //b-a comparado con c-a
    return cmp((b-a)%(c-a));
    //ccw=1, cw=-1, colinear=0
}


//le puse vect xq obviamente "vector" no se le puede poner xD
typedef vector<point> poligono;
typedef point vect;


vect normal(vect v){return vect(-v.y,v.x);}
double norma(vect v){return hypot(v.x,v.y);}

/******************************************************************************
 Convex Hull (Graham)
 Complejidad: O(n*lg(n))
 Dependencias:
 *  norma()
 *  ccw()
 *  estructuras de punto y recta
 Descripcion:
 * algoritmo de graham para obtener el convex-hull  dado un
 * conjutno de puntos
 ******************************************************************************/

 point pivote;

 bool cmp_radial(point a, point b)
 {
      //para ordenar en sentido horario
      int aux=ccw(pivote,a,b);
      return ((aux<0) ||(aux==0 && norma(a-pivote)<norma(b-pivote)));
 }

 bool cmp_pivote(point p, point q)
 {
      //para ordenar según el menor x o el y
      int aux=cmp(p.x, p.y);
      return ((aux<0) || (aux==0 && cmp(p.y,q.y)));
 }

 /*pasar el poligono por referencia reduce el tiempo, pero desordena el
   conjunto de puntos*/

   poligono convexHull(poligono &p)
   {
      int i,j,n=p.size();
      poligono g;
      /*ordena, formando un poligono estrellado*/
      pivote=*min_element(p.begin(),p.end(),cmp_pivote);
      sort(p.begin(),p.end(),cmp_radial);

      /*
        para poner a los colineares al final del poligono

        for(i=n-2; i>=0 && ccw(p[0],p[i],p[n-1])==0; i--)
                   reverse(p.begin()+i+1,p.end());

      */

      for(i=j=0;i<n; i++)
      {
          //si se quieren tener en cuenta colineares cambiar >= por >
          while(j>2 && ccw(g[j-2],g[j-1],p[i])>0)
          {
                     g.pop_back();
                     j--;
          }
          g.push_back(p[i]); j++;
      }
      return g;
   }


int main(){
    int i, n;
    poligono p;
    point k;
    scanf("%d", &n);
    while (n--) {
        scanf("%lf %lf", &k.x, &k.y);
        p.push_back(k);
    }
    poligono g = convexHull(p);
    n = g.size();
    for (i = 0; i < n; i++)
        printf("(%lf,%lf)\n", g[i].x, g[i].y);

	for(int i = 0; i < 3;i++){
		for(int j = i+1;j < 4;j++){
			
		}
	}

    putchar('\n');
}
