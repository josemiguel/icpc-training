#include <iostream>
#include <stdlib.h>

using namespace std;

const int N = 9;

void mostrar( int a[N] )
{
   int i;
   for(i=0;i<N;i++)
      cout << a[i] << '\t';
   cout << endl << endl;    
}

void ord_shell( int a[N] )
{
     int i, j, k, inc, aux;
     inc = N/2;
     while (inc>0)
     {
        cout << "Distancia: " << inc << endl << endl;   
	    for(i=inc;i<N;i++)
	    {
	       j = i - inc;
	       while (j >= 0)
	       {
		      k = j + inc;
		      if ( a[j] <= a[k] )
			     j = -1;
		      else
		      {
			    aux = a[j];
			    a[j] = a[k];
			    a[k] = aux;	
			    mostrar(a);
		      }
		      j = j - inc;
		   }
	    }
	    inc = inc/2;  
     }
}

int main()
{
   int a[N]={20,11,37,24,18,15,29,32,13};
   mostrar(a);
   ord_shell(a);
   //mostrar(a);
   system("PAUSE");
   return 0;
}
