//
//  main.c
//  Comedor
//
//  Created by Sebastián Silva García on 3/21/16.
// ModifiedBY Gerry ps. Sebas es puto

#include <stdio.h>
#include <stdlib.h>
//Declaramos las estructuras tipo nodo llamadas empleado y fila que utilizaremos
struct Empleado{
    int id;
    char *nombre;
    int salario;
    struct Empleado *siguiente;

};
struct Fila{
    struct Empleado *primero;
    struct Empleado *ultimo;
    
};

//Declaramos las funciones para encolar y desencolar empleados.
void encolar(struct Fila *fila, int id, char *nombre, int salario);
char * desencolar(struct Fila *fila);





int main(int argc, const char * argv[]) {
    struct Fila nueva;
    encolar(&nueva, 1, "sebas", 2345);
    encolar(&nueva, 3, "se33bas", 2545);
    encolar(&nueva, 4, "seeebas", 23245);
    printf("%s\n", desencolar(&nueva));
    printf("%s\n", desencolar(&nueva));



        return 0;
}




//Funciones encolar y desencolar
void encolar(struct Fila *fila, int id, char *nombre, int salario){
    struct Empleado *nuevo;
    nuevo = (struct Empleado *)malloc(sizeof(struct Empleado));
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->salario  = salario;
    
    //Si está vacía la cola
    if ((*fila).primero == NULL){
        fila->primero = nuevo;
        fila->ultimo = nuevo;
    }else {
        //Si la cola no está vacía...
        fila->ultimo->siguiente = nuevo;
        fila->ultimo = nuevo;
    }
}


char * desencolar(struct Fila *fila){
    struct Empleado *aux;
    char *nombre;
    if (fila->primero == NULL){
        printf("No hay empleados esperando \n");
        return "";
    }
    aux = fila->primero;
    nombre = aux->nombre;
    if (fila->primero == fila->ultimo){
        fila->primero = NULL;
        fila->ultimo = NULL;
    }else{
        fila->primero = aux->siguiente;
    }
    free(aux);
    return nombre;
    
}








