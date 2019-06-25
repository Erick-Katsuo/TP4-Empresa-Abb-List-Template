#ifndef _CLIENTE_H_
#define _CLIENTE_H_

#include <iostream>

using namespace std;

class Cliente{
    public:
    /*METODOS PURAMENTE VIRTUALES*/

        /*Descripcion: Metodo virtual, la redefinicion de este metodo debera mostrar al miembro o miembros registrados.
         *Pre:-.
         *Post: Muestra por consola los nombres registrados.
        */
        virtual void mostrar_registrados() = 0;

        /*Descripcion: Metodo virtual, la redefinicion de este metodo debera mostrar por consola el descuento correspondiente
                       y el "precio_base" aplicando el descuento.
         *Pre: precio_base >= 0.
         *Post: Muestra por consola el descuento correspondiente y el "precio_base" aplicando el descuento.
        */
        virtual void mostrar_descuento(int precio_base) = 0;

        virtual ~Cliente(){

            cout<<"Destructor Cliente"<<endl;
        }
};


#endif /*_CLIENTE_H_*/
