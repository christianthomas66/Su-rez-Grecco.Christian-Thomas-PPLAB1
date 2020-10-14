#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "motos.h"
#include "trabajos.h"






void mostrarDescripcionServicios(eServicio servicios[],int tamServicio)
{

    printf("\nListado de servicios\n");
    printf("id        Descripcion     Precio \n");

    for(int i=0; i<tamServicio; i++)
    {
        printf("%d      %10s      $%2.f \n",servicios[i].id,servicios[i].descripcion,servicios[i].precio);
    }

}
int altaTrabajo(int idX,eTrabajo vec[], int tamTrabajo,eServicio servicios[],int tamServicios,eMoto listaMotos[], int tamMotos,eTipo tipos[],int tamTipos,eColor colores[],int tamColores)
{
    int todoOK = -1;
    int indice = buscarLibreTrabajo(vec,tamTrabajo);
    int auxInt;

    eTrabajo auxTrabajo;
    system("cls");

    printf("***** ALTA TRABAJO *****\n\n");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }

    else
    {
        while(todoOK==-1)
        {
            //ID MOTO
            mostrarMotos(listaMotos,tamMotos,tipos,tamTipos,colores,tamColores);
            if((utn_getEntero(&auxInt,2,"Ingrese el id de la moto: ","Error. Reingrese el id de la moto\n",0,1000))==0)
            {
                if((buscarMoto(auxInt,listaMotos,tamMotos))!=-1)
                {
                    auxTrabajo.idMoto=auxInt;
                }
                else
                {
                    printf("No existe ninguna moto con el id: %d\n\n",auxInt);
                    todoOK=0;
                    break;
                }

            }
            else
            {
                printf("Se quedo sin intentos para ingresar el id de la moto\n");
                todoOK=0;
                break;
            }
            //SERVICIOS
            mostrarDescripcionServicios(servicios,tamServicios);
            if((utn_getEntero(&auxInt,2,"Ingrese el servicio: ","Error. Reingrese el servicio\n",20000,20003))==0)
            {
                auxTrabajo.idServicio=auxInt;
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el servicio\n");
            }
            //DIA
            if((utn_getEntero(&auxInt,2,"Ingrese el dia: ","Error. Reingrese el dia\n",1,31))==0)
            {
                auxTrabajo.fecha.dia=auxInt;
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el dia\n");
                todoOK=0;
                break;
            }
            //MES
            if((utn_getEntero(&auxInt,2,"Ingrese el mes: ","Error. Reingrese el mes\n",1,12))==0)
            {
                auxTrabajo.fecha.mes=auxInt;
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el mes\n");
                todoOK=0;
                break;
            }
            //ANIO
            if((utn_getEntero(&auxInt,2,"Ingrese el anio: ","Error. Reingrese el anio\n",2019,2050))==0)
            {
                auxTrabajo.fecha.anio=auxInt;
                todoOK=1;
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el anio\n");
                todoOK=0;
                break;

            }


        }
        if(todoOK==1)
        {
            auxTrabajo.id = idX;

            auxTrabajo.isEmpty = 0;

            printf("El id del nuevo trabajo es: %d\n",idX);

            vec[indice] = auxTrabajo;
        }


    }


    return todoOK;
}
int buscarLibreTrabajo(eTrabajo vec[],int tam)
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
void inicializarTrabajos(eTrabajo vec[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}
void mostrarTrabajo(eTrabajo x,eServicio servicios[], int tamServicios)
{
    char nombreServicio[21];
    float precioServicio;

    cargarDescripcionServicio(nombreServicio,&precioServicio,x.idServicio,servicios,tamServicios);

    printf(" %d      %d       %10s      $%.2f       %d/%d/%d \n",x.id,x.idMoto,nombreServicio,precioServicio,x.fecha.dia,x.fecha.mes,x.fecha.anio);

}
float cargarDescripcionServicio(char servicio[],float* precio,int id, eServicio servicios[], int tamServicios)
{
    int todoOK = 0;

    for(int i=0; i<tamServicios; i++)
    {
        if(servicios[i].id==id)
        {
            strcpy(servicio,servicios[i].descripcion);
            *precio=servicios[i].precio;
            todoOK = 1;
        }
    }

    return todoOK;
}
void mostrarTrabajos(eTrabajo x[],int tamTrabajos,eServicio servicios[],int tamServicios)
{
    int flag=0;
    system("cls");
    printf("\n*****LISTADO DE TRABAJOS *****\n");
    printf("  ID     ID MOTO     SERVICIO       PRECIO       FECHA \n");

    for(int i=0; i<tamTrabajos; i++)
    {
        if(x[i].isEmpty == 0)
        {
            mostrarTrabajo(x[i],servicios,tamServicios);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNo hay trabajos que listar\n\n");
    }

}
