#include <cstdlib>
#include <iostream>

using namespace std;

struct nodo_2{
    int data;
    nodo_2 *sig;
    nodo_2 *prev;
}*start, *stop;

class ListaSecundaria{

public:
    ListaSecundaria(){
        start = nullptr;
        stop = nullptr;
    }
    
    void agregarElemento(int valor){
         nodo_2 * n = crearNodo(valor);
         if(!start){
             start = n;
             stop = n;
         }else{
             stop -> sig = n;
             n -> prev = stop;
             stop = n;
         }
     }
    
    nodo_2* crearNodo(int valor){
         nodo_2 * n = new nodo_2;
         n-> data = valor;
         n -> sig = nullptr;
         n -> prev = nullptr;
         return n;
     }
    
    void mostrarLista(){
         nodo_2 * temp = start;
         if(!start){
             cout<<"No hay elementos que mostrar";
         }
         else{
             while(temp){
                 cout<<temp -> data<<", ";
                 temp = temp -> sig;
             }
         }
     }

};

struct nodo{
    int dato;
    nodo *sig;
    nodo *prev;
 } *inicio, *fin;
 
class ListaDoble {
    
public:
    
    ListaDoble(){
        inicio = nullptr;
        fin = nullptr;
        
    }
        
    void agregarElemento(int valor){
         nodo * n = crearNodo(valor);
         if(!inicio){
             inicio = n;
             fin = n;
         }else{
             fin -> sig = n;
             n -> prev = fin;
             fin = n;
         }
     }
    
    int promedio(){
        int suma = 0;
        int elementos = 0;
        nodo *temp;
        temp = inicio;
        if(!inicio){
            return 0;
        }
        else{
            while(temp){
                suma += temp -> dato;
                elementos ++;
                temp = temp -> sig;
            }
        }
        return suma/elementos;
    }
    
    void revisarProm(int prom, ListaSecundaria l2){
        nodo *temp;
        temp = inicio;
        if(!inicio){
            cout<<"La lista esta vacia ;v "<<endl;
        }
        else{
            while(temp){
                int data = temp -> dato;
                cout<<"dato: "<<data<<endl;
                if(data >= prom){
                    l2.agregarElemento(data);
                }  
                temp = temp->sig;
            }
        }
    }

    nodo* crearNodo(int valor){
         nodo * n = new nodo;
         n-> dato = valor;
         n -> sig = nullptr;
         n -> prev = nullptr;
         return n;
     }

    void mostrarLista(){
         nodo * temp = inicio;
         if(!inicio){
             cout<<"No hay ni mierda";
         }
         else{
             while(temp){
                 cout<<temp -> dato<<", ";
                 temp = temp -> sig;
             }
         }
     }
};
 
int main(int argc, char** argv) {
    ListaDoble listita;
    ListaSecundaria l2;
    listita.agregarElemento(1);
    listita.agregarElemento(2);
    listita.agregarElemento(3);
    listita.agregarElemento(4);
    listita.agregarElemento(5);
    listita.mostrarLista();
    int prom = listita.promedio();
    listita.revisarProm(prom, l2);
    l2.mostrarLista();
    return 0;
    
}