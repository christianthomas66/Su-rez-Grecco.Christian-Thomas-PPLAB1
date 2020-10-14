#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char descripcion[26];
    float precio;

} eServicio;

typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;

} eTrabajo;

#endif // TRABAJOS_H_INCLUDED


void mostrarDescripcionServicios(eServicio servicios[],int tamServicio);
int buscarLibreTrabajo(eTrabajo vec[],int tam);
void inicializarTrabajos(eTrabajo vec[],int tam);
int altaTrabajo(int idX,eTrabajo vec[], int tamTrabajo,eServicio servicios[],int tamServicios,eMoto listaMotos[], int tamMotos,eTipo tipos[],int tamTipos,eColor colores[],int tamColores);
void mostrarTrabajo(eTrabajo x,eServicio servicios[], int tamServicios);
float cargarDescripcionServicio(char servicio[],float* precio,int id, eServicio servicios[], int tamServicios);
void mostrarTrabajos(eTrabajo x[],int tamTrabajos,eServicio servicios[],int tamServicios);
