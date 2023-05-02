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

void buscarTareaID(int id, int cantidad, Tarea **lista)
{
    int resultado =0;

    for (int i = 0; i < cantidad; i++)
    {
        if (id == lista[i]->TareaID)
        {
            printf("\n La tarea obtenida es %s",lista[i]->Descripcion);
            resultado = 1;  
        }
    }
    if (resultado==0){
        printf("\nNo se encontro tarea con ese id.");
    }
}

void buscarTareaPalabra(char *palabra,int cantidad,Tarea **lista){
   int resultado =0;

    for (int i = 0; i < cantidad; i++)
    {
        if (strstr(lista[i]->Descripcion,palabra))
        {
            printf("\n La tarea obtenida es %s",lista[i]->Descripcion);
            resultado = 1;  
        }
    }
    if (resultado==0){
        printf("\nNo se encontro tarea con esa palabra.");
    }
}

int main()
{
    srand(time(NULL));

        int canTareas, realizar,opcion=0;
        int resultado,id;
        char *palabraBuscada;
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
            TareaNueva->Descripcion=malloc(MAX*sizeof(char)); 
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
        printf("\n3.Buscar Tarea por ID");
        printf("\n4.Buscar Tarea por palabra");
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
            }else if (opcion == 2){
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
            }else if (opcion==3)
            {
                printf("\n El ID buscado es: ");
                scanf("%d",&id);
                buscarTareaID(id,canTareas,ListaTareas);
            }else if(opcion ==4)
            {
                palabraBuscada = (char *)malloc(MAX*sizeof(char));
                printf("\n La palabra buscada es: ");
                fflush(stdin);
                gets(palabraBuscada);
                buscarTareaPalabra(palabraBuscada,canTareas,ListaTareas);
            }
            
                   
        printf("\n---------------------------------");
        printf("\n MENU");
        printf("\n0.Salir");
        printf("\n1.Ver tareas pendientes");
        printf("\n2.Ver tareas realizadas");
        printf("\n3.Buscar Tarea por ID");
        printf("\n4.Buscar Tarea por palabra");
        printf("\n---------------------------------");
        printf("\n Elegir opcion: ");
        scanf("%d",&opcion);

}


    return 0;
}

/* 6. Cree un nuevo branch llamado busca-tarea e implemente una función de
búsqueda de tarea por nro. de id de nombre BuscarTarea. La misma devuelve
la tarea solicitada.
7. Vuelva al branch main e implemente también una nueva versión de la función
BuscarTarea en donde la misma sea por palabra clave en vez de por Id. (uno
le manda una palabra y te tiene que devolver la primera tarea que contenga
dicha palabra).
Nota: Para realizar este punto, investigue el uso de la función strstr.
8. Realizar el merge correspondiente y resuelva el conflicto producido.
Finalmente modifique los nombres de las funciones a BuscaTareaPorId y otra
BuscaTareaPorPalabra.
9. Agregue una interfaz de usuario al programa principal que permita consultar
tareas por id y palabra clave y mostrarlas por pantalla. */