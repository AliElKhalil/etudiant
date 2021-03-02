 /*------------------------------------------------------------
Nom : EL KHALIL
Pr�nom : Ali
Classe : 3PSC
Groupe : C1
Titre : date.h
D�scription : structure date, fonction et proc�dure li�es.
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
    //Fonction qui retourne un entier c qui prend une valeur qui d�pend de l'incoh�rence d'une date rep�r�e.
    //c=1 : Le nombre de jour d�passe 31 ou est n�gatif ou nulle.
    //c=2 : Le nombre de jours est de 31 alors que le mois ne compte que 30 jours.
    //c=3 : Le nombre de jours d�passe 29 en F�vrier.
    //c=4 : Le nombre de jours d�passe 29 en F�vrier alors que l'ann�e n'est pas bissextile.
    //c=5 : Le mois n'est pas compris entre 1 et 12.
    //c=0 : La date est coh�rente.

    //d�claration des variables
    int c;
    int j;
    int m;
    int a;

    //Notation pour r�duire le temps d'�criture
    j=da.jour;
    m=da.mois;
    a=da.annee;

    //On v�rifie si le jours ne d�passe pas 31 et n'est pas n�gatif
    if (j>31||j<1)
    {
        c=1;
    }
    else
    {
        //cas des mois � 30 jours
        if (( m==4 ||m==6||m==9||m==11)&&j==31)
        {
            c=2;
        }
        else
        {
            //cas de f�vrier d'une ann�e bissextile
            if (m==2 && j>29)
            {
                c=3;
            }
            else
            {
                //cas de f�vrier d'une ann�e non bissextile
                if (m==2 &&(((a%4!=0 || a%100==0)&&(a%400!=0))&&j==29))
                {
                    c=4;
                }
                else
                {
                    //v�rification si le mois est bien entre 1 et 12
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
            printf("\nDate incoh�rente : Le jour saisi est sup�rieur � 31 ou inf�rieur � 1.");
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
                    printf("\nLe mois de F�vrier ne peut pas avoir plus que 29 jours.");
                }
                else
                {
                    if (c==4)
                    {
                        printf("\nL'ann�e saisie n'est pas bissextile, le mois de F�vrier ne peut pas compter 29 jours.");
                    }
                    else
                    {
                        if (c==5)
                        {
                            printf("\nLe mois doit �tre un entier entre 1 et 12.");
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

