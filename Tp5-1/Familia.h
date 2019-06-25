
#ifndef _FAMILIA_H_
#define _FAMILIA_H_

#include "Lista.h"

#include "Cliente.h"

const string SIN_NOMBRE = "SIN_NOMBRE";
const float DESCUENTO_FAMILIA = 0.35;
const int PRECIO_NULO = -1;

class Familia: public Cliente{
    private:
        Lista<string> integrantes;
    public:
    /*CONSTRUCTOR*/

        /*Descripcion: Constructor de la clase Familia, crea el objeto "Familia" con la "cantidad_integrantes"
                       guardandolos en la Lista "integrantes".
         *Pre: "cantidad_integrantes" > 0.
         *Post: Crea el objeto Familia y la Lista "integrantes" correctamente.
        */
        Familia(int cantidad_integrantes);

        /*Descripcion: Constructor por defecto de la clase Familia.
         *Pre: -.
         *Post: Crea el objeto Familia.
        */
        Familia();

    public:
    /*METODOS ASIGNAR-OBTENER*/

        Lista<string>* obtener_list_integrantes();

    public:
    /*REDEFINICION DE METODOS PURAMENTE VIRTUALES*/

        /*Descripcion: Redefinicion de metodo perteneciente a la clase Cliente, muestra a los miembros registrados.
         *Pre: Lista de integrantes correctamente inicializada.
         *Post: Muestra por consola los nombres registrados.
        */
        void mostrar_registrados();

        /*Descripcion: Redefinicion de metodo perteneciente a la clase Cliente, muestra por consola el descuento correspondiente
                       y el "precio_base" aplicando el descuento.
         *Pre: precio_base >= 0.
         *Post: Muestra por consola el descuento correspondiente y el "precio_base" aplicando el descuento.
        */
        void mostrar_descuento(int precio_base);

        virtual ~Familia(){
            cout<<"Destructor Familia"<<endl;
        }
};


#endif /*_FAMILIA_H_*/
