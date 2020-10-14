#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "motos.h"



void inicializarMotos(eMoto vec[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}
int altaMoto(int idX,eMoto vec[], int tam,eTipo tipos[], int tamTipos,eColor colores[],int tamColores)
{
    int todoOK = -1;
    int indice = buscarLibreMoto(vec,tam);
    char auxChar[51];
    int auxInt;

    eMoto auxMoto;
    system("cls");

    printf("***** ALTA MOTO *****\n\n");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }

    else
    {
        while(todoOK==-1)
        {
            //MARCA
            if((utn_getCadena(auxChar,21,2,"Ingrese la marca: ","Error. Reingrese la marca\n"))==0)
            {
                strcpy(auxMoto.marca,auxChar);
            }
            else
            {
                printf("Se quedo sin intentos para ingresar la marca\n");
                todoOK=0;
                break;
            }
            //TIPO
            mostrarDescripcionTipos(tipos,tamTipos);
            if((utn_getEntero(&auxInt,2,"Ingrese el tipo: ","Error. Reingrese el tipo\n",1000,1003))==0)
            {
                auxMoto.idTipo=auxInt;
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el tipo\n");
                todoOK=0;
                break;
            }
            //COLOR
            mostrarDescripcionColores(colores,tamColores);
            if((utn_getEntero(&auxInt,2,"Ingrese el color: ","Error. Reingrese el color\n",10000,10004))==0)
            {
                auxMoto.idColor=auxInt;
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el color\n");
                todoOK=0;
                break;
            }
            //CILINDRADA
            if((utn_getEntero(&auxInt,2,"Ingrese la cilindara: ","Error. Reingrese la cilindrada\n",0,751))==0)
            {
                auxMoto.cilindrada=auxInt;
                todoOK=1;
            }
            else
            {
                printf("Se quedo sin intentos para ingresar la cilindrada \n");
                todoOK=0;
                break;
            }

        }
        if(todoOK==1)
        {
            auxMoto.id = idX;

            auxMoto.isEmpty = 0;

            printf("El id de la nueva moto es: %d\n",idX);

            vec[indice] = auxMoto;
        }


    }


    return todoOK;
}
int buscarLibreMoto(eMoto vec[],int tam)
{

    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;

}
void mostrarDescripcionTipos(eTipo tipos[],int tamTipo)
{

    printf("\nListado de tipos\n");
    printf("id        Descripcion\n");

    for(int i=0; i<tamTipo; i++)
    {
        printf("%d      %10s\n",tipos[i].id,tipos[i].nombreTipo);
    }

}
void mostrarDescripcionColores(eColor colores[],int tamColores)
{

    printf("\nListado de colores\n");
    printf("id          Descripcion\n");

    for(int i=0; i<tamColores; i++)
    {
        printf("%d      %10s\n",colores[i].id,colores[i].nombreColor);
    }

}
void modificarMoto(eMoto vec[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[], int tamColores)
{
    int indice;
    int id;
    char confirma;
    int auxInt;

    system("cls");
    printf("***** MODIFICAR MOTO *****\n\n");

    mostrarMotos(vec,tamMotos,tipos,tamTipos,colores,tamColores);

    printf("\nIngrese el id: ");
    scanf("%d",&id);

    indice = buscarMoto(id,vec,tamMotos);

    if(indice== -1)
    {
        printf("No hay registro de algun empleado con el id: %d\n", id);
    }
    else
    {
        system("cls");
        printf("ID     MARCA     TIPO       COLOR     CILINDRADA \n");
        mostrarMoto(vec[indice],tipos,tamTipos,colores,tamColores);

        printf("\nConfirma modificar esta moto? : ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            switch(menuModificar())
            {
            case 'a':
                mostrarDescripcionColores(colores,tamColores);
                if((utn_getEntero(&auxInt,2,"Ingrese el nuevo color: ","Error. Reingrese el color\n",10000,10004))==0)
                {
                   vec[indice].idColor=auxInt;
                }
                else
                {
                    printf("Se quedo sin intentos para ingresar el color\n");
                }
                break;
            case 'b':
                if((utn_getEntero(&auxInt,2,"Ingrese la nueva cilindara: ","Error. Reingrese la cilindrada\n",0,751))==0)
                {
                    vec[indice].cilindrada=auxInt;
                }
                else
                {
                    printf("Se quedo sin intentos para ingresar la cilindrada \n");
                }
                break;
            case 'c':
                printf("\n\nSe cancelo la operacion");
                break;
            default:
                printf("\n\nIngrese una opcion valida.");
            }
        }
        else
        {
            printf("\n\nSe cancelo la operacion\n\n");
        }

    }

}
void mostrarMoto(eMoto x,eTipo tipos[],int tamTipos,eColor colores[], int tamColores)
{
    char nombreTipo[21];
    char nombreColor[21];

    cargarDescripcionTipo(nombreTipo,x.idTipo,tipos,tamTipos);
    cargarDescripcionColor(nombreColor,x.idColor,colores,tamColores);

    printf("%d     %6s    %6s     %6s        %d   \n",x.id,x.marca,nombreTipo,nombreColor,x.cilindrada);

}
int cargarDescripcionTipo(char tipo[],int id, eTipo tipos[], int tamTipos)
{
    int todoOK = 0;

    for(int i=0; i<tamTipos; i++)
    {
        if(tipos[i].id==id)
        {
            strcpy(tipo,tipos[i].nombreTipo);
            todoOK = 1;
        }
    }

    return todoOK;
}
int cargarDescripcionColor(char color[],int id, eColor colores[], int tamColores)
{
    int todoOK = 0;

    for(int i=0; i<tamColores; i++)
    {
        if(colores[i].id==id)
        {
            strcpy(color,colores[i].nombreColor);
            todoOK = 1;
        }
    }

    return todoOK;
}
void mostrarMotos(eMoto x[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[], int tamColores)
{
    int flag=0;
    system("cls");
    printf("\n*****LISTADO DE MOTOS *****\n");
    printf("ID     MARCA     TIPO       COLOR     CILINDRADA \n");

    for(int i=0; i<tamMotos; i++)
    {
        if(x[i].isEmpty == 0)
        {
            mostrarMoto(x[i],tipos,tamTipos,colores,tamColores);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNo hay motos que listar\n\n");
    }

}
int buscarMoto(int id, eMoto vec[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;

}
int menuModificar()
{
    char opcion;

    printf("\n\nQUE DESEA MODIFICAR?\n\n");
    printf("a-Color\n");
    printf("b-Cilindrada\n");
    printf("c-Cencelar\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;

}
void bajaMoto(eMoto x[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[], int tamColores)
{
    int indice;
    int id;
    char confirma;

    system("cls");
    printf("****BAJA MOTO ****\n\n");

    mostrarMotos(x,tamMotos,tipos,tamTipos,colores,tamColores);

    printf("\nIngrese el id: ");
    scanf("%d",&id);

    indice = buscarMoto(id,x,tamMotos);

    if(indice== -1)
    {
        printf("No hay registro de alguna moto con el id: %d\n\n", id);
    }
    else
    {
        printf("ID     MARCA     TIPO       COLOR     CILINDRADA \n");
        mostrarMoto(x[indice],tipos,tamTipos,colores,tamColores);

        printf("Confirma la baja? : ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            x[indice].isEmpty=1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se cancelo la operacion\n\n");
        }

    }

}
void listarMotos(eMoto x[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[], int tamColores)
{
    eMoto auxMoto;

    for(int i=0; i<tamMotos; i++)
    {
        for(int j=i+1; j<tamMotos; j++)
        {
            if(x[i].idTipo>x[j].idTipo)
            {
                auxMoto=x[i];
                x[i]=x[j];
                x[j]=auxMoto;
            }
            else
            {
                if(x[i].idTipo==x[j].idTipo && x[i].id>x[j].id)
                {
                    auxMoto=x[i];
                    x[i]=x[j];
                    x[j]=auxMoto;
                }
            }

        }
    }
    system("cls");
    mostrarMotos(x,tamMotos,tipos,tamTipos,colores,tamColores);
}
