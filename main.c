#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"

#define TAM 100
int main()
{
    char seguir='s';
    int opcion = 0;
    char respuesta;
    int conta = 0;
    char aux[20];
    EMovie movies[TAM];
    inicializarMovies(movies, TAM);
    if(CargarBin(movies, TAM)){
        printf("No se pudo cargar el archivo");
        exit(1);
    }
    //cargarMovies(movies, TAM);
    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("2- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir y guardar datos en archivo binario\n");

        opcion = PedirOpcion();

        switch(opcion)
        {
            case 1:
                AltaMovie(movies, TAM);
                funcion_pausa();

                break;
            case 2:
                BajaMovie(movies, TAM);
                funcion_pausa();
                break;
            case 3:
                ModificarMovie(movies, TAM);
                funcion_pausa();
               break;
            case 4:
                printf("***Generar archivo HTML ***");
                printf("\nIngrese nombre que desea darle al archivo: ");
                fflush(stdin);
                gets(aux);
                while(validar_cadena(aux, 20)){
                    printf("Nombre muy largo, reingrese: ");
                    fflush(stdin);
                    gets(aux);
                }
                if(generarPagina(movies, TAM, aux)){
                    printf("\nNo se pudo generar archivo HTML");
                }
                else
                {
                    printf("\nSe genero archivo exitosamente");
                }
                funcion_pausa();
                break;
            case 5:
                conta = contadorMovies(movies, TAM);
                printf("cantidad de peliculas en sistema: %d\n", conta);
                printf("Desea guardar cambios y salir?(S/N): ");
                respuesta = tolower(getche());
                if(respuesta == 's'){
                    if(GuardarBin(movies, TAM)){
                        printf("\nNo se pudo guardar el archivo\n");
                    }
                    else{
                        printf("\nSe han guardado los cambios y se cerrara el programa\n");
                    }
                    seguir = 'n';
                    system("pause");
                    break;
                }
                else{
                    printf("\nSe ha cancelado la accion.\n");
                    system("pause");
                    break;
                }
            default:
                printf("Opcion no disponible en el menu");
                funcion_pausa();
                break;
        }
    }

    return 0;
}
