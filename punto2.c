#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion;
    int Duracion; // entre 10 – 100
}typedef Tarea;

void main()
{

    int cant=0;
    //Cantidad de tareas a realizar
    printf("\nIngrese la cantidad de tareas: ");
    scanf("%d",&cant);
    fflush(stdin);

    //Generar arreglo de doble puntero

    Tarea **Tareas = (Tarea**) malloc (cant*sizeof(Tarea*));

    for (int i = 0; i < cant; i++)
    {
        Tareas[i]=NULL;
    }
    
    //Cargar Tareas

    for (int j = 0; j < cant; j++)
    {
        //Asignacion de la tarea e id
        Tareas[j] = (Tarea*)malloc(sizeof(Tarea));
        Tareas[j]->TareaID = j+1;
        //Ingresar la descripcion

        int cantLetra = 0;
        char descripcion[100];

        printf("\n Escribir la descripcion: ");
        gets(descripcion);
        fflush(stdin);
        cantLetra = strlen(descripcion);
        fflush(stdin);
        Tareas[j]->Descripcion=(char*)malloc(sizeof(char)*cantLetra);
        strcpy(Tareas[j]->Descripcion,descripcion);
        fflush(stdin);

        //Ingresar duracion

        
            printf("Ingrese la duracion de la tarea entre 10 y 100: %d" );
            scanf("%d",Tareas[j]->Duracion);
            fflush(stdin);
        
    }

        for (int i = 0; i < cant; i++)
        {
            printf("\nLa tarea es: %s",Tareas[i]->Descripcion);
            printf("\nEl id es: %d",Tareas[i]->TareaID);
            printf("\nLa tarea dura: %d",Tareas[i]->Duracion);
        }
    






}

