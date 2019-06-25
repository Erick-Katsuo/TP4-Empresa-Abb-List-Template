
#ifndef _NODO_ABB_H_
#define _NODO_ABB_H_

#include <iostream>

using namespace std;

const int PUNTERO_NULO_ABB = 0;
const int SIN_CLAVE = 0;

template<typename Dato>
class Nodo_abb{
    private:
    /*ATRIBUTOS*/
        int clave;
        Dato contenido;
        Nodo_abb* hijo_der;
        Nodo_abb* hijo_izq;
        Nodo_abb* padre;
    public:
    /*CONSTRUCTOR*/

        /*Descripcion: Constructor de la clase Nodo_abb. Inicializa los atributos correspondientes.
         *Pre: -.
         *Post: Crea el objeto con los parametros recibidos.
        */
        Nodo_abb(Dato contenido, int clave, Nodo_abb* padre);
    public:
    /*METODOS ASIGNAR-OBTENER*/
        /*Descripcion: Asigna un valor al atributo "contenido".
         *Pre: El tipo de dato debe corresponder al definido para "Dato".
         *Post: Queda asignado un nuevo valor para el atributo "contenido".
        */
        void asignar_contenido(Dato recibir_contenido);

        /*Descripcion: Actualiza la clave correspondiente al "Nodo_abb" actual.
         *Pre:-.
         *Post: Actualiza la clave correspondiente al "Nodo_abb" actual.
        */
        void asignar_clave(int clave);

        /*Descripcion: Devuelve la clave correspondiente al "Nodo_abb" actual.
         *Pre: -.
         *Post: Devuelve la clave correspondiente.
        */
        int obtener_clave();

        /*Descripcion: Devuelve el puntero "hijo_der" correspondiente al "Nodo_abb" actual.
         *Pre: -.
         *Post: Devuelve la direccion del "hijo_der".
        */
        Nodo_abb* obtener_hijo_der();

        /*Descripcion: Devuelve el puntero "hijo_izq" correspondiente al "Nodo_abb" actual.
         *Pre: -.
         *Post: Devuelve la direccion del "hijo_izq".
        */
        Nodo_abb* obtener_hijo_izq();

        /*Descripcion: Actualiza el hijo derecho del "Nodo_abb" actual.
         *Pre:-.
         *Post:  Actualiza el hijo derecho al "Nodo_abb" actual.
        */
        void asignar_hijo_der(Nodo_abb* hijo_der);

        /*Descripcion: Actualiza el hijo izquierdo del "Nodo_abb" actual.
         *Pre:-.
         *Post:  Actualiza el hijo izquierdo al "Nodo_abb" actual.
        */
        void asignar_hijo_izq(Nodo_abb* hijo_izq);

        /*Descripcion: Devuelve el atributo "contenido".
         *Pre: -.
         *Post: Devuelve el atributo "contenido".
        */
        Dato obtener_contenido();

        /*Descripcion: Devuelve el puntero "padre" correspondiente al "Nodo_abb" actual.
         *Pre: -.
         *Post: Devuelve la direccion del "padre".
        */
        Nodo_abb* obtener_padre();

        /*Descripcion: Actualiza el padre del "Nodo_abb" actual.
         *Pre:-.
         *Post:  Actualiza el padre del "Nodo_abb" actual.
        */
        void asignar_padre(Nodo_abb<Dato>* padre);
};


/*CONSTRUCTOR*/
template<typename Dato>
Nodo_abb<Dato>::Nodo_abb(Dato contenido, int clave, Nodo_abb<Dato>* padre){
    cout<<"Constructor Nodo_abb"<<endl;
    this->contenido = contenido;
    this->clave = clave;
    this->hijo_der = PUNTERO_NULO_ABB;
    this->hijo_izq = PUNTERO_NULO_ABB;
    this->padre = padre;
}

/*METODOS ASIGNAR-OBTENER*/

template<typename Dato>
void Nodo_abb<Dato>::asignar_contenido(Dato contenido){
    this->contenido = contenido;
}

template<typename Dato>
void Nodo_abb<Dato>::asignar_clave(int clave){
    this->clave = clave;
}

template<typename Dato>
int Nodo_abb<Dato>::obtener_clave(){
    return clave;
}

template<typename Dato>
Nodo_abb<Dato>* Nodo_abb<Dato>::obtener_hijo_der(){
    return hijo_der;
}

template<typename Dato>
Nodo_abb<Dato>* Nodo_abb<Dato>::obtener_hijo_izq(){
    return hijo_izq;
}

template<typename Dato>
void Nodo_abb<Dato>::asignar_hijo_der(Nodo_abb<Dato>* hijo_der){
    this->hijo_der = hijo_der;
}

template<typename Dato>
void Nodo_abb<Dato>::asignar_hijo_izq(Nodo_abb<Dato>* hijo_izq){
    this->hijo_izq = hijo_izq;
}

template<typename Dato>
Dato Nodo_abb<Dato>::obtener_contenido(){
    return contenido;
}

template<typename Dato>
Nodo_abb<Dato>* Nodo_abb<Dato>::obtener_padre(){
    return padre;
}

template<typename Dato>
void Nodo_abb<Dato>::asignar_padre(Nodo_abb<Dato>* padre){
    this->padre = padre;
}

#endif /*_NODO_ABB_H_*/

