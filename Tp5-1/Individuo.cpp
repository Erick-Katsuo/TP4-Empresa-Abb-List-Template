#include "Individuo.h"

/*CONSTRUCTOR*/

Individuo::Individuo(string nombre){
    cout<<"Constructor Individuo"<<endl;
    this->nombre = nombre;
}

/*METODOS ASIGNAR-OBTENER*/

string Individuo::obtener_nombre(){
    return nombre;
}

/*REDEFINICION DE METODOS PURAMENTE VIRTUALES*/

void Individuo::mostrar_registrados(){
    cout<<nombre<<endl;
}

void Individuo::mostrar_descuento(int precio_base){
    cout<<"Precio Base:  $"<<precio_base<<endl;
    cout<<"Descuento:     "<<DESCUENTO_INDIVIDUO*100<<"%"<<endl;
    cout<<"Precio final: $"<<(precio_base - (precio_base*DESCUENTO_INDIVIDUO))<<endl;
}
