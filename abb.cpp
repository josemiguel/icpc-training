#include <iostream>
#include <stdlib.h>
#include "abb.h"

using namespace std;

int menu()
{  
    int op;
    system("CLS");
    cout << "ARBOL ABB"  << endl << endl;
    cout << "1. Insertar" << endl;
    cout << "2. Buscar" << endl;
    cout << "3. Buscar mayor" << endl;
    cout << "4. Buscar menor" << endl;
    cout << "5. Imprimir en orden" << endl;
    cout << "6. Imprimir en pre-orden" << endl;
    cout << "7. Imprimir en post-orden" << endl;
    cout << "8. Suma de nodos" << endl;
    cout << "9. Cuenta de nodos" << endl;
    cout << "10. Terminar" << endl;
    cout << endl << "Elija opcion: ";
    cin >> op;
    return op;
}

int main()
{
	abb A;
    int op,v;	
    nodoABB *b;
	do 
	{
        op = menu();
        switch(op)
        {
            case 1:  cout << endl << "Ingrese valor : ";
		             cin >> v;
		             b = A.buscar(v);
                     if ( b == NULL )
                     {      
		                A.insertar(v);
		                cout << endl << "Elemento insertado" << endl;    
		             }
                     else
                        cout << "El elemento ya esta en el arbol" << endl;       
	                 break;
	        
            case 2:  cout << endl << "Ingrese valor : ";
		             cin >> v;
		             b = A.buscar(v);
                     if ( b == NULL )
                        cout << endl << "El elemento no esta en el arbol" << endl;    
		             else
                        cout << "El elemento si esta en el arbol" << endl;   
                     break;
            
            case 3:  b = A.buscar_mayor();
                     if ( b == NULL )
                        cout << "No hay mayor porque el arbol esta vacio" << endl;
                     else
                        cout << "El mayor es " << (*b).dato << endl;
                     break;
                     
            case 4:  b = A.buscar_menor();
                     if ( b == NULL )
                        cout << "No hay menor porque el arbol esta vacio" << endl;
                     else
                        cout << "El menor es " << (*b).dato << endl;
                     break;   
            
            case 5:  cout << "En orden " << endl << endl;
                     A.imprimeenorden( A.getraiz() );
                     cout << endl;
                     break;
                     
            case 6:  cout << "En pre-orden " << endl << endl;
                     A.imprimepreorden( A.getraiz() );
                     cout << endl;
                     break;
                     
            case 7:  cout << "En post-orden " << endl << endl;
                     A.imprimepostorden( A.getraiz() );
                     cout << endl;
                     break; 
                 
            case 8: cout << "La suma de nodos es " << A.sumanodos( A.getraiz()) << endl;                            
                    break;
                                                          
            case 9: cout << "La cantidad de nodos es " << A.cuentanodos( A.getraiz()) << endl;                            
                    break;
                                                                                       
        }    
        cout << endl;
        system("PAUSE");    
    }
    while( op != 10);    
   	return 0;
}
