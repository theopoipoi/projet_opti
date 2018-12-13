#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdint.h>

int main()
{
    int i;
    int j;
    int taille_matrice;

    FILE *file;
    file=fopen("/home/theopoipoi/CLionProjects/projet_opti/data/nug30.dat", "r");

    fseek(file, 0, SEEK_SET);
    fscanf(file, "%d", &taille_matrice);
    printf("Taille matrice = %d \n",taille_matrice);
/*matrix*/
/*Use double , you have floating numbers not int*/
// malloc = dynamic allocation of memory
//sizeof = donne la taille en bytes de son opérande.
    int **mat1=(int**)malloc(sizeof(int*) * taille_matrice);
    for(i=0;i<taille_matrice;++i) {
        mat1[i]=(int*)malloc(sizeof(int)*taille_matrice);
    }

    //Déclaration de la seconde matrice
    int **mat2=(int**)malloc(sizeof(int*) * taille_matrice);

    for(i=0;i<taille_matrice;++i) {
        mat2[i]=(int*)malloc(sizeof(int)*taille_matrice);
    }


    //Remplissage première matrice
    fseek(file, 3, SEEK_SET);
    if(file != NULL) {
        for (i = 0; i < taille_matrice; i++) {
            for (j = 0; j < taille_matrice; j++) {
                //Use lf format specifier, %c is for character
                //fscanf = lit les chaines formatées
                // %lf = format pour double
                // %d = format pour les entiers
                if (!fscanf(file, "%d", &mat1[i][j])) {
                    break;
                }
                printf("%d \t", mat1[i][j]); //Use lf format specifier, \n is for new line
            }
            printf("\n");

        }
    }
    else {
        printf("Erreur dans l'ouverture du fichier \n");
    }

    //Remplissage deuxième matrice
    if(file != NULL)
    {
        printf("Début deuxième matrice \n");
        for (i = 0; i < taille_matrice; i++) {
            for (j = 0; j < taille_matrice; j++) {
                //Use lf format specifier, %c is for character
                //fscanf = lit les chaines formatées
                // %lf = format pour double
                // %d = format pour les entiers
                if (!fscanf(file, "%d", &mat2[i][j])) {
                    break;
                }
                printf("%d \t", mat2[i][j]); //Use lf format specifier, \n is for new line
            }
            printf("\n");

        }
    }
    else {
        printf("Erreur dans l'ouverture du fichier \n");
    }

    fclose(file);
}