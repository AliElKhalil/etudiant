 /*------------------------------------------------------------
Nom : EL KHALIL
Prénom : Ali
Classe : 3PSC
Groupe : C1
Titre : etudiant.h
Déscription : structure etudiant, fonction et procédure liées.
---------------------------------------------------------------*/
#include "date.h"
#define NombreNote 3

typedef struct
{
    char nom[nmax];
    char prenom[nmax];
    date ddn;
    float n[NombreNote];
    float m;
}etudiant;

void saisir_1_note(int i, etudiant *e)
{
    do{
        printf("\n    Note N%d : ", i+1);
        scanf("%f", &e->n[i]);
    }while (e->n[i]<0||e->n[i]>20);
}

void saisir_toutes_les_notes( etudiant *e)
{
    int i;
    for (i=0;i<NombreNote;i++)
    {
        saisir_1_note(i,e);
    }
}

float Moyenne(etudiant *e)
{
    int i;
    float S=0;
    float m;
    for (i=0;i<NombreNote;i++)
    {
        S=S+(e->n[i]);
    }
    m=S/((float) NombreNote);
    return m;
}

etudiant saisir_1_etudiant(int i)
{
    int c;
    etudiant e;
    do{
        trait();
        printf("\n    Etudiant %d",i);
        trait();
        printf("\n    Nom de l'etudiant (en majuscule) : ");
        scanf("%s", e.nom);
        etoile();
        printf("\n    Prenom de l'etudiant (en majuscule) : ");
        scanf("%s", e.prenom);
        etoile();
        printf("\n    Date de naissance : ");
        e.ddn=saisir_1_date();
        etoile();
        saisir_toutes_les_notes(&e);
        e.m=Moyenne(&e);
        printf("\n    Moyenne : %f", e.m);
        do
        {
            printf("\nConfirmez la saisie ?");
            scanf("%d",&c);
        }while(c!=0 && c!=1);
    }while(c==0);
    return (e);
    system("cls");
}

void afficher_1_etudiant(etudiant e,int i)
{
    titre2("Fiche Etudiant ",i);
    printf("\n\n Nom: %s",e.nom);
    printf("\n\n Prenom: %s",e.prenom);
    printf("\n\n Date de naissance : ");
    afficher_1_date(e.ddn);
    printf("\n\n Moyenne : %f\n",e.m);
}

void saisir_n_etudiant(int n,etudiant *e)
{
    int i;
    for (i=0;i<n;i++)
    {
        *(e+i)=saisir_1_etudiant(i+1);
    }
}

void afficher_n_etudiant(int n, etudiant *e)
{
    int i;
    for (i=0;i<n;i++)
    {
        afficher_1_etudiant(*(e+i),i+1);
    }
}

void saisie_fichier_1_etudiant(FILE *fic,etudiant e)
{
    fprintf(fic,"%s %s %d/%d/%d %f\n",e.nom,e.prenom,e.ddn.jour,e.ddn.mois,e.ddn.annee,e.m);
}

void saisie_fichier_n_etudiant(FILE *fic,etudiant *e,int n)
{
    int i;
    int j;
    for (i=0;i<n;i++)
    {
        saisie_fichier_1_etudiant(fic,*(e+i));
    }
}

void ajout_etudiant()
{
    char nom[Mmax];
    int n;
    int i;
    int *j;
    system("cls");
    printf("\nNom du fichier a creer ou a ouvrir : ");
    scanf("%s",nom);
    system("cls");
    FILE *fic=fopen(nom,"a+");
    if (fic==NULL)
    {
        printf("\nErreur lors de la création/de l'ouverture du fichier.");
    }
    else
    {
        etudiant *e;
        printf("\nNombre d'etudiant a saisir : ");
        scanf("%d",&n);
        e=(etudiant*)malloc(n*sizeof(etudiant));
        system("cls");
        saisir_n_etudiant(n,e);
        saisie_fichier_n_etudiant(fic,e,n);
        fclose(fic);
        free(e);
        printf("\n\aAjout effectuee.");
    }
    printf("\nRetour au menu d'ajout\n");
    system("pause");
    system("cls");
}

void afficher_etudiant()
{
    char NomFichier[Mmax];
    char t[nmax];
    printf("\nNom du fichier : ");
    scanf("%s",NomFichier);
    printf("\nSaisissez le nom ou le prenom de l'etudiant a rechercher et afficher : ");
    scanf("%s",t);
    FILE *fic=fopen(NomFichier,"r");
    if (fic==NULL)
    {
        printf("\nErreur dans l'ouverture du fichier");
        printf("\nVerifier l'existence du fichier saisi.");
    }
    else
    {
        int k=0;
        etudiant e;
        rewind(fic);
        while (!feof(fic))
        {
            fscanf(fic,"%s %s %d/%d/%d %f\n",e.nom,e.prenom,&e.ddn.jour,&e.ddn.mois,&e.ddn.annee,&e.m);
            if (strcmp(e.nom,t)==0 || strcmp(e.prenom,t)==0)
            {
                k++;
            }
        }
        if (k>0)
        {
            etudiant *f;
            f=(etudiant*)malloc(k*sizeof(etudiant));
            int i=0;
            int j=0;
            rewind(fic);
            while (!feof(fic))
            {
                fscanf(fic,"%s %s %d/%d/%d %f\n",e.nom,e.prenom,&e.ddn.jour,&e.ddn.mois,&e.ddn.annee,&e.m);
                if (strcmp(e.nom,t)==0 || strcmp(e.prenom,t)==0)
                {
                    strcpy((f+i)->nom,e.nom);
                    strcpy((f+i)->prenom,e.prenom);
                    (f+i)->ddn.jour=e.ddn.jour;
                    (f+i)->ddn.mois=e.ddn.mois;
                    (f+i)->ddn.annee=e.ddn.annee;
                    (f+i)->m=e.m;
                    i++;
                }
            }
            fclose(fic);
            afficher_n_etudiant(k,f);
            free(f);
        }
        else
        {
            printf("\nAucun etudiant ne correspond a la recherche.");
        }
    }
    printf("\nRetour au menu recherche et affichage.");
    system("pause");
    system("cls");
}

void supprimer_etudiant()
{
    char NomFichier[Mmax];
    char t[nmax];
    printf("\nNom du fichier : ");
    scanf("%s",NomFichier);
    system("cls");
    printf("\nSaisissez le nom ou le prenom de l'etudiant a supprimer : ");
    scanf("%s",t);
    system("cls");
    FILE *fic=fopen(NomFichier,"r");
    if (fic==NULL)
    {
        printf("\nErreur dans l'ouverture du fichier");
    }
    else
    {
        int k=0;
        etudiant e;
        rewind(fic);
        while (!feof(fic))
        {
            fscanf(fic,"%s %s %d/%d/%d %f\n",e.nom,e.prenom,&e.ddn.jour,&e.ddn.mois,&e.ddn.annee,&e.m);
            if (strcmp(e.nom,t)==0 || strcmp(e.prenom,t)==0)
            {
                k++;
            }
        }
        if (k>0)
        {
            etudiant *f;
            f=(etudiant*)malloc(k*sizeof(etudiant));
            int i=0;
            int j=0;
            int tab[k];
            rewind(fic);
            while (!feof(fic))
            {
                fscanf(fic,"%s %s %d/%d/%d %f\n",e.nom,e.prenom,&e.ddn.jour,&e.ddn.mois,&e.ddn.annee,&e.m);
                if (strcmp(e.nom,t)==0 || strcmp(e.prenom,t)==0)
                {
                    strcpy((f+i)->nom,e.nom);
                    strcpy((f+i)->prenom,e.prenom);
                    (f+i)->ddn.jour=e.ddn.jour;
                    (f+i)->ddn.mois=e.ddn.mois;
                    (f+i)->ddn.annee=e.ddn.annee;
                    (f+i)->m=e.m;
                    tab[i]=j; //enregistrement des lignes où se trouvent les etudiants à supprimer potentiellement.
                    i++;
                }
                j++;
            }
            fclose(fic);
            afficher_n_etudiant(k,f);
            free(f);
            do{
                printf("\nSaisir le numéro de l'etudiant a supprimer : ");
                scanf("%d",&i);
                i--;
            }while (i<0 && i>k-1);
            j=tab[i];
            supprimer_1_ligne(NomFichier,j);
            printf("\n\aSuppression effectuée.");
        }
        else
        {
            printf("\nAucun etudiant ne correspond a la recherche.");
        }
    }
    printf("\nRetour au menu suppression.");
    system("pause");
    system("cls");
}

void modifier_1_etudiant(const char *NomFichier[],int j)
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
        etudiant e;
        int i=0;
        printf("\nEntrez les nouvelles information de l'etudiant.");
        e=saisir_1_etudiant(1);
        rewind(fica);
        char texte[100];
        while (!feof(fica))
        {
            fgets(texte,99,fica);
            if (i!=j)
            {
                fputs(texte,ficn);
            }
            else
            {
                saisie_fichier_1_etudiant(ficn,e);
            }
            i++;
        }
    }
    fclose(fica);
    remove("temporaire.txt");
    fclose(ficn);
}

void modifier_etudiant()
{
    char NomFichier[Mmax];
    printf("\nNom du fichier : ");
    scanf("%s",NomFichier);
    system("cls");
    FILE *fic=fopen(NomFichier,"r");
    if (fic==NULL)
    {
        printf("\nErreur dans l'ouverture du fichier");
    }
    else
    {
        char t[nmax];
        printf("\nSaisissez le nom ou le prenom de l'etudiant a modifie : ");
        scanf("%s",t);
        system("cls");
        int k=0;
        etudiant e;
        rewind(fic);
        while (!feof(fic))
        {
            fscanf(fic,"%s %s %d/%d/%d %f\n",e.nom,e.prenom,&e.ddn.jour,&e.ddn.mois,&e.ddn.annee,&e.m);
            if (strcmp(e.nom,t)==0 || strcmp(e.prenom,t)==0)
            {
                k++;
            }
        }
        if (k>0)
        {
            etudiant *f;
            f=(etudiant*)malloc(k*sizeof(etudiant));
            int i=0;
            int j=0;
            int tab[k];
            rewind(fic);
            while (!feof(fic))
            {
                fscanf(fic,"%s %s %d/%d/%d %f\n",e.nom,e.prenom,&e.ddn.jour,&e.ddn.mois,&e.ddn.annee,&e.m);
                if (strcmp(e.nom,t)==0 || strcmp(e.prenom,t)==0)
                {
                    strcpy((f+i)->nom,e.nom);
                    strcpy((f+i)->prenom,e.prenom);
                    (f+i)->ddn.jour=e.ddn.jour;
                    (f+i)->ddn.mois=e.ddn.mois;
                    (f+i)->ddn.annee=e.ddn.annee;
                    (f+i)->m=e.m;
                    tab[i]=j; //enregistrement des lignes où se trouvent les etudiants à modifier potentiellement.
                    i++;
                }
                j++;
            }
            fclose(fic);
            afficher_n_etudiant(k,f);
            free(f);
            do{
                printf("\nSaisir le numéro de l'etudiant a modifier : ");
                scanf("%d",&i);
                i--;
            }while (i<0 && i>k);
            system("cls");
            j=tab[i];
            modifier_1_etudiant(NomFichier,j);
            printf("\n\aModification effectuée.");
        }
        else
        {
            printf("\nAucun etudiant ne correspond a la recherche.");
        }
    }
    printf("\nRetour au menu modification.");
    system("pause");
    system("cls");
}

void afficher_tous_les_etudiants()
{
    char NomFichier[Mmax];
    system("cls");
    printf("\nNom du fichier : ");
    scanf("%s",NomFichier);
    system("cls");
    FILE *fic=fopen(NomFichier,"r");
    if (fic==NULL)
    {
        printf("\nErreur dans l'ouverture du fichier");
        printf("\nVerifier l'existence du fichier saisi.");
    }
    else
    {
        int n=nombre_ligne(fic);
        printf("\nIl y a %d etudiant dans le fichier",n);
        etudiant *e;
        e=(etudiant*)malloc(n*sizeof(etudiant));
        int i;
        rewind(fic);
        for (i=0;i<n;i++)
        {
            fscanf(fic,"%s %s %d/%d/%d %f\n",(e+i)->nom,(e+i)->prenom,&(e+i)->ddn.jour,&(e+i)->ddn.mois,&(e+i)->ddn.annee,&(e+i)->m);
        }
        afficher_n_etudiant(n,e);
        free(e);
        fclose(fic);
        system("pause");
    }
    printf("\nRetour au menu recherche et affichage.");
    system("pause");
    system("cls");
}
