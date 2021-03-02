 /*------------------------------------------------------------
Nom : EL KHALIL
Prénom : Ali
Classe : 3PSC
Groupe : C1
Titre : date.h
Déscription : structure date, fonction et procédure liées.
---------------------------------------------------------------*/
#include "generale.h"

typedef struct
{
    int jour;
    int mois;
    int annee;
}date;

int coherence_date(date da)
{
    //Fonction qui retourne un entier c qui prend une valeur qui dépend de l'incohérence d'une date repérée.
    //c=1 : Le nombre de jour dépasse 31 ou est négatif ou nulle.
    //c=2 : Le nombre de jours est de 31 alors que le mois ne compte que 30 jours.
    //c=3 : Le nombre de jours dépasse 29 en Février.
    //c=4 : Le nombre de jours dépasse 29 en Février alors que l'année n'est pas bissextile.
    //c=5 : Le mois n'est pas compris entre 1 et 12.
    //c=0 : La date est cohérente.

    //déclaration des variables
    int c;
    int j;
    int m;
    int a;

    //Notation pour réduire le temps d'écriture
    j=da.jour;
    m=da.mois;
    a=da.annee;

    //On vérifie si le jours ne dépasse pas 31 et n'est pas négatif
    if (j>31||j<1)
    {
        c=1;
    }
    else
    {
        //cas des mois à 30 jours
        if (( m==4 ||m==6||m==9||m==11)&&j==31)
        {
            c=2;
        }
        else
        {
            //cas de février d'une année bissextile
            if (m==2 && j>29)
            {
                c=3;
            }
            else
            {
                //cas de février d'une année non bissextile
                if (m==2 &&(((a%4!=0 || a%100==0)&&(a%400!=0))&&j==29))
                {
                    c=4;
                }
                else
                {
                    //vérification si le mois est bien entre 1 et 12
                    if (m>12 ||m<1)
                    {
                        c=5;
                    }
                    else
                    {
                        c=0;
                    }
                }
            }
        }
    }
    return c;
}

date saisir_1_date()
{
    date da;
    int c;
    do
    {
        printf("\nSaisir la date (j/m/a) : ");
        scanf("%d/%d/%d",&da.jour,&da.mois,&da.annee);
        c=coherence_date(da);
        if (c==1)
        {
            printf("\nDate incohérente : Le jour saisi est supérieur à 31 ou inférieur à 1.");
        }
        else
        {
            if (c==2)
            {
                printf("\nLe mois saisi compte au maximum 30 jours.");
            }
            else
            {
                if (c==3)
                {
                    printf("\nLe mois de Février ne peut pas avoir plus que 29 jours.");
                }
                else
                {
                    if (c==4)
                    {
                        printf("\nL'année saisie n'est pas bissextile, le mois de Février ne peut pas compter 29 jours.");
                    }
                    else
                    {
                        if (c==5)
                        {
                            printf("\nLe mois doit être un entier entre 1 et 12.");
                        }
                    }
                }
            }
        }
    }while (c!=0);
    return da;
}

void afficher_1_date(date da)
{
    printf("%d/%d/%d",da.jour,da.mois,da.annee);
}

