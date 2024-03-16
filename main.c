#include <stdio.h>
#include <stdio.h>
#define nbMAX 100
int main() {
    int nbNotes;
    double T[nbMAX];
    double moyenne,somme = 0.0;
    double minimum,maximum;
    int posMax,posMin;
    double Z;
    double AUX;

    do{
    printf("    Entrez le nombre de notes a saisir: ");
    scanf("%d",&nbNotes);
    }while(nbNotes< 0 || nbNotes>nbMAX);
    // Déclaration d'un tableau pour stocker les notes
    // Boucle pour saisir les notes
    for (int i = 1; i <= nbNotes; i++) {
      do{
        printf("    Saisissez la note %d : ", i);
        scanf("%lf", &T[i]); // %lf est le format pour lire un double
       }while (T[i]<0 || T[i]>20);
    }
    printf("\n");
    // Affichage des notes saisies
    printf("\n      Les notes saisies :\n");
    for (int i = 1; i <= nbNotes; i++) {
        printf(" %7.2lf", T[i]); // %.2lf affiche le double avec deux décimales
    }

    for (int i = 1; i <=nbNotes; i++) {
        somme += T[i];
    }

    // Calcul de la moyenne
    moyenne = somme / nbNotes;
    printf("\n");
    // Affichage de la somme et de la moyenne
    printf("\n      La somme des notes est : %.2lf\n", somme);
    printf("        La moyenne des notes est : %.2lf\n", moyenne);

    // Initialisation des variables pour le minimum et le maximum
    minimum = T[1]; // On suppose que la première note est le minimum initial
    maximum = T[1]; // On suppose que la première note est le maximum initial
    posMax=1;
    posMin=1;
    // Recherche du minimum et du maximum
    for (int i = 1; i <= nbNotes; i++) {
        if (T[i] < minimum) {
            minimum = T[i];
            posMin =i+1;
        }
        if (T[i] > maximum) {
            maximum = T[i];
            posMax = i+1;
        }
    }
// Affichage du minimum et du maximum
    printf("\n      Le minimum des notes est : %.2lf  a la position %d\n", minimum,posMin);
    printf("       Le maximum des notes est : %.2lf    a la position %d\n", maximum,posMax);
    printf("\n");
{
    for (int i = 1; i <= nbNotes ; i++) {
        for (int j = 1; j <= nbNotes - 1; j++) {
            if (T[j] > T[j + 1]) {
                // Échanger les éléments si ils sont dans le mauvais ordre
                AUX = T[j];
                T[j] = T[j + 1];
                T[j + 1] = AUX;
            }
        }
    }
}
printf("\n");
printf("\n        Tri a bulles :\n");
    for (int i = 1; i <= nbNotes; i++) {
        printf(" %7.2lf", T[i]); // %.2lf affiche le double avec deux décimales
    }

printf("\n");
// Tri par sélection

    for (int i = 1; i <= nbNotes ; i++) {
        // Trouver l'index du minimum dans le reste du tableau
        int posMinimale = i;
        for (int j = i + 1; j < nbNotes; j++) {
            if (T[j] < T[posMinimale]) {
                posMinimale = j;
            }
        }

        // Échanger l'élément actuel avec le minimum trouvé
        double temp = T[i];
        T[i] = T[posMinimale];
        T[posMinimale] = temp;
    }
    printf("\n");
printf("\n       Tri par selection :\n");
    for (int i = 1; i <= nbNotes; i++) {
        printf(" %7.2lf", T[i]); // %.2lf affiche le double avec deux décimales
    }
// Tri par insertion
// Tri par insertion

    printf("\n");
    for (int i = 1; i <= nbNotes; i++) {
        Z = T[i];
      int  j = i - 1;
        // Déplacer les éléments du sous-tableau trié qui sont plus grands que la clé
        while (j >= 1 && T[j] > Z) {
            T[j + 1] = T[j];
            j = j - 1;
        }
        T[j + 1] = Z;
    }
    printf("\n     Tri par insertion :\n");
    for (int i = 1; i <= nbNotes; i++) {
        printf(" %7.2lf", T[i]); // %.2lf affiche le double avec deux décimales
    }
    printf("\n");


    // Déclarer la position d'insertion et la valeur à insérer
    double valAInserrer;
int position;
    // Demander à l'utilisateur d'entrer la position et la valeur
    do{
        printf("  Entrez la position d'insertion (de 0  a  %d) : ", nbNotes);
        scanf("%d", &position);
       }while(position<1 || position>nbNotes);

       do{
           printf("  Entrez la valeur a inserrer : ");
           scanf("%lf",&valAInserrer);
       }while(valAInserrer<0 || valAInserrer>20);
    // Décaler les éléments du tableau pour faire de la place pour le nouvel élément
    for (int i = nbNotes; i >= position; i--) {
        T[i+1] = T[i];
    }

    // Insérer la nouvelle valeur à la position spécifiée
        T[position] = valAInserrer;

    // Augmenter la taille du tableau
        nbNotes++;

    // Afficher le tableau après l'insertion
    printf("  Le tableau apres l'insertion :\n");
    for (int i = 1; i <= nbNotes; i++) {
        printf("%7.2lf ", T[i]);
    }
    printf("\n");

    do{
        printf("  Entrez la position de la suppression (de 0  a  %d) : ", nbNotes);
        scanf("%d", &position);
       }while(position<0 || position>nbNotes);

    // Déplacer les éléments suivants d'une position vers l'avant
    for (int i = position; i <= nbNotes ; i++) {
        T[i] = T[i + 1];
    }
    printf("\n");
    // Diminuer la taille du tableau
    (nbNotes)--;
    printf("  Le tableau apres la suppression :\n");
    for (int i = 1; i <= nbNotes; i++) {
        printf("%7.2lf ", T[i]);
    }
    printf("\n");

    printf("  La recherche  sequentielle\n");
    int resultat=-1;

        // Déclarer la valeur à rechercher
    double valeurRecherchee;

    // Demander à l'utilisateur d'entrer la valeur à rechercher
    do{
        printf("  Entrez la valeur a rechercher : ");
        scanf("%lf", &valeurRecherchee);
    }while(valeurRecherchee<0 || valeurRecherchee>20);

    // Effectuer la recherche
     position = -1; // Variable pour indiquer si la valeur est trouvée
    int i=1;
    while(i<=nbNotes && position==-1){
        if ( T[i] == valeurRecherchee)
            position = i;
           else
                i++;
    }
    printf("\n");
    if (position==-1)
        printf("  La valeur %7.2lf n'a pas ete trouvee dans le tableau.\n", valeurRecherchee);
        else
            printf("  La valeur %7.2lf a  ete trouvee dans le tableau a la position %d\n ",valeurRecherchee,position);

    printf("\n");
    printf("  La recherche dichotomique\n");
    double noteRecherchee;
    do{
        printf("  Entrez la note a recherchee : ");
        scanf("%lf",&noteRecherchee);
    }while(noteRecherchee<0 || noteRecherchee>20);

    int gauche=1,droite=nbNotes;

    while (gauche <= droite) {
        int milieu = (gauche + droite) / 2;

        // Vérifier si l'élément est présent au milieu
        if (T[milieu] == noteRecherchee) {
            resultat=milieu;
            gauche=droite+1;
             // L'élément est trouvé, renvoyer l'indice
        }

        // Si l'élément est plus petit, ignorer la moitié droite
        else
            if (noteRecherchee<T[milieu]) {
                droite= milieu - 1;
                 }

        // Si l'élément est plus grand, ignorer la moitié gauche
        else {
               gauche = milieu + 1;
        }
    }
    if (resultat != -1) {
        printf("  La note %5.2lf est present a l'indice %d.\n", noteRecherchee, resultat);
    } else {
        printf("  La note  %5.2lf n'est pas present dans le tableau.\n", noteRecherchee);
    }
    for (int i = 1; i <= nbNotes; i++) {
        printf("%7.2lf ", T[i]);
    }
    printf("\n");
    /* Déclarations */
 /* Les tableaux et leurs dimensions */
  double A[50], B[50], FUS[100];
  int N, M;
  int IA, IB, IFUS; /* indices courants */

 /* Saisie des données */
   do{
        printf("  Dimension du tableau A (max.50) : ");
        scanf("%d", &N );
   }while(N<0 || N> nbMAX);
printf("\n");
    printf("   Entrer les elements de A dans l'ordre croissant :\n");
    for (IA=1; IA<=N; IA++)
    {
        do{
           printf("Element A[%d] : ", IA);
           scanf("%lf", &A[IA]);
        }while(A[IA]<0 || A[IA]>20);
    }
printf("\n");
printf("  Dimension du tableau B (max.50) : ");
  do{
    scanf("%d", &M );
  }while (M<0 || M>nbMAX);

    printf("Entrer les elements de B dans l'ordre croissant :\n");
    for (IB=1; IB<=M; IB++)
    {
        do{
            printf("  Element B[%d] : ", IB);
            scanf("%lf", &B[IB]);
        }while(B[IB]<0 || B[IB]>20 );
    }
 /* Affichage des tableaux A et B */
        printf("  Tableau A :\n");
        for (IA=1; IA<=N; IA++)
            printf("%7.2lf ", A[IA]);
        printf("\n");
        printf("  Tableau B :\n");
        for (IB=1; IB<=M; IB++)
        printf("  %7.2lf ", B[IB]);
        printf("\n");

/* Fusion des éléments de A et B dans FUS */
 /* de façon à ce que FUS soit aussi trié. */
 IA=1; IB=1; IFUS=1;
while ((IA<=N) && (IB<=M))
      if(A[IA]<B[IB])
        {
         FUS[IFUS]=A[IA];
          IFUS++;
             IA++;
        }
     else
        {
         FUS[IFUS]=B[IB];
         IFUS++;
         IB++;
        }
 /* Si IA ou IB sont arrivés à la fin de leur tableau, */
 /* alors copier le reste de l'autre tableau.          */
    while (IA<=N)
        {
         FUS[IFUS]=A[IA];
         IFUS++;
         IA++;
        }
    while (IB<=M)
        {
         FUS[IFUS]=B[IB];
         IFUS++;
         IB++;
        }
  printf("\n");
 /* Edition du résultat */
   printf("   Tableau FUS :\n");
   for (IFUS=1;IFUS<=(N+M); IFUS++)
    printf("%7.2lf ", FUS[IFUS]);
    printf("\n");
 return 0;
}
