#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"

#define BIN "./MoviesBin.dat"


/** \brief Ingresa peliculas ya hardcodeadas al sistema
 *
 * \param puntero a estructura EMovie
 * \param tamaño estructura
 * \return void
 *
 */
void cargarMovies(EMovie* movies, int tam){
    char tit[3][20] = {"India jones ", "E.t", "Star wars"};
    char gen[3][20] = {"Accion", "Ciencia ficcion", "Ciencia ficcion"};
    int dur[3] = {115,115,121};
    char des[3][100] = {"Archaeologist and adventurer Indiana Jones is hired by the U.S. government to find the Ark of the Covenant before the Nazis",
    "A troubled child summons the courage to help a friendly alien escape Earth and return to his home world.",
    "Luke Skywalker joins forces with a Jedi Knight, a cocky pilot, a wookiee and two droids to save the galaxy from the Empire's world-destroying battle-station, while also attempting to rescue Princess Leia from the evil Darth Vader."};
    int pun[3] = {85,79,87};
    char lin[3][150] = {"http://www.zancada.com/wp-content/imagenes/2016/09/062612-indiana-jones.jpg","http://250.took.nl/img/posters/large/0083866_large.jpg","https://images-na.ssl-images-amazon.com/images/M/MV5BOTAzODEzNDAzMl5BMl5BanBnXkFtZTgwMDU1MTgzNzE@._V1_UX182_CR0,0,182,268_AL_.jpg"};
    int estado[3] = {1,1,1};
    for(int i=0;i<3;i++){
        strcpy(movies[i].titulo, tit[i]);
        strcpy(movies[i].genero, gen[i]);
        movies[i].duracion = dur[i];
        strcpy(movies[i].descripcion, des[i]);
        movies[i].puntaje = pun[i];
        strcpy(movies[i].linkImagen, lin[i]);
        movies[i].estado = estado[i];
    }
}

/** \brief Hace una pausa en el programa esperando que el usuario ingrese un caracter por teclado.
 *
 */
void funcion_pausa(void)
{
    printf("\nPulse tecla para volver al menu\n");
    getch();
}

/** \brief verifica que una cadena de caracteres no se desborde.
 *
 * \param cadena de caracteres a verificar.
 * \param tamaño de la cadena tipo entero.
 * \return devuelve 1 si se desborda, 0 si no.
 *
 */
int validar_cadena(char aux[], int tam){
    if(strlen(aux)>tam){
        return 1;
    }
    else{
        return 0;
    }
}

/** \brief verifica si en una cadena de caracteres hay algun numero.
 *
 * \param cadena de caracteres a verificar.
 * \return devuelve 1 si la cadena tiene nuemero/s, 0 si no.
 *
 */
int validar_char(char aux[]){
    int flag = 0;
    for(int i=0;i<strlen(aux); i++){
        if(isdigit(aux[i])){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        return 1;
    }
    else{
        return 0;
    }
}

/** \brief verifica si hay letras en un dato que se utilizará como entero.
 *
 * \param cadena de caracteres a verificar.
 * \return devuelve 1 si se encuentra letra, 0 si no.
 *
 */
int validar_entero(char op[]){
    int flag = 0;
    for(int i=0; i<strlen(op); i++){
        if(!isdigit(op[i])){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        return 1;
    }
    else{
        return 0;
    }
}

/** \brief valida si un entero esta fuera del rango o dentro.
 *
 * \param cadena de caracteres con el entero a validar.
 * \param minimo del rango
 * \param maximo del rango
 * \return devuelve 1 si esta fuera del rango, 0 si no.
 *
 */
int rango_entero(char aux[], int min, int max){
    if(atoi(aux)<min || atoi(aux)>max){
      return 1;
    }
    else{
        return 0;
    }
}

/** \brief Pasa a mayúscula el primer caracter y el seguido de un espacio, los demas los pasa a minúscula.
 *
 * \param cadena de caracteres a pasar.
 *
 */
void pasaje_nombre(char aux[]){
    strlwr(aux);
    aux[0] = toupper(aux[0]);
    for(int i=0;i<strlen(aux);i++){
        if(aux[i]=='.'){
            aux[i+2] = toupper(aux[i+2]);
        }
    }
}

/** \brief compara una pelicula ingresada con las que hay en la lista
 *
 * \param puntero a estructura EMovie
 * \param pelicula a comparar
 * \param tamaño de la estructura
 * \return 1 si son iguales, 0 si no
 */
int validar_pelicula(EMovie* movies, char peli[], int tam){
    int flag = 0;
    for(int i=0;i<tam;i++){
        if(strcmp(peli, movies[i].titulo)==0){
            flag = 1;
            break;
        }
    }
    return flag;
}

/** \brief Pide al usuario una opcion para el menu y lo valida.
 *
 * \param void
 * \return devuelve la opcion ingresada.
 *
 */
int PedirOpcion(void){
    char op[5];
    int aux;
    printf("Ingrese una opcion: ");
    fflush(stdin);
    gets(op);

    while(validar_cadena(op,5) || validar_entero(op)){
        printf("Opcion no valida, reingrese: ");
        fflush(stdin);
        gets(op);
    }
    aux = atoi(op);
    return aux;
}

/** \brief inicializa los estados en 0 de la estructura EMovie
 *
 * \param puntero a estructura EMovie
 * \param tamaño de la estructura
 * \return void
 *
 */
void inicializarMovies(EMovie* movies, int tam){
    for(int i=0;i<tam;i++){
        strcpy(movies[i].titulo, " ");
        strcpy(movies[i].genero, "");
        movies[i].duracion = 0;
        strcpy(movies[i].descripcion, "");
        movies[i].puntaje = 0;
        strcpy(movies[i].linkImagen,"");
        movies[i].estado = 0;
    }
}


/** \brief busca un lugar en la lista
 *
 * \param puntero a estructura EMovie
 * \param tamaño de la estructura
 * \return indice del lugar libre
 *
 */
int BuscarLugar(EMovie* movies, int tam){
    int indice = -1;
    for(int i=0; i<tam; i++){
        if(movies[i].estado==0){
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Da de alta una pelicula
 *
 * \param puntero a estructura EMovie
 * \param tamaño de la estructura
 * \return void
 *
 */
void AltaMovie(EMovie* movie, int tam){
    int indice, libre=0;
    char auxchar[200];
    indice = BuscarLugar(movie, tam);
    if(indice!=-1){
        printf("******Cargar una pelicula******\n");
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(auxchar);
        pasaje_nombre(auxchar);
        while(validar_cadena(auxchar, 20)){
            printf("Nombre muy largo, reingrese: ");
            fflush(stdin);
            gets(auxchar);
        }
        if(validar_pelicula(movie, auxchar, tam)){
            libre = 1;
        }
        if(libre == 0){
            strcpy(movie[indice].titulo, auxchar);
            printf("\nIngrese Genero: ");
            fflush(stdin);
            gets(auxchar);
            while(validar_cadena(auxchar, 20) || validar_char(auxchar)){
                printf("Genero muy largo o contiene numeros. Reingrese: ");
                fflush(stdin);
                gets(auxchar);
            }
            pasaje_nombre(auxchar);
            strcpy(movie[indice].genero, auxchar);
            printf("\nIngrese duracion de la pelicula en minutos: ");
            fflush(stdin);
            gets(auxchar);
            while(validar_entero(auxchar) || rango_entero(auxchar, 0, 240)){
                printf("Duracion invalida, contiene letras o esta fuera de rango<0-240>. Reingrese: ");
                fflush(stdin);
                gets(auxchar);
            }
            movie[indice].duracion = atoi(auxchar);
            printf("\nIngrese descripcion de la pelicula: ");
            fflush(stdin);
            gets(auxchar);
            while(validar_cadena(auxchar, 100)){
                printf("Descripcion muy larga. Reingrese:");
                fflush(stdin);
                gets(auxchar);
            }
            pasaje_nombre(auxchar);
            strcpy(movie[indice].descripcion, auxchar);
            printf("\nIngrese puntaje: ");
            fflush(stdin);
            gets(auxchar);
            while(validar_entero(auxchar) || rango_entero(auxchar, 0, 100)){
                printf("Puntaje invalido, contiene letras o esta fuera de rango<0-100>. Reingrese: ");
                fflush(stdin);
                gets(auxchar);
            }
            movie[indice].puntaje = atoi(auxchar);
            printf("\nIngrese Link de imagen de la pelicula: ");
            fflush(stdin);
            gets(auxchar);
            while(validar_cadena(auxchar, 150)){
                printf("Link muy largo. Reingrese: ");
                fflush(stdin);
                gets(auxchar);
            }
            strcpy(movie[indice].linkImagen, auxchar);
            movie[indice].estado = 1;

        }
        else{
            printf("La Pelicula ya existe!");

        }
    }
    else{
        printf("No hay mas lugar en la lista!");

    }
}

/** \brief Carga el archivo .bin de las peliculas, si no existe lo crea
 *
 * \param puntero a estructura EMovie
 * \param tamaño de la estructura
 * \return 0 si pudo cargarlo, 0 si no
 *
 */
int CargarBin(EMovie* movies, int tam){
    int flag = 0;

    FILE* f;
    f=fopen(BIN, "rb");
    if(f==NULL){
        f = fopen(BIN, "wb");
        if(f==NULL){
            return 1;
        }
        flag = 1;
    }
    if(flag == 0){
        fread(movies, sizeof(EMovie), tam, f);
    }
    fclose(f);
    return 0;
}

/** \brief Guarda en el archivo .bin los cambios realizados
 *
 * \param puntero a estructura EMovie
 * \param tamaño de la estructura
 * \return 0 si pudo guardar los datos, 1 si no.
 *
 */
int GuardarBin(EMovie* movies, int tam){
    int error = 0;
    FILE* f;
    f=fopen(BIN, "wb");
    if(f==NULL){
        error = 1;
    }
    AcomodarListado(movies, tam);
    fwrite(movies, sizeof(EMovie), contadorMovies(movies, tam), f);
    fclose(f);


    return error;

}

/** \brief Lista todo los titulos disponibles alfabeticamente
 *
 * \param puntero a estructura EMovie
 * \param tamaño de la estructura
 * \return void
 *
 */
void ListarTitulos(EMovie* movies, int tam){
    OrdenarAlfabeticamente(movies, tam);
    printf("***Titulos disponibles: ***\n");
    int cont=0;
    for(int i=0;i<tam;i++){
        if(movies[i].estado==1){
            printf("%d - %s\n",cont+1, movies[i].titulo);
            cont++;
        }
    }
}

/** \brief lista todos los datos de una pelicula
 *
 * \param puntero a estructura EMovie
 * \param indice de la pelicula a listar
 * \return void
 *
 */
void ListarMovie(EMovie* movies, int indice){
    printf("***Pelicula encontrada: ***\n");
        if(movies[indice].estado==1){
            printf("Titulo: %s\n", movies[indice].titulo);
            printf("Genero: %s\n", movies[indice].genero);
            printf("Duracion: %d\n", movies[indice].duracion);
            printf("Descripcion: %s\n", movies[indice].descripcion);
            printf("Puntaje: %d\n",movies[indice].puntaje);
            printf("Link de Imagen: %s\n", movies[indice].linkImagen);
        }
}

/** \brief busca una pelicula de la lista por el nombre
 *
 * \param puntero a estructura EMovie
 * \param tamaño de la estructura
 * \return devuelve el indice de la pelicula a buscar, -1 si no la encuentra
 *
 */
int BuscarMovie(EMovie* movies, int tam){
    int indice = -1;
    char aux[30];
    printf("Ingrese nombre de la pelicula a buscar: ");
    fflush(stdin);
    gets(aux);
    while(validar_cadena(aux, 20)){
        printf("\nNombre muy largo. Reingrese: ");
        fflush(stdin);
        gets(aux);
    }
    pasaje_nombre(aux);
    for(int i=0; i<tam; i++){
        if(strcmp(aux, movies[i].titulo) == 0){
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Da de baja una pelicula del sistema
 *
 * \param puntero a estructura EMovie
 * \param tamaño de la estructura
 * \return void
 *
 */
void BajaMovie(EMovie* movie, int tam){
    int indice = -1;
    char respuesta;
    ListarTitulos(movie, tam);
    indice = BuscarMovie(movie, tam);
    if(indice != -1){
        ListarMovie(movie, indice);
        printf("Desea dar de baja esta pelicula?(S/N)");
        respuesta = tolower(getche());
        if(respuesta == 's'){
            movie[indice].estado = 0;
            strcpy(movie[indice].titulo, " ");
            strcpy(movie[indice].genero, "");
            movie[indice].duracion = 0;
            strcpy(movie[indice].descripcion, "");
            movie[indice].puntaje = 0;
            strcpy(movie[indice].linkImagen,"");
            printf("\nPelicula Borrada!");
            return;
        }
        else{
            printf("\nAccion cancelada!");
            return;
        }
    }
    else{
        printf("Pelicula no existe!");
        return;
    }

}

/** \brief cuenta las peliculas que estan dadas de alta en el sistema
 *
 * \param puntero a estructura EMovie
 * \param tamaño de estructura
 * \return cantidad de peliculas dadas de alta
 *
 */
int contadorMovies(EMovie* movies, int tam){
    int contador = 0;
    for(int i=0;i<tam;i++){
        if(movies[i].estado == 1){
            contador++;
        }
    }
    return contador;
}

/** \brief Modifica todos los datos de una pelicula que se pide por titulo
 *
 * \param puntero a estructura EMovie
 * \param tamaño de estructura
 * \return void
 *
 */
void ModificarMovie(EMovie* movie, int tam){
    int indice = -1;
    int libre = 0;
    char auxchar[200];
    char respuesta;
    ListarTitulos(movie, tam);
    indice = BuscarMovie(movie, tam);
    if(indice != -1){
        ListarMovie(movie, indice);
        printf("Desea modificar informacion de esta pelicula?(S/N)");
        respuesta = tolower(getche());
        if(respuesta == 's'){
            printf("\nIngrese nuevo titulo: ");
            fflush(stdin);
            gets(auxchar);
            pasaje_nombre(auxchar);
            while(validar_cadena(auxchar, 20)){
                printf("Nombre muy largo, reingrese: ");
                fflush(stdin);
                gets(auxchar);
            }
            if(validar_pelicula(movie, auxchar, tam)){
                libre = 1;
            }
            if(libre == 0){
                strcpy(movie[indice].titulo, auxchar);
                printf("\nIngrese nuevo Genero: ");
                fflush(stdin);
                gets(auxchar);
                while(validar_cadena(auxchar, 20) || validar_char(auxchar)){
                    printf("Genero muy largo o contiene numeros. Reingrese: ");
                    fflush(stdin);
                    gets(auxchar);
                }
                pasaje_nombre(auxchar);
                strcpy(movie[indice].genero, auxchar);
                printf("\nIngrese nueva duracion de la pelicula en minutos: ");
                fflush(stdin);
                gets(auxchar);
                while(validar_entero(auxchar) || rango_entero(auxchar, 0, 240)){
                    printf("Duracion invalida, contiene letras o esta fuera de rango<0-240>. Reingrese: ");
                    fflush(stdin);
                    gets(auxchar);
                }
                movie[indice].duracion = atoi(auxchar);
                printf("\nIngrese nueva descripcion de la pelicula: ");
                fflush(stdin);
                gets(auxchar);
                while(validar_cadena(auxchar, 100)){
                    printf("Descripcion muy larga. Reingrese:");
                    fflush(stdin);
                    gets(auxchar);
                }
                pasaje_nombre(auxchar);
                strcpy(movie[indice].descripcion, auxchar);
                printf("\nIngrese nuevo puntaje: ");
                fflush(stdin);
                gets(auxchar);
                while(validar_entero(auxchar) || rango_entero(auxchar, 0, 100)){
                    printf("Puntaje invalido, contiene letras o esta fuera de rango<0-100>. Reingrese: ");
                    fflush(stdin);
                    gets(auxchar);
                }
                movie[indice].puntaje = atoi(auxchar);
                printf("\nIngrese nuevo Link de imagen de la pelicula: ");
                fflush(stdin);
                gets(auxchar);
                while(validar_cadena(auxchar, 150)){
                    printf("Link muy largo. Reingrese: ");
                    fflush(stdin);
                    gets(auxchar);
                }
                strcpy(movie[indice].linkImagen, auxchar);
                printf("\nPelicula Modificada!");
                return;
            }

            else{
                printf("La Pelicula ya existe!");
                return;
            }
        }
        else{
            printf("\nAccion cancelada!");
            return;
        }
    }
    else{
        printf("Pelicula no existe!");
        return;
    }
}

/** \brief Acomoda el listado con las peliculas de alta primeras
 *
 * \param puntero a estructura  EMovie
 * \param tamaño de estructura
 * \return void
 *
 */
void AcomodarListado(EMovie* movies, int tam){
    EMovie aux;
    for(int i = 0; i<tam-1;i++){
        for(int j = i; j<tam; j++){
            if(movies[i].estado <= movies[j].estado){
                aux = movies[i] ;
                movies[i]  = movies[j];
                movies[j] = aux;
            }
        }
    }
}

/** \brief Ordena listado de peliculas alfabeticamente
 *
 * \param puntero a estructura EMovie
 * \param tamaño de estructura
 * \return void
 *
 */
void OrdenarAlfabeticamente(EMovie* movies, int tam){
    EMovie aux;
    for(int i = 0; i<tam-1;i++){
        for(int j = i; j<tam; j++){
            if(movies[i].estado == 1 && movies[j].estado == 1){
                if(strcmp(movies[i].titulo, movies[j].titulo)>0){
                    aux = movies[i] ;
                    movies[i]  = movies[j];
                    movies[j] = aux;
                }
            }
        }
    }
}

/** \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *
 * \param movies EMovie*
 * \param tamaño de la estructura
 * \param nombre para el archivo.
 * \return 0 si se genero el archivo, 1 si hubo error
 *
 */
int generarPagina(EMovie* movies, int tam, char html[]){
    FILE* f;
    int error = 0;
    AcomodarListado(movies, tam);
    int cont = contadorMovies(movies, tam);
    strcat(html, ".html");
    f = fopen(html, "w");
    if(f==NULL){
        error = 1;
    }
    fprintf(f, "<!DOCTYPE html> \
<!-- Template by Quackit.com --> \
<html lang='en'> \
<head> \
    <meta charset='utf-8'> \
    <meta http-equiv='X-UA-Compatible' content='IE=edge'> \
    <meta name='viewport' content='width=device-width, initial-scale=1'> \
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --> \
    <title>Lista peliculas</title> \
    <!-- Bootstrap Core CSS --> \
    <link href='css/bootstrap.min.css' rel='stylesheet'> \
    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --> \
    <link href='css/custom.css' rel='stylesheet'> \
    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --> \
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// --> \
    <!--[if lt IE 9]> \
        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script> \
        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script> \
    <![endif]--> \
</head> \
<body> \
    <div class='container'> \
        <div class='row'>");
 for(int i=0; i<cont; i++){
    fprintf(f, "<article class='col-md-4 article-intro'> \
                <a href='#'> \
                    <img class='img-responsive img-rounded' src='");
    fprintf(f, movies[i].linkImagen);
    fprintf(f,"' alt=''> \
                </a> \
                <h3> \
                    <a href='#'>");
    fprintf(f, movies[i].titulo);
    fprintf(f, "</a> \
                </h3> \
				<ul> \
					<li>Genero:");
    fprintf(f, movies[i].genero);
    fprintf(f, "</li> \
					<li>Puntaje:");
    fprintf(f, "%d", movies[i].puntaje);
    fprintf(f, "</li>	\
					<li>Duracion:");
    fprintf(f, "%d", movies[i].duracion);
    fprintf(f, "</li> \
            	</ul> \
                <p>");
    fprintf(f, movies[i].descripcion);
    fprintf(f, ".</p> \
            </article>");

 }
 fprintf(f, "</div>  \
         <!-- /.row --> \
    </div> \
    <!-- /.container --> \
    <!-- jQuery --> \
    <script src='js/jquery-1.11.3.min.js'></script> \
    <!-- Bootstrap Core JavaScript --> \
    <script src='js/bootstrap.min.js'></script> \
	<!-- IE10 viewport bug workaround --> \
	<script src='js/ie10-viewport-bug-workaround.js'></script> \
	<!-- Placeholder Images --> \
	<script src='js/holder.min.js'></script> \
</body> \
</html>");

fclose(f);
return error;
}
