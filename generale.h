/*------------------------------------------------------------
Nom : EL KHALIL
Prénom : Ali
Classe : 3PSC
Groupe : C1
Titre : Module générale
Déscription : Module avec des fonctions et procédure générale.
---------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>  //structure
#include <string.h>  //usage de chaines de caractère
#include<math.h>

#define nmax 50

int saisir_n()      //Fonction pour demander à l'utilisateur de saisir un entier
{
    int n;
    do{
        printf("\nDonner la valeur de n :");
        scanf("%d",&n);
    }while (n<=0 || n>10);
    return n;
}

void trait ()           //Procédure qui affiche un trait
{
    printf("\n----------------------------");
}
void titre (char un_titre[nmax*2])      //Titre normale
{
    trait();
    printf("\n   %s",un_titre);
    trait();
}

void etoile()
{
    printf("\n          ***          ");
}

void titre2 (char un_titre[nmax*2],int i)   //Titre numéroté
{
    trait();
    printf("\n   %s %d",un_titre,i );
    trait();
}

int recommencer_ou_pas()
{
    int c;
    do
    {
        printf("\nVoulez vous recommencez ? Saisissez 1 si oui, 0 si non ");
        scanf("%d",&c);
    }while (c!=1 && c!=0);
    return c;
}

void supprimer_1_ligne(const char *NomFichier,int n) //suppression de la nème ligne du fichier "NomFichier"
{
    rename(NomFichier,"temporaire.txt");
    FILE *fica=fopen("temporaire.txt","r");
    FILE *ficn=fopen(NomFichier,"w");
    if (fica==NULL || ficn==NULL)
    {
        printf("\nErreur dans l'ouverture des fichiers.");
        remove(NomFichier);
        rename("temporaire.txt",NomFichier);
        system("pause");
    }
    else
    {
        int i=0;
        char texte[100];
        char c;
        rewind(fica);
        rewind(ficn);
        while (fgets(texte,99,fica)!=NULL)
        {
            if (i!=n)
            {
                fputs(texte,ficn);
            }
            i++;
        }
        fclose(fica);
        remove("temporaire.txt");
        fclose(ficn);
    }
}

int nombre_ligne(FILE *fic)
{
    int n=0;
    char c;
    rewind(fic);
    while ((c=fgetc(fic))!=EOF)
    {
        if (c=='\n')
        {
            n++;
        }
    }
    return (n);
}
