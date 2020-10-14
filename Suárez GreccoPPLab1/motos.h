#ifndef MOTOS_H_INCLUDED
#define MOTOS_H_INCLUDED

typedef struct
{
    int id;
    char nombreTipo[21];

} eTipo;

typedef struct
{
    int id;
    char nombreColor[21];
} eColor;

typedef struct
{
    int id;
    char marca[21];
    int idTipo;
    int idColor;
    int cilindrada;
    int isEmpty;
} eMoto;


#endif // MOTOS_H_INCLUDED



void inicializarMotos(eMoto vec[],int tam);
int buscarLibreMoto(eMoto vec[],int tam);
void mostrarDescripcionTipos(eTipo tipos[],int tamTipo);
void mostrarDescripcionColores(eColor colores[],int tamColores);
int altaMoto(int idX,eMoto vec[], int tam,eTipo tipos[], int tamTipos,eColor colores[],int tamColores);
int cargarDescripcionTipo(char tipo[],int id, eTipo tipos[], int tam);
void mostrarMoto(eMoto x,eTipo tipos[],int tamTipos,eColor colores[], int tamColores);
int cargarDescripcionColor(char color[],int id, eColor colores[], int tamColores);
void mostrarMotos(eMoto x[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[], int tamColores);
int buscarMoto(int id, eMoto vec[], int tam);
void modificarMoto(eMoto vec[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[], int tamColores);
int menuModificar();
void bajaMoto(eMoto x[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[], int tamColores);
void listarMotos(eMoto x[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[], int tamColores);
