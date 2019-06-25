#include "Familia.h"

/*CONSTRUCTOR*/

Familia::Familia(int cantidad_integrantes){
    string nombre = SIN_NOMBRE;
    cout<<"Constructor Familia"<<endl;
    cout<<"Registrando "<<cantidad_integrantes<<" integrantes"<<endl;
    for(int i = 1; i<= cantidad_integrantes ; i++){
        cout<<"Ingrese nombre de algun integrante"<<endl;
        cin>>nombre;
        integrantes.agregar_nodo(nombre, 1);
        cout<<"Registrados: "<<i<<endl;
    }
    cout<<"Registro completado"<<endl;
}

Familia::Familia(){
    cout<<"Constructor Familia"<<endl;
}

/*METODOS ASIGNAR-OBTENER*/

Lista<string>* Familia::obtener_list_integrantes(){
    return &integrantes;
}

/*REDEFINICION DE METODOS PURAMENTE VIRTUALES*/

void Familia::mostrar_registrados(){
    cout<<"\tMostrando integrantes"<<endl;
    for(int i = 1; i <= integrantes.obtener_tam_lista() ; i++){
        cout<<integrantes.consultar_lista(i);
        if(i!=integrantes.obtener_tam_lista()){
            cout<<", ";
        }else{
            cout<<endl;
        }
    }
}

void Familia::mostrar_descuento(int precio_base){
    int precio_total = precio_base * integrantes.obtener_tam_lista();
    cout<<"Precio Base:  $"<<precio_base<<endl;
    cout<<"Precio Total:  $"<<precio_total<<endl;
    cout<<"Descuento:     "<<DESCUENTO_FAMILIA*100<<"%"<<endl;
    cout<<"Precio final: $"<<(precio_total - (precio_total*DESCUENTO_FAMILIA))<<endl;
}
