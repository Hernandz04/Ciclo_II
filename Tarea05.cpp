#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct datos *elemento;

struct datos{
	int dato;
	elemento siguiente;
};
class Lista{
	public:
		Lista();
		bool ListaVacia(void);
		elemento NuevoElemento(void);
		void Anadir(int dato);
		bool Borrar (int dato);
		elemento Buscar(int dato);
		void Visualizar(void);
		int menu(void);
	private:
	elemento cabecera;
};
Lista::Lista(){
	cabecera=NULL;
}
bool Lista::ListaVacia(void){
	return cabecera=NULL;
}

elemento Lista::NuevoElemento(void){
	elemento aux=new datos;
	return aux;
}

void Lista::Anadir(int dato){
	elemento cab=cabecera;
	elemento actual=cabecera, anterior=cabecera, q;
    if(ListaVacia()){
	cab=NuevoElemento();
	cab->dato=dato;
	cab->siguiente=NULL;
	cabecera=cab;
	return;
	}while(actual!=NULL && dato> actual->dato){
		anterior=actual;
		actual=actual->siguiente;
	}
	q=NuevoElemento();
	if(anterior==actual){
		q->dato=dato;
		q->siguiente=cab;
		cab=q;
	}else{
		q->dato=dato;
		q->siguiente=q;
	}
	cabecera=cab;
}
bool Lista::Borrar(int dato){
	elemento cab=cabecera;
	elemento actual=cab, anterior=cab;
	if(ListaVacia())
	    return false;
	while(actual!=NULL && dato!=actual->dato){
		anterior=actual;
		actual=actual->siguiente;
	}
	if (actual==NULL)
    return false;
    if (anterior==actual)
    cab=cab->siguiente;
    else
    anterior->siguiente=actual->siguiente;
    delete(actual);
    cabecera=cab;
    return true;
}
elemento Lista::Buscar (int dato){
	elemento actual=cabecera;
	while(actual!=NULL && dato!=actual->dato)
    actual=actual->siguiente;
return actual;
}
void Lista::Visualizar(void){
    elemento actual=cabecera;
    if(ListaVacia()){
        cout<<"Lista Vacia"<<endl;
    }else{
        while(actual!=NULL){
            cout<<actual->dato<<endl;
            actual=actual->siguiente;
        }
    }
    system ("pause");
}

int Lista::menu(void){
    int op;
    system("cls");
    do{
        cout<<"  MENU"<<endl;
        cout<<"[1] Anadir"<<endl;
        cout<<"[2] Quitar"<<endl;
        cout<<"[3] Buscar"<<endl;
        cout<<"[4] Ver Lista"<<endl;
        cout<<"[5] Salir"<<endl;
        cout<<"Ingrese Opcion: ";
        cin>>op;
        system("cls");
    }while(op!=1 && op!=2 && op!=3 && op!=4 && op!=5);
    return op;
}
int main(int argc, char *argv[]){
	Lista L;
	elemento q;
	int op,V;
	do{
		op=L.menu();
		switch(op){
			case 1: cout<<"Ingrese Valor: ";
			        cin>>V;
			        L.Anadir(V);
			        break;
			case 2: cout<<"Valor a Borrar: ";
			        cin>>V;
			        if(L.Borrar(V))
		                cout<<"Elemento borrado"<<endl;
			         else
			            cout<<"Imposible operacion"<<endl;
			        system("pause");
			        break;
			case 3: if(L.ListaVacia())
			        cout<<"Lista vacia"<<endl;
			        else
			        {
		            cout<<"Valor a buscar: ";
				    cin>>V;
				    q=L.Buscar(V);
				    if(q)
				        cout<<"encontrado"<<endl;
			        else
			            cout<<"no encontrado"<<endl;
			        }
			        system("pause");
			        break;
			case 4: L.Visualizar();
		}
	}while(op!=5);
	return EXIT_SUCCESS;
}