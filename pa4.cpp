#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;


void insertar(void **&lista, void *dato, int (*comparar)(void*, void*)){

	void **nodo = new void*[2];
	nodo[1] = dato;
	nodo[2] = NULL;

	if ( lista == NULL ) {
		lista = nodo;
	}else{
		void **ptr = lista;
		int ret = -1;
		while( (ret=comparar( ptr[1], dato))< 0 && ptr[2] != NULL ){ // el orden de las 2 sentencias importa
			ptr = (void**)ptr[2];
		}
		if ( ret == 0 ) return ;
		void **tmp = (void **)ptr[2] ;
		nodo[2] = tmp;
		ptr[2] = nodo;
	}
}
 
void *buscar(void * lista, void *dato, int (*comparar)(void*, void*)){
	if ( lista == NULL ) {
		return NULL;
	}else{
		void **ptr = (void**)lista;
		while( ptr != NULL){
			if (comparar( ptr[1], dato) == 0 ) return ptr[1];
			ptr = (void**)ptr[2];
		}
	}
	return NULL;

}
void imprimir(void **lista, void(*impDato)(void*)){
	while( lista ) {
	
		impDato( lista[ 1 ] );
		
		lista = (void**)lista[2];
	}
}
int comparaCia(void *a, void *b ){
	void **na = (void**)a;
	void **nb = (void**)b;	
	
	int a_code = *(int *)na[0];
	int b_code = *(int *)nb[0];	
//	cout << a_code<<" " << b_code<<endl;
	return a_code - b_code;
}

int comparaTel(void *a, void *b){
	void **na = (void**)a;
	void **nb = (void**)b;	
	
	char *a_tel = (char *)na[0];
	char *b_tel = (char *)nb[0];	
	
	int ret = strcmp( a_tel,b_tel);
//	cout << a_tel <<" " <<b_tel << endl;
	if ( ret == 0 ) {
		
		float *acum = new float[1];
		*acum = *(float *) na[1] + *(float *)nb[1];
		na[1] = acum;
	}
	
	return ret;
}

void *leeCia(){
	void **lista = NULL;
	char s[100];
	int n; char c;
	while( scanf("%d%c", &n, &c) ) {
		gets( s );	
		
		char *cia = new char[strlen(s)+1];
		strcpy( cia, s );
		
		void **nodo = new void *[3];
		int *nro = new int[1];
		*nro = n;
		nodo[0] = nro;
		nodo[1] = cia;
		nodo[2] = NULL;
		
		void *dato = nodo;
		
		insertar( lista, dato, comparaCia);
	}
	gets( s );
	return lista ;	
}

void imprimeTel(void *a){
	void **tel = (void**)a;
	printf("%s\tTotal: %.2f\n", (char *) tel[0], *(float *) tel[1]);
}

void imprimeCia(void *a){
	void **cia = (void**)a;
	printf("%d %s\n", *(int *)cia[0], (char *)cia[1] );
	imprimir( (void**) cia[2], imprimeTel);
	
}


void *leeTel( void *cias ){
	char s[100];
	int n; 
	float v;
	while( scanf("%d %s %f", &n, s , &v) != EOF) {
	
		void **nodo = new void*[3];
		int *nro  = new int[1];
		*nro = n;
		nodo[0] = nro;
		nodo[1] = nodo[2] = NULL;

		
		
		void *ptr = buscar( cias, nodo, comparaCia );
		if ( ptr == NULL ) continue;
		

		/***********************************/
		void **tel = new void*[2];
		
		char *cad = new char[strlen(s)+1];
		strcpy( cad, s );
		
		float *val = new float[1];
		*val = v;
		
		tel[0] = cad;
		tel[1] = val; 
		/***********************************/		
		
		void **tmp = (void **) ptr;
		//cout << tmp[2] << endl;
		
		void **telfs = (void**)tmp[2];
		
		insertar( telfs, tel, comparaTel );
		
		tmp[2] = telfs;
	}
	return NULL ;	
}




int main(){

	void *cias = leeCia();
	leeTel( cias );
	imprimir( (void**)cias, imprimeCia);
	
	return 0;
}
