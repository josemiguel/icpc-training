#include<cstdio>
#include<iostream>
using namespace std;

int main (){

	int i,j,k,m,n,p,q,sumador;
	printf("Ingrese el tamano de la matriz A[m,n]:");
	scanf("%d %d",&m,&n);
	int a[m*n];

	for (i=0;i<m;i++){
	    for (j=0;j<n;j++){
        	printf("Ingrese el valor de A[%d][%d]:",i+1,j+1);
	        scanf("%d",&a[i*n+j]);
	    }	
	}	

	printf("Ingrese el tamano de la matriz B[m,n]:");
	scanf("%d %d",&p,&q);
	int b[p*q];


	for (i=0;i<p;i++){
		for (j=0;j<q;j++){
		        printf("Ingrese el valor de B[%d][%d]:",i+1,j+1);
			 scanf("%d",&b[i*q+j]);
		 }
	}

	int c[m*q];
	for (k=0;k < m*q;k++){
	    c[k]=0;
	}

	if (n!=p)printf("No se puede multiplicar.");
	else{
	     for (i=0;i<m;i++){
        	 for (j=0;j<q;j++){
	             sumador =0;
        	     for ( k = 0;k <n; k++){
		             sumador+= a[i*n+k]*b[k*q+j];
	             }
	       	     c[i*m+j]= sumador;
	         }

	    }

	}

	for (i=0;i<m;i++){
	    for (j=0;j<q;j++){
		    printf("%d ",c[i*m+j]);
	    }

	    printf("\n");

	}

	printf("A -->\n");

 

	for (i=0;i<m;i++){

	    for (j=0;j<n;j++){

       	        printf("[%d] ",a[i*n+j]);

	    }

	    printf("\n");

	}

	printf("B -->\n");

	for (i=0;i<p;i++){

	    for (j=0;j<q;j++){

               printf("[%d] ",b[i*q+j]);

	    }

	    printf("\n");

	}

 
	return 0;

}
