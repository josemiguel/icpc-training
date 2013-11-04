#include <iostream>
#include <stdlib.h>
#include "tablashash1.h"

using namespace std;

int menu()
{  
    int op;
    system("CLS");
    cout << "TABLA HASH CON DISPERSION ABIERTA"  << endl << endl;
    cout << "1. Insertar" << endl;
    cout << "2. Buscar" << endl;
    cout << "3. Eliminar" << endl;
    cout << "4. Imprimir" << endl;
    cout << "5. Terminar" << endl;
    cout << endl << "Elija opcion: ";
    cin >> op;
    return op;
}

int main()
{
	tablahash T;
    int op,v;	
	nodo *b;
	do 
	{
        op = menu();
        switch(op)
        {
            case 1:  cout << endl << "Ingrese valor : ";
		             cin >> v;
		             T.insertar(v);
		             break;
            case 2:  cout << endl << "Ingrese valor a buscar : ";
                     cin >> v;
                     b = T.buscar(v);
	                 if ( b == NULL )
	   	                cout << endl << "El elemento no esta en la tabla" << endl;
                     else
                	   	cout << endl << "El elemento si esta en la tabla" << endl;
                	 break; 
            case 3:  cout << endl << "Ingrese valor a eliminar : ";
	                 cin >> v;
                     T.eliminar(v); 
                     break;
            case 4:  T.imprimir();                  	
        }    
        cout << endl;
        system("PAUSE");    
    }
    while( op != 5 );    
   	return 0;
}
