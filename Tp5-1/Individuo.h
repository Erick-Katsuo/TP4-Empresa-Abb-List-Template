
#ifndef _INDIVIDUO_H_
#define _INDIVIDUO_H_

#include "Cliente.h"

const float DESCUENTO_INDIVIDUO = 0.1;

class Individuo: public Cliente{
    private:
        string nombre;
    public:
    /*CONSTRUCTOR*/

        /*Descripcion: Constructor de la clase Individuo.
         *Pre: -.
         *Post: Muestra por consola los nombres registrados.
        */
        Individuo(string nombre);

    public:
    /*METODOS ASIGNAR-OBTENER*/

        string obtener_nombre();

    public:
    /*REDEFINICION DE METODOS PURAMENTE VIRTUALES*/

        /*Descripcion: Redefinicion de metodo perteneciente a la clase Cliente, muestra al miembro registrado.
         *Pre: -.
         *Post: Muestra por consola los nombres registrados.
        */
        void mostrar_registrados();

        /*Descripcion: Redefinicion de metodo perteneciente a la clase Cliente, muestra por consola el descuento correspondiente
                       y el "precio_base" aplicando el descuento.
         *Pre: precio_base >= 0.
         *Post: Muestra por consola el descuento correspondiente y el "precio_base" aplicando el descuento.
        */
        void mostrar_descuento(int precio_base);

        virtual ~Individuo(){
            cout<<"Destructor Individuo"<<endl;
        }
};


#endif /*_INDIVIDUO_H_*/
