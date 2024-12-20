/*  Autor: Jhoan Daniel Arenas Reyes
    Fecha: 06/Dic/2024
    Descripción: Ejmeplo cola*/

#include <stdio.h>
#include <stdlib.h>

/* ------------------------------> Implementación de la cola <------------------------------ */
struct nodoCola{
    char Nombre;
    int Edad;
    struct nodoCola *ptrSiguiente;
};

typedef struct nodoCola NodoCola;
typedef NodoCola *ptrNodoCola;
/*Prototipos Cola*/
void imprimeCola(ptrNodoCola ptrActual);
int estaVacia(ptrNodoCola ptrCabeza);
void retirar(ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon);
void agregar(ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon, char Nombre, int Edad);
void instruccionesCola(void);

void instruccionesCola(void){
    printf("<------Este programa puede ingresar y retirar elementos de una cola------>\n");
    printf("Introduzca su eleccion:\n"
    "1 para agregar un nombre a la cola\n"
    "2 para eliminar un nombre de la cola\n"
    "3 para terminar\n");
}

int estaVacia(ptrNodoCola ptrCabeza){
    return ptrCabeza == NULL;
}

void agregar(ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon, char nombre, int edad){
    ptrNodoCola ptrNuevo;
    ptrNuevo = malloc(sizeof(NodoCola));

    if(ptrNuevo != NULL){
        ptrNuevo->Nombre = nombre;
        ptrNuevo->Edad = edad;
        ptrNuevo->ptrSiguiente = NULL;

        if(estaVacia(*ptrCabeza)){
            *ptrCabeza = ptrNuevo;
        }else{
            (*ptrTalon)->ptrSiguiente = ptrNuevo;
        }
        *ptrTalon = ptrNuevo;
    }else{
        printf("no se inserto %c. No hay memoria disponible.\n", nombre);
    }
}

void retirar(ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon){
    char nombre;
    int edad;
    ptrNodoCola tempPtr;
    
    nombre = (*ptrCabeza)->Nombre;
    nombre = (*ptrCabeza)->Edad;
    tempPtr = *ptrCabeza;
    *ptrCabeza = (*ptrCabeza)->ptrSiguiente;

    if(*ptrCabeza == NULL){
        *ptrTalon = NULL;
    }
    printf("Se retiro el elemento de la cola\n");
    free(tempPtr);
}

void imprimeCola(ptrNodoCola ptrActual){
    if(ptrActual == NULL){
        printf("La cola esta vacia.\n\n");
    }else{
        printf("La cola es:\n");

        while (ptrActual != NULL)
        {
            printf("Nombre: %c, Edad: %d ->", ptrActual->Nombre, ptrActual->Edad);
            ptrActual = ptrActual->ptrSiguiente;
        }
        printf("NULL\n\n");
    }
}

void funcionCola(){
    ptrNodoCola ptrCabeza = NULL;
    ptrNodoCola ptrTalon = NULL;
    int eleccion;
    char nombre;
    int edad;

    instruccionesCola(); /*Despliega el menú*/
    printf("Opc(1,2,3)= ");
    scanf("%d", &eleccion);
    while(eleccion != 3){
        switch (eleccion)
        {
        case 1:
            printf("Introduzca un caracter para el nombre: ");
            scanf(" %c", &nombre);
            printf("Introduzca la edad: ");
            scanf("%d", &edad);
            agregar(&ptrCabeza, &ptrTalon, nombre, edad);
            imprimeCola(ptrCabeza);
            break;
        case 2:
            if(!estaVacia(ptrCabeza)){
                retirar(&ptrCabeza, &ptrTalon);
            }
            imprimeCola(ptrCabeza);
            break;
        default:
            printf("Elección no valida.\n\n");
            instruccionesCola();
            break;
        }
        printf("Opc(1,2,3)= ");
        scanf("%d", &eleccion);
    }
}

/* ------------------------------> Implementación de la pila <------------------------------ */
/*Estructura auto-referenciada*/
struct nodoPila{
    char dato;
    struct nodoPila *ptrSiguiente; /*Apuntador a nodoPila*/
};

typedef struct nodoPila NodoPila; /*Sinónimo de la estructura nodoPila*/
typedef NodoPila *ptrNodoPila; /*Sinónimo para Nodopila*/

/*Prototipos*/
void empujar(ptrNodoPila *ptrCima, char info);
char sacar(ptrNodoPila *ptrCima);
int estaVaciaPila(ptrNodoPila ptrCima);
void imprimePila(ptrNodoPila ptrActual);
void instruccionesPila(void);

void instruccionesPila(void){
    printf("Este programa muestra un ejemplo de una pila\n");
    printf("Introduzca su eleccion:\n"
    "1 para empujar un valor dentro de la pila\n"
    "2 para sacar un valor de la pila\n"
    "3 para terminar un programa\n");
}

void empujar(ptrNodoPila *ptrCima, char info){
    ptrNodoPila ptrNuevo;
    ptrNuevo = malloc(sizeof(NodoPila));

    if(ptrNuevo != NULL){
        ptrNuevo->dato = info;
        ptrNuevo->ptrSiguiente = *ptrCima;
        *ptrCima = ptrNuevo;
    }else{
        printf("%c no se inserto. Memoria insuficiente.\n", info);
    }
}

char sacar(ptrNodoPila *ptrCima){
    ptrNodoPila ptrTemp;
    char valorElim;

    ptrTemp = *ptrCima;
    valorElim = (*ptrCima)->dato;
    *ptrCima = (*ptrCima)->ptrSiguiente;
    free(ptrTemp);

    return valorElim;
}

void imprimePila(ptrNodoPila ptrActual){
    if(ptrActual == NULL){
        printf("La pila esta vacia.\n\n");
    }else{
        printf("La pila es:\n");

        while (ptrActual != NULL)
        {
            printf("%c ->", ptrActual->dato);
            ptrActual = ptrActual->ptrSiguiente;
        }
        printf("NULL\n\n");
    }
}

int estaVaciaPila(ptrNodoPila ptrCima){
    return ptrCima == NULL;
}

void funcionPila(){
    ptrNodoPila ptrPila = NULL;
    int eleccion;
    char valor;

    instruccionesPila(); /*Despliega el menú*/
    printf("? ");
    scanf("%d", &eleccion);


    while(eleccion != 3){

        switch (eleccion)
        {
        case 1:
            printf("Introduzca una letra: ");
            scanf(" %c", &valor);
            empujar(&ptrPila, valor);
            imprimePila(ptrPila);
            break;
        case 2:
            if(!estaVaciaPila(ptrPila)){
                printf("El valor sacado es %c. \n", sacar(&ptrPila));
            }
            imprimePila(ptrPila);
            break;
        default:
            printf("Elección no valida.\n\n");
            instruccionesPila();
            break;
        }
        printf("? ");
        scanf("%d", &eleccion);
    }
}

/* ------------------------------> Implementación de la Lista circular doble <------------------------------ */
struct Alumno{
    char Nombre[10];
    char Boleta[10];
    int Edad;
    struct Alumno *sig;
    struct Alumno *prev;   
};
struct Alumno *inicio = NULL, *fin = NULL, *aux;

void CrearLista(){
    // Si está vacía la lista crea el priimer nodo
    printf("Ingresa los siguientes datos:\n");
    if (inicio == NULL){
        inicio = (struct Alumno *)malloc(sizeof(struct Alumno));
        fin = inicio;
        printf("\nNombre: ") ;
        scanf("%s", inicio->Nombre);
        inicio->sig = inicio;
        inicio->prev = inicio;
    }
    else{
        printf("\nLa lista ya existe !!!\n");
    }
}

void AgregarElementos(){
    // Agregar elementos en La Lista
    int opcion = 1;
    printf("\nAgregar otro elemento a la lista\n");
    printf("Ingresa los siguientes datos:\n");
    if (fin == NULL){
        printf("No se ha creado la lista!!\n");
    }
    else{
        while (opcion == 1){
            struct Alumno *nuevo = (struct Alumno *)malloc(sizeof(struct Alumno));
            printf("\nNombre:");
            scanf("%s", nuevo->Nombre);

            nuevo->sig = inicio; 
            nuevo->prev = fin;
            fin->sig = nuevo;
            inicio->prev = nuevo;
            fin = nuevo;

            printf("\nAgregar otro? presione 1 o otro numero para salir:");
            scanf("%d", &opcion);
        }
    }
}

void MostrarElementos(){
    printf("\nLectura de la lista circular doble de izquierda a derecha:\n");
    if (inicio == NULL){
        printf("\nNo hay Lista!!!");
    }
    else{
        aux = inicio;
        int contador=0;
        do {
            printf("%s -> ", aux->Nombre);
            aux = aux->sig;
            if (aux == inicio) {
                contador++;
            }
        } while (aux != inicio);
        printf("\n");
    }

    printf("\nLectura de la lista circular doble de derecha a izquierda:\n");
    if (fin == NULL) {
        printf("No hay lista para recorrer!!!\n");
    } else {
        struct Alumno *aux = fin;
        do {
            printf("%s -> ", aux->Nombre);
            aux = aux->prev;
        } while (aux != fin);
        printf("*\n");
    }
}

void funcionListaCircularDoble(){
    printf("Programa para trabajar con una Lista\n");
   int opcion;

    do {
        printf("\n======= Menu =======\n");
        printf("1. Crear lista\n");
        printf("2. Agregar elementos\n");
        printf("3. Mostrar elementos\n");
        printf("4. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                CrearLista();
                break;
            case 2:
                AgregarElementos();
                break;
            case 3:
                MostrarElementos();
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion incorrecta. Intenta de nuevo.\n");
        }
    } while (opcion != 4);
}
/* ------------------------------> Implementación de la Lista doblemente enlazada <------------------------------ */

struct AlumnoListaDoble {
    char Nombre[10];
    char Boleta[10];
    int Edad;
    struct AlumnoListaDoble *sig;
    struct AlumnoListaDoble *ant;
};

struct AlumnoListaDoble *inicioListaDoble = NULL, *finListaDoble = NULL, *auxListaDoble = NULL;

void CrearListaDoble() {
    printf("Ingresa los siguientes datos:\n");
    if (inicioListaDoble == NULL) {
        inicioListaDoble = (struct AlumnoListaDoble *)malloc(sizeof(struct AlumnoListaDoble));
        finListaDoble = inicioListaDoble;
        printf("\nNombre: ");
        scanf("%s", inicioListaDoble->Nombre);
        /*printf("\nBoleta: ");
        scanf("%s", inicioListaDoble->Boleta);
        printf("\nEdad : ");
        scanf("%d", &inicioListaDoble->Edad);*/
        inicioListaDoble->sig = NULL;
        inicioListaDoble->ant = NULL;
    } else {
        printf("\nLa lista ya existe !!!\n");
    }
}

void AgregarElementosListaDoble() {
    int opcion = 1;
    printf("\nAgregar otro elemento a la lista\n");
    printf("Ingresa los siguientes datos:\n");
    if (finListaDoble == NULL) {
        printf("No se ha creado la lista!!\n");
    } else {
        while (opcion == 1) {
            struct AlumnoListaDoble *nuevo = (struct AlumnoListaDoble *)malloc(sizeof(struct AlumnoListaDoble));
            printf("\nNombre: ");
            scanf("%s", nuevo->Nombre);
            /*printf("Boleta: ");
            scanf("%s", nuevo->Boleta);
            printf("Edad: ");
            scanf("%d", &nuevo->Edad);*/

            nuevo->sig = NULL;
            nuevo->ant = finListaDoble;
            finListaDoble->sig = nuevo;
            finListaDoble = nuevo;

            printf("\nAgregar otro? presione 1 o otro numero para salir: ");
            scanf("%d", &opcion);
        }
    }
}

void MostrarElementosListaDoble() {
    printf("\n<<<<<<Mostrando los elementos de la lista>>>>>>\n");

    if (inicioListaDoble == NULL) {
        printf("\nNo hay Lista!!!\n");
        return;
    }

    // Mostrar en orden ascendente
    printf("\nRegistros de forma ascendente:\n");
    auxListaDoble = inicioListaDoble;
    while (auxListaDoble != NULL) {
        printf("%s ", auxListaDoble->Nombre);
        /*printf(", Boleta: %s, Edad: %d -> ", auxListaDoble->Boleta, auxListaDoble->Edad);*/
        auxListaDoble = auxListaDoble->sig;
    }
    printf("*\n");

    // Mostrar en orden descendente
    printf("\nRegistros de forma descendente:\n");
    auxListaDoble = finListaDoble;
    while (auxListaDoble != NULL) {
        printf("%s ", auxListaDoble->Nombre);
        /*printf(", Boleta: %s, Edad: %d -> ", auxListaDoble->Boleta, auxListaDoble->Edad);*/
        auxListaDoble = auxListaDoble->ant;
    }
    printf("*\n");
}

void funcionListaDoblementeEnlazada(){
    int opcion;

    printf("Programa para trabajar con una Lista Doble\n");

    do {
        printf("\n======= Menu =======\n");
        printf("1. Crear lista\n");
        printf("2. Agregar elementos\n");
        printf("3. Mostrar elementos\n");
        printf("4. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                CrearListaDoble();
                break;
            case 2:
                AgregarElementosListaDoble();
                break;
            case 3:
                MostrarElementosListaDoble();
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion incorrecta. Intenta de nuevo.\n");
        }
    } while (opcion != 4);
}

void menuPrincipal() {
    int opcion;
    do {
        printf("----------- MENU PRINCIPAL -----------\n");
        printf("1. Lista doblemente enlazada\n");
        printf("2. Lista circular doblemente enlazada\n");
        printf("3. Pila\n");
        printf("4. Cola\n");
        printf("5. Salir\n");
        printf("--------------------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                funcionListaDoblementeEnlazada();
                break;
            case 2:
                funcionListaCircularDoble();
                break;
            case 3:
                funcionPila();
                break;
            case 4:
                funcionCola();
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Ingrese un numero del menu \n");
        }
        printf("\n");
    } while(opcion != 5);
}


int main()
{
    printf("\nPrograma hecho por:\n");
    printf("Alumno: Jhoan Daniel Arenas Reyes\n");
    printf("Matricula: 2203025078\n");

    printf("\nEste programa nos permite tener las funciones de una lista doble, lista circular doblemente enlazada, pilas y colas\n");
    menuPrincipal();
    return 0;
}

