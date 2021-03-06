/*------------------------------------------------------------
Nom : EL KHALIL
Pr�nom : Ali
Classe : 3PSC
Groupe : C1
Titre : Module g�n�rale
D�scription : Module avec des fonctions et proc�dure g�n�rale.
---------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>  //structure
#include <string.h>  //usage de chaines de caract�re
#include<math.h>

#define Mmax 50 //taille max des chaines de caractere representant les noms des fichiers
#define nmax 50

int saisir_n()      //Fonction pour demander � l'utilisateur de saisir un entier
{
    int n;
    do{
        printf("\nDonner la valeur de n :");
        scanf("%d",&n);
    }while (n<=0 || n>10);
    return n;
}

void trait ()           //Proc�dure qui affiche un trait
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

void titre2 (char un_titre[nmax*2],int i)   //Titre num�rot�
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

void supprimer_1_ligne(const char *NomFichier,int n) //suppression de la n�me ligne du fichier "NomFichier"
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


void fusion_fichier()
{
    system("cls");
    printf("\nSaisie des deux fichiers � fusionner.");
    char t1[Mmax];
    char t2[Mmax];
    char t3[Mmax];
    printf("\nPremier fichier : ");
    scanf("%s",t1);
    system("cls");
    printf("\nDeuxi�me fichier : ");
    scanf("%s",t2);
    system("cls");
    printf("\nCreer  un nouveau fichier ou ajouter la fusion des deux fichier � un autre fichier.");
    printf("\nDonnez le nom du fichier a creer/ouvrir : ");
    scanf("%s",t3);
    system("cls");
    FILE *fic1=fopen(t1,"r");
    FILE *fic2=fopen(t2,"r");
    FILE *fic3=fopen(t3,"a");
    if (fic1==NULL || fic2==NULL ||fic3==NULL)
    {
        printf("\nErreur dans l'ouverture des fichiers.");
    }
    else
    {
        rewind(fic1);
        rewind(fic2);
        char texte[256];
        while (fgets(texte,255,fic1)!=NULL)
        {
            fputs(texte,fic3);
        }
        while (fgets(texte,255,fic2)!=NULL)
        {
            fputs(texte,fic3);
        }
        fclose(fic1);
        fclose(fic2);
        fclose(fic3);
        printf("\n\aLes fichiers %s et %s ont �t� fusionn� et ajout� au fichier %s",t1,t2,t3);
    }
    system("pause");
    system("cls");
}

void supprimer_fichier()
{
    char NomFichier[Mmax];
    int c;
    printf("\nDonner le nom du fichier a supprimer : ");
    scanf ("%s",NomFichier);
    system("cls");
    printf("\nAttention, vous vous appretez a supprimer le fichier %s.",NomFichier);
    system("pause");
    printf("\nConfirmez la suppression du fichier %s : ",NomFichier);
    do
    {
        printf("\nSaisissez 1 si oui, 0 si non.");
        scanf("%d",&c);
    }while(c!=0 && c!=1);
    if (c==1)
    {
        remove(NomFichier);
        printf("\n\aSuppression effectu�e.");
    }
    system("pause");
    system("cls");
}

void fin_programme()
{
    system("cls");
    printf("\nFin du programme.");
    printf("\nMerci de l'avoir utilise.");
    printf("\n\nBy Ali El Khalil, student at IPSA.");
    trait();
    printf("\n");
    system("pause");
}

void debut_programme(const char *t[])
{
    system("cls");
    printf("\t\t%s",t);
    printf("\n\t\t~~~~~~~~~~~~~~");
    printf("\n\t\t   Bienvenu");
    printf("\n\t\t~~~~~~~~~~~~~~");
    printf("\n\n\n");
    system("pause");
    system("cls");
}
