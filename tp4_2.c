#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 50
struct
{
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion;
    int Duracion; // entre 10 – 100
}typedef Tarea;

int main()
{
    srand(time(NULL));

        int canTareas, realizar,opcion=0;
        printf("Indique la cantidad de tareas a cargar: ");
        scanf("%d",&canTareas);
        Tarea **ListaTareas;
        Tarea **TareasRealizadas;

        TareasRealizadas=(Tarea **)malloc(canTareas*sizeof(Tarea *));
        
        ListaTareas = (Tarea **) malloc(canTareas*sizeof(Tarea *));
        //Inicializo los arreglos apuntando a NULL
        for (int i = 0; i < canTareas; i++)
            {
                ListaTareas[i]=NULL;
                TareasRealizadas[i]=NULL;
            }

        //CARGAR TAREAS
        for (int i = 0; i < canTareas; i++)
        {
            Tarea *TareaNueva;
            TareaNueva = (Tarea *) malloc(sizeof(Tarea)); 
            TareaNueva->TareaID=i+1;
            TareaNueva->Descripcion=malloc(MAX*sizeof(char*)); 
            printf("\n Descripcion de la tarea: ");
            fflush(stdin);
            gets(TareaNueva->Descripcion);
            TareaNueva->Duracion=10+rand()%100;
            fflush(stdin);
            ListaTareas[i]= TareaNueva;
        }

        //menu

        printf("\n---------------------------------");
        printf("\n MENU");
        printf("\n0.Salir");
        printf("\n1.Ver tareas pendientes");
        printf("\n2.Ver tareas realizadas");
        printf("\n---------------------------------");
        printf("\n Elegir opcion: ");
        scanf("%d",&opcion);


        while (opcion!=0)
        {
            if (opcion == 1)
            {
                for (int i = 0; i < canTareas; i++)
                    {
                        if (ListaTareas[i]==NULL)
                        {
                            printf("\nYa se realizo la tarea %d",i+1);
                            
                        }else{
                            printf("\n---ID=%d---",ListaTareas[i]->TareaID);
                            printf("\nDescripcion: %s",ListaTareas[i]->Descripcion);
                            printf("\nLa duracion es %d",ListaTareas[i]->Duracion);
                            printf("\nSe realizo la tarea?\n1.SI\n2.NO\n");
                            scanf("%d",&realizar);
                        }
                        
                        if (realizar==1)
                        {
                            Tarea *tareaRealizada;
                            tareaRealizada = (Tarea *)malloc(sizeof(Tarea));
                            tareaRealizada->Descripcion=ListaTareas[i]->Descripcion;
                            tareaRealizada->TareaID=ListaTareas[i]->TareaID;
                            tareaRealizada->Duracion=ListaTareas[i]->Duracion;
                            TareasRealizadas[i]=tareaRealizada;
                            ListaTareas[i]=NULL;
                            realizar=0;
                        }
                        
                    } 
            }else if (opcion == 2)
                for (int i = 0; i < canTareas; i++) 
                    {
                        if (TareasRealizadas[i]==NULL)
                        {
                            printf("\nNo se realizo la tarea %d",i+1);
                        }else{
                            printf("\n---ID=%d---",TareasRealizadas[i]->TareaID);
                            printf("\nDescripcion: %s",TareasRealizadas[i]->Descripcion);
                            printf("\nLa duracion es %d",TareasRealizadas[i]->Duracion);
                        }
                    }
        printf("\n---------------------------------");
        printf("\n MENU");
        printf("\n0.Salir");
        printf("\n1.Ver tareas pendientes");
        printf("\n2.Ver tareas realizadas");
        printf("\n---------------------------------");
        printf("\n Elegir opcion: ");
        scanf("%d",&opcion);
        }


    return 0;
}
