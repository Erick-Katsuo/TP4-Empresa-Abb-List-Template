#include "Empresa.h"

/*CONSTRUCTOR*/

Empresa::Empresa(){
    this->opcion = OPCION_NULA;
    cout<<"Constructor Empresa"<<endl;
    cout<<"Bienvenido a la Empresa Telefonica: Andy & Co"<<endl;
    cout<<"Ingrese el precio base actual de la suscripcion mensual"<<endl;
    cout<<"Coste de suscripcion actual: $";
    cin>>(this->precio_base);
}

/*METODOS ASIGNAR-OBTENER*/

int Empresa::obtener_precio_base(){
    return precio_base;
}


void Empresa::asignar_precio_base(int precio_base){
    this->precio_base = precio_base;
}

/*METODOS*/

void Empresa::ejecutar_opcion(){
    int dato = SIN_DATO;
    switch(opcion){
        case LISTAR_CLIENTES:
            listar_datos_clientes();
            cout<<endl<<endl;
            break;
        case BUSCAR_CLIENTE:
            cout<<"Ingrese telefono"<<endl;
            cin>>dato;
            buscar_cliente(dato);
            cout<<endl<<endl;
            break;
        case AGREGAR_CLIENTE:
            agregar_cliente();
            cout<<endl<<endl;
            break;
        case DAR_BAJA:
            cout<<"Ingrese telefono a dar de baja"<<endl;
            cin>>dato;
            dar_baja(dato);
            cout<<endl<<endl;
            break;
        case ACTUALIZAR_PRECIO_SUSCRIP:
            cout<<"Ingrese nuevo precio de suscrip"<<endl;
            cin>>dato;
            asignar_precio_base(dato);
            cout<<endl<<endl;
            break;
        case SALIR:
            cout<<"Termino el laburo wiiii"<<endl<<endl;
            break;
        default:
            cout<<"Ingreso no aceptado"<<endl;
    }
}

void Empresa::abrir_empresa(){
    cargar_base_datos();
    while(opcion != 6){
        cout<<"\t\tOpciones Laburo"<<endl;
        cout<<"Listar clientes                 [1]"<<endl;
        cout<<"Buscar cliente                  [2]"<<endl;
        cout<<"Agregar cliente                 [3]"<<endl;
        cout<<"Dar baja cliente                [4]"<<endl;
        cout<<"Actualizar precio suscripcion   [5]"<<endl;
        cout<<"Salir del laburo                [6]"<<endl;
        cin>>opcion;
        ejecutar_opcion();
    }
}

void Empresa::agregar_nombres(string linea_nombres, Familia* nueva_familia){
    unsigned pos = linea_nombres.find(COMA);
    string nombre = SIN_NOMBRE;
    if(linea_nombres[pos]==COMA){
        nombre = linea_nombres.substr(STRING_POS_INICIAL, pos);
        nueva_familia->obtener_list_integrantes()->agregar_nodo(nombre, 1);
        linea_nombres.erase(STRING_POS_INICIAL,pos+1);
        agregar_nombres(linea_nombres, nueva_familia);
    }else{
        nombre = linea_nombres.substr(pos+1);
    }
}

void Empresa::verificar_telefono(Cliente* nuevo_cliente, int telefono){
    if(! ( clientes.insertar_raiz(nuevo_cliente, telefono) )){
        cout<<"Numero ocupado, intentando con nuevo telefono: "<<telefono+1<<"..."<<endl;
        verificar_telefono(nuevo_cliente, telefono+1);
    }else{
        cout<<"Cliente agregado"<<endl;
    }
}

void Empresa::diferenciar_cliente(string linea_nombres, int telefono){
    unsigned pos = linea_nombres.find(COMA);
    string nombre = SIN_NOMBRE;
    if(linea_nombres[pos]==COMA){
        Familia* nueva_familia = new Familia();
        agregar_nombres(linea_nombres, nueva_familia);
        verificar_telefono(nueva_familia, telefono);
    }else{
        nombre = linea_nombres.substr(pos+1);
        Individuo* nuevo_individuo = new Individuo(nombre);
        verificar_telefono(nuevo_individuo, telefono);
    }
}


void Empresa::operar_informacion(string linea_dato){
    unsigned pos = linea_dato.find(COMA);
    int numero_telefono;
    string telefono = linea_dato.substr(STRING_POS_INICIAL, pos);
    stringstream convertir(telefono);
    convertir>>numero_telefono;
    linea_dato.erase(STRING_POS_INICIAL,pos+1);
    diferenciar_cliente(linea_dato, numero_telefono);
}

void Empresa::cargar_base_datos(){
    ifstream base_datos(BASE_DATOS);
    string linea_dato = LINEA_DATO_NULA;
    while (getline(base_datos, linea_dato)) {
        operar_informacion(linea_dato);
    }
}



void Empresa::mostrar_cliente(Cliente* cliente){
    cliente->mostrar_descuento(this->precio_base);
    cliente->mostrar_registrados();
    cout<<endl<<endl;
}

void Empresa::inorder_cliente(Nodo_abb<Cliente*>* dato){
    if(dato != (Nodo_abb<Cliente*>*)PUNTERO_NULO_ABB){
        inorder_cliente(dato->obtener_hijo_izq());
        cout<<"Telefono: "<<dato->obtener_clave()<<endl;
        mostrar_cliente(dato->obtener_contenido());
        inorder_cliente(dato->obtener_hijo_der());
    }
}

void Empresa::listar_datos_clientes(){
    cout<<"\t\t\tListando Clientes: "<<endl;
    inorder_cliente(clientes.obtener_raiz());
}

void Empresa::buscar_cliente(int telefono){
    cout<<"\t\tBuscando cliente con numero "<<telefono<<"..."<<endl;
    if(clientes.buscar_nodo(telefono, clientes.obtener_raiz())){
          Cliente* aux_cliente = clientes.buscar_nodo(telefono, clientes.obtener_raiz())->obtener_contenido();
        if(aux_cliente){
            aux_cliente->mostrar_registrados();
        }
    }else{
        cout<<"El telefono ingresado no corresponde a un cliente registrado"<<endl;
    }
}

void Empresa::agregar_cliente(){
    int integrantes = SIN_INTEGRANTES;
    string nombre = SIN_NOMBRE;
    int nuevo_telefono = TELEFONO_NULO;
    cout<<"Ingrese su padron"<<endl;
    cin>>nuevo_telefono;
    cout<<"Ingrese la cantidad de registros que desea ralizar"<<endl;
    cin>>integrantes;
    if(integrantes != 1){
        Familia* nueva_familia = new Familia(integrantes);
        verificar_telefono(nueva_familia, nuevo_telefono);
    }else{
        cout<<"Ingrese su nombre"<<endl;
        cin>>nombre;
        Individuo* nuevo_individuo = new Individuo(nombre);
        verificar_telefono(nuevo_individuo, nuevo_telefono);
    }
}

void Empresa::dar_baja(int telefono_baja){
    cout<<"Dando de baja a un cliente"<<endl;
    if(clientes.buscar_nodo(telefono_baja, clientes.obtener_raiz())){
        delete (clientes.buscar_nodo(telefono_baja, clientes.obtener_raiz())->obtener_contenido());
        if(clientes.borrar_raiz(telefono_baja)){
            cout<<"Cliente con numero "<<telefono_baja<<" fue correctamente dado de baja"<<endl;
        }
    }else{
        cout<<"Error:"<<endl;
        cout<<"El telefono ingresado no corresponde a un cliente registrado"<<endl;
    }
}


/*METODO DEL DESTRUCTOR*/

void Empresa::vaciar_datos(Nodo_abb<Cliente*>* hoja){
    if(hoja != (Nodo_abb<Cliente*>*)NO_EXISTE){
        vaciar_datos(hoja->obtener_hijo_izq());
        vaciar_datos(hoja->obtener_hijo_der());
        cout<<"Contenido de hoja "<<hoja->obtener_clave()<<": liberado"<<endl;
        delete hoja->obtener_contenido();
    }
}

/*DESTRUCTOR*/

Empresa::~Empresa(){
    cout<<"Destructor Empresa"<<endl;
    vaciar_datos(clientes.obtener_raiz());
}






































