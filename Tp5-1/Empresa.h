#ifndef _EMPRESA_H_
#define _EMPRESA_H_

#include "Abb.h"
#include "Individuo.h"
#include "Familia.h"
#include "Cliente.h"
#include <fstream>
#include <sstream>


const int OPCION_NULA = -1;
const int PRECIO_BASE_NULO = -1;
const int PRECIO_BASE_MINIMO = 0;
const int MAX_NOMBRE = 14;
const char BASE_DATOS[MAX_NOMBRE] = "clientes.txt";
const string LINEA_DATO_NULA = "LINEA_DATO_NULA";
const char COMA = ',';
const int STRING_POS_INICIAL = 0;
const int SIN_INTEGRANTES = 0;
const int TELEFONO_NULO = -1;

const int LISTAR_CLIENTES = 1;
const int BUSCAR_CLIENTE = 2;
const int AGREGAR_CLIENTE = 3;
const int DAR_BAJA = 4;
const int ACTUALIZAR_PRECIO_SUSCRIP = 5;
const int SALIR = 6;

const int SIN_DATO = -1;

class Empresa{
    private:
    /*ATRIBUTOS*/

        int opcion;
        int precio_base;
        Abb<Cliente*> clientes;
    public:
    /*CONSTRUCTOR*/

        /*Descripcion: Constructor de la clase Empresa, inicializara los atributos correctamente.
         *Pre: precio_base >= 0.
         *Post: Inicializa los atributos correctamente.
        */
        Empresa();

    public:
    /*METODOS ASIGNAR-OBTENER*/

        /*Descripcion: Devuelve el atributo "precio_base".
         *Pre: -.
         *Post: Devuelve el atributo "precio_base".
        */
        int obtener_precio_base();

        /*Descripcion: Actualiza el atributo "precio_base".
         *Pre: precio_base >= 0.
         *Post: Actualiza el atributo "precio_base".
        */
        void asignar_precio_base(int precio_base);

    public:
    /*METODOS*/

        /*Descripcion: Inicializa el funcionamiento del objeto.
         *Pre: -.
         *Post: Abre la Empresa permitiendo al usuario elegir entre varias opciones mediante el menu.
        */
        void abrir_empresa();

        /*Descripcion: Abre el archivo requerido para comenzar a cargar los datos del mismo.
         *Pre: Archivo "clientes.txt" correctamente definido. (CSV)
         *Post: Los datos del archivo "clientes.txt" son cargados como corresponde al Abb "clientes".
        */
        void cargar_base_datos();

        /*Descripcion: Ejecuta la opcion correspondiente al valor del atributo "opcion".
         *Pre: -.
         *Post: Ejecuta la opcion correspondiente al valor del atributo "opcion".
        */
        void ejecutar_opcion();

        /*Descripcion: Realiza la lectura en la primer linea del archivo, guarda el dato "telefono" obtenido mediante las condiciones
                       utilizadas y recorta la linea obtenida para luego usarse en diferenciar_cliente.
         *Pre: -.
         *Post: Guarda el dato "telefono" y acciona el metodo diferenciar_cliente.
        */
        void operar_informacion(string linea_dato);

        /*Descripcion: Dependiendo de las condiciones el metodo diferencia si el nuevo Cliente es un Individuo o Familia.
                        Al detectar el Cliente guarda la informacion requerida y utiliza el metodo verificar_telefono.
         *Pre: -.
         *Post: Al verificarse la disponibilidad del "telefono" agrega al Abb "clientes" el nuevo Cliente.
        */
        void diferenciar_cliente(string linea_nombres, int telefono);

        /*Descripcion: Al detectarse un nuevo Cliente Familia, guarda los nombres agregandolos a la correspondiente Lista "integrantes".
         *Pre: -.
         *Post: Guarda los nombres del nuevo Cliente en la Lista correspondiente de la nueva Familia.
        */
        void agregar_nombres(string linea_nombres, Familia* nueva_familia);

        /*Descripcion: Si el numero de "telefono" esta asignado, vuelve a intentar con el mismo numero sumandole uno(1)
                       hasta que se logre verificar su disponibilidad y procede a agregarlo al Abb "clientes"
         *Pre: -.
         *Post: Al verificarse la disponibilidad del "telefono" agrega al Abb "clientes" el nuevo Cliente.
        */
        void verificar_telefono(Cliente* nuevo_cliente, int telefono);

        /*Descripcion: Informa el uso de este metodo y utiliza inorder_cliente para luego proceder a usar mostrar_cliente.
         *Pre: "tam_abb" de Abb "clientes" >0.
         *Post: Informa el uso de este metodo y utiliza inorder_cliente para luego proceder a usar mostrar_cliente.
        */
        void listar_datos_clientes();

        /*Descripcion: Accede al Abb de tal forma que muestra la clave de los clientes actuales para luego utilizar
                       mostrar_cliente en orden ascendente.
         *Pre: "tam_abb" de Abb "clientes" >0.
         *Post: Informa el uso de este metodo y utiliza inorder_cliente para luego proceder a usar mostrar_cliente.
        */
        void inorder_cliente(Nodo_abb<Cliente*>* dato);

        /*Descripcion: Muestra la informacion del Cliente recibido.
         *Pre: -.
         *Post: Muestra la informacion del Cliente recibido.
        */
        void mostrar_cliente(Cliente* cliente);

        /*Descripcion: Buscara al cliente mediante el "telefono" recibido.
         *Pre: -.
         *Post: Muestra la informacion del Cliente correspondiente, en caso de no encontrarse se informa.
        */
        void buscar_cliente(int telefono);

        /*Descripcion: Agrega un nuevo Cliente al Abb "clientes" con un nuevo "telefono".
         *Pre: -.
         *Post: Agrega un nuevo Cliente al Abb "clientes".
        */
        void agregar_cliente();

        /*Descripcion: Procede a buscar el Cliente solicitado para realizar la baja, en caso
                       de no existir se proced a informar.
         *Pre: -.
         *Post: Da de baja a un Cliente del Abb "clientes", en caso de no encontrarse se informa por consola.
        */
        void dar_baja(int telefono_baja);

    private:
    /*METODO DEL DESTRUCTOR*/
        /*Descripcion: Libera la memoria utilizada en el "contenido" de la hoja actual.
         *Pre: -.
         *Post: Libera la memoria utilizada en el "contenido" de la hoja actual.
        */
        void vaciar_datos(Nodo_abb<Cliente*>* hoja);

    public:
    /*DESTRUCTOR*/

        /*Descripcion: Destructor de la clase Empresa, libera la memoria dinamica usada en el "contenido" del Abb "clientes".
         *Pre: -.
         *Post: Libera la memoria dinamica usada en el "contenido" del Abb "clientes".
        */
        ~Empresa();
};

#endif /*_EMPRESA_H_*/
