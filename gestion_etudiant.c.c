/*------------------------------------------------------------
Nom : EL KHALIL
Prénom : Ali
Classe : 3PSC
Groupe : C1
Titre : gestion_etudiant
Déscription : Travail demandé pour le 04/03/2021.
---------------------------------------------------------------*/
#include "etudiant.h"

void menu_ajout(int *b)
{
    system("cls");
    trait();
    printf("\n===Menu ajout etudiant===");
    trait();
    printf("\n1-Ajouter un etudiant");
    printf("\n2-Fusionner deux fichiers");
    printf("\n0-Retour au menu principal\n");
    scanf("%d",b);
}

void menu_rechercher_afficher_etudiant(int *b)
{
    system("cls");
    trait();
    printf("\n===Menu recherche et affichage d'etudiant===");
    trait();
    printf("\n1-Afficher un ou plusieurs etudiant(s)");
    printf("\n2-Afficher tous les etudiants");
    printf("\n0-Retour au menu principal\n");
    scanf("%d",b);
}

void menu_suppression_etudiant(int *b)
{
    system("cls");
    trait();
    printf("\n===Menu suppression d'etudiant===");
    trait();
    printf("\n1-Supprimer un etudiant");
    printf("\n2-Supprimer un fichier d'etudiant");
    printf("\n0-Retour au menu principal\n");
    scanf("%d",b);
}

void menu_modification_etudiant(int *b)
{
    system("cls");
    trait();
    printf("\n===Menu modification d'etudiant===");
    trait();
    printf("\n1-modifier un etudiant");
    printf("\n0-Retour au menu principal\n");
    scanf("%d",b);
}

void saisir_etudiant()
{
    int b;
    do{
        menu_ajout(&b); //done
    }while(b!=0 && b!=1 && b!=2);
    while (b!=0)
    {
        if (b==1)
        {
            ajout_etudiant(); //done
        }
        if (b==2)
        {
            fusion_fichier();
            printf("\nRetour au menu d'ajout");
            system("pause");
            system("cls");
        }
        do{
            menu_ajout(&b);
        }while(b!=0 && b!=1);
        system("cls");
    }
}

void afficher_ou_existence_etudiant()
{
    int b;
    do{
        menu_rechercher_afficher_etudiant(&b); //done
    }while(b!=0 && b!=1 && b!=2);
    while (b!=0)
    {
        if (b==1)
            afficher_etudiant(); //done
        if (b==2)
            afficher_tous_les_etudiants();
        do{
            menu_rechercher_afficher_etudiant(&b);
        }while(b!=0 && b!=1 && b!=2);
        system("cls");
    }
}

void menu_principal(int *a)
{
    system("cls");
    trait();
    printf("\n   ###Menu principal###");
    trait();
    printf("\n1-Ajouter des etudiants");
    printf("\n2-Rechercher et afficher etudiant");
    printf("\n3-Supprimer un etudiant");
    printf("\n4-Modifier un etudiant");
    printf("\n0-Quitter le programme");
    printf("\n");
    scanf("%d",a);
}

void suppression_etudiant()
{
    int b;
    do{
        menu_suppression_etudiant(&b); //done
    }while(b!=0 && b!=1 && b!=2);
    while (b!=0)
    {
        if (b==1)
        {
            supprimer_etudiant(); //done
        }
        if (b==2)
        {
            supprimer_fichier();
            printf("\nRetour au menu suppression.");
            system("pause");
            system("cls");
        }
        do{
            menu_suppression_etudiant(&b);
        }while(b!=0 && b!=1);
        system("cls");
    }
}

void modification_etudiant()
{
    int b;
    do{
        menu_modification_etudiant(&b); //done
    }while(b!=0 && b!=1);
    while (b!=0)
    {
        modifier_etudiant(); //done
        do{
            menu_modification_etudiant(&b);
        }while(b!=0 && b!=1);
        system("cls");
    }
}

main()
{
    debut_programme("Gestion d'etudiant");
    int *a;
    do
    {
        do{
            menu_principal(&a); //done
        }while (a!=1 && a!=2 && a!=0 && a!=3 && a!=4);
        if (a==1)
        {
            saisir_etudiant();  //done
        }
        if (a==2)
        {
            afficher_ou_existence_etudiant(); //done
        }
        if (a==3)
        {
            suppression_etudiant(); //done
        }
        if (a==4)
        {
            modification_etudiant();
        }
    }while (a!=0);
    fin_programme();
}
