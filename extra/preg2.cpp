#include <iostream>
#include <stdlib.h>
#include "preg2.h"

using namespace std;

int menu()
{  
    int op;
    system("CLS");
    cout << "COLA DE PRIORIDAD"  << endl << endl;
    cout << "1. Encolar" << endl;
    cout << "2. Desencolar" << endl;
    cout << "3. Imprimir" << endl;
    cout << "4. Terminar" << endl;
    cout << endl << "Elija opcion: ";
    cin >> op;
    return op;
}

int main()
{
	colap C;
    int op,v,pr;	
	do 
	{
        op = menu();
        C.imprimir();
        switch(op)
        {
            case 1:  cout << endl << "Ingrese valor : ";
		             cin >> v;
		             cout << endl << "Ingrese prioridad : ";
		             cin >> pr;
		             C.encolar(v,pr);
		             cout << endl << "Elemento encolado" << endl;    
	                 break;
	        case 2:  if ( !C.estavacia() )
	                 {
                         v = C.desencolar();
                         cout << endl << v << " ha sido desencolado" << endl;  
                     } 
                     else
		                 cout << endl << "No hay elementos en la cola" << endl;  
	                 break;
            case 3:  C.imprimir();                  	
        }    
        cout << endl;
        system("PAUSE");    
    }
    while( op != 4);    
   	return 0;
}
