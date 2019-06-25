#ifndef _ABB_H_
#define _ABB_H_

#include "Nodo_abb.h"

const int ABB_VACIO = 0;
const int NO_EXISTE = 0;

const bool INSERTADO_CORRECTO = true;
const bool INSERTADO_FALLIDO = false;

template<typename Dato>
class Abb{
    private:
    /*ATRIBUTOS*/
        Nodo_abb<Dato>* raiz;
        int tam_abb;
    public:
    /*CONSTRUCTOR*/

        /*Descripcion: Constructor de la clase Nodo_abb. Inicializa los atributos correspondientes.
         *Pre: -.
         *Post: Crea el objeto como corresponde.
        */
        Abb();
    public:
    /*METODOS OBTENER*/

        /*Descripcion: Devuelve la raiz correspondiente al Abb.
         *Pre: -.
         *Post: Devuelve la raiz, en caso de no existir devuelve 0(cero)/NO_EXISTE.
        */
        Nodo_abb<Dato>* obtener_raiz();

        /*Descripcion: Devuelve tamaño actual del Abb.
         *Pre: -.
         *Post: Devuelve tamaño correspondiente al Abb.
        */
        int obtener_tam_abb();


    public:
    /*METODOS*/

        /*Descripcion: Recibe la raiz, clave y el contenido. Si no existe la raiz procede a crearla, en caso contrario
                       procede a insertar el nuevo nodo como corresponde.
         *Pre: -.
         *Post: Inserta el nuevo contenido como corresponde a un Abb.
        */
        bool insertar_raiz(Dato nuevo_contenido, int clave);

    private:
        /*Descripcion: Recibe la raiz, clave y el contenido para luego hubicarlo en el correspondiente lugar dependiendo
                       de las condiciones establecidas.
                       Actualiza el "tam_abb".
         *Pre: El puntero "nodo_abb" recibido fuera de este metodo debe corresponder al puntero "raiz" de este Abb.
         *Post: Inserta el nuevo contenido como corresponde a un Abb. Actualiza el "tam_abb".
        */
        void insertar(Dato nuevo_contenido, int clave, Nodo_abb<Dato>* nodo_abb, bool &insertar);

    public:
        /*Descripcion: Buscara el contenido requerido mediante la clave ingresada, dependiendo de las condiciones
                       devuelve o no el contenido esperado y en caso de no existir lo notifica por consola.
         *Pre: El puntero "nodo_abb" recibido fuera de este metodo debe corresponder al puntero "raiz" de este Abb.
         *Post: Devuelve el contenido, en caso de no existir lo notifica por consola retornando 0(cero) definido como NO_EXISTE.
        */
        Nodo_abb<Dato>* buscar_nodo(int clave, Nodo_abb<Dato>* nodo_abb);

    private:
        /*Descripcion: Modifica los Nodo_abb necesarios para el caso de borrar un nodo con dos hijos.
         *Pre: Nodo_abb correctamente inicializados y modificados previamente.
         *Post: Modifica los Nodo_abb necesarios para el caso de borrar un nodo con dos hijos.
        */
        Nodo_abb<Dato>* caso_dos_hijos(Nodo_abb<Dato>* nodo_original, Nodo_abb<Dato>* nodo_reemplazo);
    public:

        /*Descripcion: Borrara el contenido del Nodo_abb deseado dependiendo de la clave ingresada.
                       En caso de no existir la clave ingresada se procedera a informar que no existe.
         *Pre: -.
         *Post: Devuelve true en caso de borrar, en caso de no existir lo notifica por consola y devuelve false.
        */
        bool borrar_raiz(int clave);

    private:

        /*Descripcion: Metodo que opera las condiciones necesarias para el caso de borrado en un Nodo_abb sin hijos.
         *Pre: Nodo_abb correctamente inicializado y modificado previamente..
         *Post: Metodo que opera las condiciones necesarias para el caso de borrado en un Nodo_abb sin hijos.
        */
        void caso_sin_hijos(Nodo_abb<Dato>* nodo_abb);

        /*Descripcion: Metodo que opera las condiciones necesarias para el caso de borrado en un Nodo_abb con un hijo derecho.
         *Pre: Nodo_abb correctamente inicializado y modificado previamente..
         *Post: Metodo que opera las condiciones necesarias para el caso de borrado en un Nodo_abb con un hijo derecho.
        */
        void caso_hijo_der(Nodo_abb<Dato>* nodo_abb);

        /*Descripcion: Metodo que opera las condiciones necesarias para el caso de borrado en un Nodo_abb con un hijo izquierdo.
         *Pre: Nodo_abb correctamente inicializado y modificado previamente..
         *Post: Metodo que opera las condiciones necesarias para el caso de borrado en un Nodo_abb con un hijo izquierdo.
        */
        void caso_hijo_izq(Nodo_abb<Dato>* nodo_abb);

        /*Descripcion: Metodo que opera las condiciones necesarias para el caso de borrado en un Nodo_abb con un hijo.
                       Dependiendo de si es un hijo derecho o izquierdo procedea utilizar el metodo correspondiente.
         *Pre: Nodo_abb correctamente inicializado y modificado previamente..
         *Post: Utiliza los metodos necesarios para el borrado de un Nodo_abb con un hijo.
        */
        void caso_un_hijo(Nodo_abb<Dato>* nodo_abb);

        /*Descripcion: Borrara el contenido del Nodo_abb deseado dependiendo de la clave ingresada.
                       En caso de no existir la clave ingresada se procedera a informar que no existe.
                       la variable "borrado" es asignada como true si se logra borrar, false en caso contrario
         *Pre: -.
         *Post: Borra el contenido del Nodo_abb deseado, asigna true a "borrado" si logra borrar y en caso contrario false.
        */
        void borrar(int clave, Nodo_abb<Dato>* nodo_abb, bool &borrado);

    private:
    /*METODO DEL DESTRUCTOR*/

        /*Descripcion: Metodo encargado de liberar hoja por hoja hasta finalizar con el Abb usado.
         *Pre: Unicamente recibe como parametro a la raiz del Abb.
         *Post: Libera la hoja correspondiente.
        */
        void liberar_hojas(Nodo_abb<Dato>* hoja);

    public:
    /*DESTRUCTOR*/

        /*Descripcion: Destructor de la clase Abb. Libera la memoria utilizada.
         *Pre: -.
         *Post: Libera la memoria utilizada.
        */
        ~Abb();

};

/*CONSTRUCTOR*/
template<typename Dato>
Abb<Dato>::Abb(){
    cout<<"Constructor Abb"<<endl;
    this->raiz = NO_EXISTE;
    this->tam_abb = ABB_VACIO;
}

/*METODOS OBTENER*/

template<typename Dato>
Nodo_abb<Dato>* Abb<Dato>::obtener_raiz(){
    return raiz;
}

template<typename Dato>
int Abb<Dato>::obtener_tam_abb(){
    return tam_abb;
}



/*METODOS*/

template<typename Dato>
bool Abb<Dato>::insertar_raiz(Dato nuevo_contenido, int clave){
    bool insertado = INSERTADO_FALLIDO;
    if(tam_abb == ABB_VACIO){
        raiz = new Nodo_abb<Dato>(nuevo_contenido, clave, NO_EXISTE);
        tam_abb++;
        insertado = INSERTADO_CORRECTO;
    }else{
        insertar(nuevo_contenido,clave,this->raiz, insertado);
        if(insertado){
            tam_abb++;
        }
    }
    return insertado;
}

template<typename Dato>
void Abb<Dato>::insertar(Dato nuevo_contenido, int clave, Nodo_abb<Dato>* nodo_abb, bool &insertado){
    if(clave > nodo_abb->obtener_clave()){
        if(nodo_abb->obtener_hijo_der() == NO_EXISTE){
            nodo_abb->asignar_hijo_der(new Nodo_abb<Dato>(nuevo_contenido, clave, nodo_abb));
            insertado = INSERTADO_CORRECTO;
        }else{
            insertar(nuevo_contenido, clave, nodo_abb->obtener_hijo_der(), insertado);
        }
    }else if(clave < nodo_abb->obtener_clave()){
        if(nodo_abb->obtener_hijo_izq() == NO_EXISTE){
            nodo_abb->asignar_hijo_izq(new Nodo_abb<Dato>(nuevo_contenido, clave, nodo_abb));
            insertado = INSERTADO_CORRECTO;
        }else{
            insertar(nuevo_contenido, clave, nodo_abb->obtener_hijo_izq(), insertado);
        }
    }else{
        insertado = INSERTADO_FALLIDO;
    }
}

template<typename Dato>
Nodo_abb<Dato>* Abb<Dato>::buscar_nodo(int clave, Nodo_abb<Dato>* nodo_abb){
    if(nodo_abb != NO_EXISTE){
        if(clave > nodo_abb->obtener_clave()){
            nodo_abb = buscar_nodo(clave, nodo_abb->obtener_hijo_der());
        }else if(clave < nodo_abb->obtener_clave()){
            nodo_abb = buscar_nodo(clave, nodo_abb->obtener_hijo_izq());
        }
    }else{
        cout<<"Nodo requerido con clave "<<clave<<": No existe"<<endl;
    }
    return nodo_abb;
}

template<typename Dato>
Nodo_abb<Dato>* Abb<Dato>::caso_dos_hijos(Nodo_abb<Dato>* nodo_original, Nodo_abb<Dato>* nodo_reemplazo){
    if((nodo_reemplazo->obtener_hijo_izq()) == NO_EXISTE){
        if( nodo_reemplazo->obtener_clave() > nodo_reemplazo->obtener_padre()->obtener_clave()){
            if(nodo_reemplazo->obtener_hijo_der() != NO_EXISTE){
                nodo_reemplazo->obtener_padre()->asignar_hijo_der( nodo_reemplazo->obtener_hijo_der() );
                nodo_reemplazo->obtener_hijo_der()->asignar_padre( nodo_reemplazo->obtener_padre() );
            }else{
                nodo_reemplazo->obtener_padre()->asignar_hijo_der( NO_EXISTE );
            }
        }else if(nodo_reemplazo->obtener_clave() < nodo_reemplazo->obtener_padre()->obtener_clave()){
            if(nodo_reemplazo->obtener_hijo_der() != NO_EXISTE){
                nodo_reemplazo->obtener_padre()->asignar_hijo_izq( nodo_reemplazo->obtener_hijo_der() );
                nodo_reemplazo->obtener_hijo_der()->asignar_padre( nodo_reemplazo->obtener_padre() );
            }else{
                nodo_reemplazo->obtener_padre()->asignar_hijo_izq( NO_EXISTE );
            }
        }
        nodo_original->asignar_clave( nodo_reemplazo->obtener_clave() );
        nodo_original->asignar_contenido( nodo_reemplazo->obtener_contenido() );
    }else{
        nodo_reemplazo = caso_dos_hijos(nodo_original, nodo_reemplazo->obtener_hijo_izq());
    }

    return nodo_reemplazo;
}

template<typename Dato>
bool Abb<Dato>::borrar_raiz(int clave){
    bool borrado = false;
    borrar(clave, this->raiz, borrado);
    return borrado;
}



template<typename Dato>
void Abb<Dato>::caso_hijo_der(Nodo_abb<Dato>* nodo_abb){
    if(nodo_abb->obtener_padre() != NO_EXISTE){
        if(nodo_abb->obtener_clave() > nodo_abb->obtener_padre()->obtener_clave()){
            nodo_abb->obtener_padre()->asignar_hijo_der(nodo_abb->obtener_hijo_der());
        }else if(nodo_abb->obtener_clave() < nodo_abb->obtener_padre()->obtener_clave()){
            nodo_abb->obtener_padre()->asignar_hijo_izq(nodo_abb->obtener_hijo_der());
        }
        nodo_abb->obtener_hijo_der()->asignar_padre(nodo_abb->obtener_padre());
    }else{
        nodo_abb->obtener_hijo_der()->asignar_padre(NO_EXISTE);
        raiz = nodo_abb->obtener_hijo_der();
    }
}

template<typename Dato>
void Abb<Dato>::caso_hijo_izq(Nodo_abb<Dato>* nodo_abb){
    if(nodo_abb->obtener_padre() != NO_EXISTE){
        if(nodo_abb->obtener_clave() > nodo_abb->obtener_padre()->obtener_clave()){
            nodo_abb->obtener_padre()->asignar_hijo_der(nodo_abb->obtener_hijo_izq());
        }else if(nodo_abb->obtener_clave() < nodo_abb->obtener_padre()->obtener_clave()){
            nodo_abb->obtener_padre()->asignar_hijo_izq(nodo_abb->obtener_hijo_izq());
        }
        nodo_abb->obtener_hijo_izq()->asignar_padre(nodo_abb->obtener_padre());
    }else{
        nodo_abb->obtener_hijo_izq()->asignar_padre(NO_EXISTE);
        raiz = nodo_abb->obtener_hijo_izq();
    }
}

template<typename Dato>
void Abb<Dato>::caso_un_hijo(Nodo_abb<Dato>* nodo_abb){
    if((nodo_abb->obtener_hijo_der() != NO_EXISTE) && (nodo_abb->obtener_hijo_izq() == NO_EXISTE)){
        caso_hijo_der(nodo_abb);
    }else if((nodo_abb->obtener_hijo_der() == NO_EXISTE) && (nodo_abb->obtener_hijo_izq() != NO_EXISTE)){
        caso_hijo_izq(nodo_abb);
    }
}

template<typename Dato>
void Abb<Dato>::caso_sin_hijos(Nodo_abb<Dato>* nodo_abb){
    if(nodo_abb->obtener_padre() != NO_EXISTE){
        if(nodo_abb->obtener_clave() > nodo_abb->obtener_padre()->obtener_clave()){
            nodo_abb->obtener_padre()->asignar_hijo_der(NO_EXISTE);
        }else if(nodo_abb->obtener_clave() < nodo_abb->obtener_padre()->obtener_clave()){
            nodo_abb->obtener_padre()->asignar_hijo_izq(NO_EXISTE);
        }
    }else{
        raiz = NO_EXISTE;
    }
}


template<typename Dato>
void Abb<Dato>::borrar(int clave, Nodo_abb<Dato>* nodo_abb, bool &borrado){
    Nodo_abb<Dato>* aux = NO_EXISTE;
    if(nodo_abb != NO_EXISTE){
        if( clave > nodo_abb->obtener_clave() ){
            borrar(clave, nodo_abb->obtener_hijo_der(), borrado);
        }else if( clave < nodo_abb->obtener_clave() ){
            borrar(clave, nodo_abb->obtener_hijo_izq(), borrado);
        }else if(clave == nodo_abb->obtener_clave()){
            aux = nodo_abb;
            if((nodo_abb->obtener_hijo_der() == NO_EXISTE) && (nodo_abb->obtener_hijo_izq() == NO_EXISTE)){
                caso_sin_hijos(nodo_abb);
            }else if((nodo_abb->obtener_hijo_der() != NO_EXISTE) && (nodo_abb->obtener_hijo_izq() != NO_EXISTE)){
                aux = caso_dos_hijos( aux, nodo_abb->obtener_hijo_der());
                if(nodo_abb->obtener_padre() == NO_EXISTE){
                    nodo_abb->asignar_padre(NO_EXISTE);
                    raiz = nodo_abb;
                }
            }else{
                caso_un_hijo(nodo_abb);
            }
            tam_abb--;
            borrado = true;
            delete aux;
        }
    }else{
        cout<<"Error al borrar "<<clave<<": Codigo de hoja No Existe"<<endl;
    }
}

/*DESTRUCTOR - METODO DEL DESTRUCTOR*/

template<typename Dato>
void Abb<Dato>::liberar_hojas(Nodo_abb<Dato>* hoja){
    if(hoja != (Nodo_abb<Dato>*)NO_EXISTE){
        liberar_hojas(hoja->obtener_hijo_izq());
        liberar_hojas(hoja->obtener_hijo_der());
        cout<<"Codigo de hoja "<<hoja->obtener_clave()<<": liberado"<<endl;
        delete hoja;
    }
}

template<typename Dato>
Abb<Dato>::~Abb(){
    cout<<"Destructor Abb"<<endl;
    liberar_hojas(raiz);
}







#endif /*_ABB_H_*/
