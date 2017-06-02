#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[100];
    int puntaje;
    char linkImagen[150];
    int estado;
}EMovie;


int generarPagina(EMovie*, int, char[]);
void cargarMovies(EMovie*, int );
int validar_cadena(char[], int);
int validar_char(char[]);
int validar_entero(char[]);
int PedirOpcion(void);
void AltaMovie(EMovie*, int);
int BuscarLugar(EMovie*, int);
void inicializarMovies(EMovie*, int);
int validar_pelicula(EMovie*, char[], int);
void pasaje_nombre(char[]);
int rango_entero(char[], int, int);
void funcion_pausa(void);
int CargarBin(EMovie*, int);
int GuardarBin(EMovie*, int);
void ListarTitulos(EMovie*, int);
void ListarMovie(EMovie*, int);
void BajaMovie(EMovie*, int);
int contadorMovies(EMovie*, int);
void ModificarMovie(EMovie* , int);
void AcomodarListado(EMovie*, int);
void OrdenarAlfabeticamente(EMovie* , int );

#endif // FUNCIONES_H_INCLUDED

