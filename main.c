#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    float c;
    float algo;
    float analyse;
    float algebre;
} notes;

typedef struct
{
    int groupe;
    int codeID;
    char prenom[15];
    char nom[15];
    notes* resultat;
    float moyenne;
} student;

typedef struct cellule
{
    student E;
    struct cellule *next;
} cellule;

cellule *insertion_debut(cellule *A,student B);
cellule *insertion_fin(cellule *A,student B);
void aff_liste(cellule *A);
student Ajouter_cellule(cellule *A,student B);
cellule *suppression(cellule *A,int nb);
cellule *Update_student(cellule *A,student B,int nb);
cellule *Chercher_student(cellule *A,int nb);
int vrf_liste_triee(cellule *A);
cellule *insertion_milieu(cellule *A,student B);
cellule *trier_liste(cellule *A);
cellule *Trouver_max(cellule *A);
cellule *Trouver_min(cellule *A);
void afficher_etudiant(cellule *A);
cellule *trier_alphabie(cellule *A);
int calcul_nb_etudiant(cellule *A);
float calcul_moyenne(cellule *A);
void etat_etudiant(cellule *A);
int vrf_liste_alph(cellule *A);
cellule *insert_mil_alph(cellule *A,student B);
void suppression_tous(cellule **A);
void menu();

int main()
{
    cellule *L,*S;
    student T;
    L=NULL;
    int n,i,choix,m;
    printf("\n  Remarque : codeID est un attribut numerique, et chaque etudiant a son propre codeID ! ");
    printf("\n\n\t Veuillez saisir le nombre des etudiants que vous voulez inscrire : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\n\t Les informations de l'etudiant %d : ",i+1);
        T=Ajouter_cellule(L,T);
        L=insertion_fin(L,T);
    }
    system("CLS");
    printf("\n\t ==> Voici la liste des etudiants : ");
    aff_liste(L);
    printf("\n");
    menu();
    do
    {
        printf("\n\t choisir une fontion parmi ces fonctions : ");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1 :
        {
            printf("\n\t Les informations de l'etudiant : ");
            T=Ajouter_cellule(L,T);
            L=insertion_fin(L,T);
            printf("\n\t La nouvelle liste des etudiants : ");
            aff_liste(L);
            menu();
        }
        break;
        case 2 :
        {
            printf("\n\t Les informations de l'etudiant : ");
            T=Ajouter_cellule(L,T);
            L=insertion_debut(L,T);
            printf("\n\t La nouvelle liste des etudiants : ");
            aff_liste(L);
            menu();
        }
        break;
        case 3 :
        {
            printf("\n\t Tapez le codeID de l'etudiant que vous voulez supprimer : ");
            scanf("%d",&m);
            if(Chercher_student(L,m) != NULL){
                L=suppression(L,m);
                system("CLS");
                printf("\n\t La nouvelle liste des etudiants : ");
                aff_liste(L);
            }else{
                printf("\n\t Il n'existe aucun etudiant porte ce code !!!");
            }
            menu();
        }
        break;
        case 4 :
        {
            printf("\n\t Tapez le codeID de l'etudiant que vous voulez modifier ses informationts : ");
            scanf("%d",&m);
            if(Chercher_student(L,m) != NULL){
                printf("\n\t Donnez les nouvelles informations de cet etediant : ");
                T=Ajouter_cellule(L,T);
                L=Update_student(L,T,m);
                system("CLS");
                printf("\n\t La nouvelle liste des etudiants : ");
                aff_liste(L);
            }else{
                printf("\n\t Il n'existe aucun etudiant porte ce code !!!");
            }
            menu();
        }
        break;
        case 5 :
        {
            printf("\n\t Tapez le codeID de l'etudiant que vous voulez chercher : ");
            scanf("%d",&m);
            S=Chercher_student(L,m);
            if(S==NULL) printf("\n\t L'etudiant que vous cherchez n'existe pas dans la liste !");
            else
            {
                printf("\n\t Voici les informations de l'etudiant que vous cherchez : ");
                afficher_etudiant(S);
                menu();
            }
        }
        break;
        case 6 :
        {
            m=vrf_liste_triee(L);
            if(m==0)   printf("\n\t La liste est vide !!");
            if(m==-1)  printf("\n\t La liste n'est pas triee ! Donc vous ne pouvez pas inserer aucun etudiant.");
            else
            {
                printf("\n\t Tapez les informations de l'etudiant que vous voulez inserer : ");
                T=Ajouter_cellule(L,T);
                L=insertion_milieu(L,T);
                printf("\n\t La nouvelle liste des etudiants : ");
                aff_liste(L);
                menu();
            }
        }
        break;
        case 7 :
        {
            printf("\n\t La liste est triee selon la moyenne par ordre decroissant : ");
            L=trier_liste(L);
            aff_liste(L);
            menu();
        }
        break;
        case 8 :
        {
            S=Trouver_max(L);
            printf("\n\t Voici les informations de l'etudiant qui a la plus grande moyenne (le majorant): ");
            afficher_etudiant(S);
            menu();
        }
        break;
        case 9 :
        {
            S=Trouver_min(L);
            printf("\n\t Voici les informations de l'etudiant qui a la plus petite moyenne (le minorant): ");
            afficher_etudiant(S);
            menu();
        }
        break;
        case 10 :
        {
            printf("\n\t La liste est triee selon les noms des etudiants par ordre alphabetique : ");
            L=trier_alphabie(L);
            aff_liste(L);
            menu();
        }
        break;
        case 11 :
        {
            printf("\n\t le nombre des etudiants enregistres dans la liste est : %d",calcul_nb_etudiant(L));
            menu();
        }
        break;
        case 12 :
        {
            printf("\n\t la moyenne generale des etudiants du Genie informatique est : %f",calcul_moyenne(L));
            menu();
        }
        break;
        case 13 :
        {
            printf("\n\t Voici l'etat de chaque etudiant de votre liste : ");

            etat_etudiant(L);
            menu();
        }
        break;
        case 14 :
        {
            m=vrf_liste_alph(L);
            if(m==1)
            {
                printf("\n\t Tapez les informations de l'etudiant que vous voulez inserer : ");
                T=Ajouter_cellule(L,T);
                L=insert_mil_alph(L,T);
                printf("\n\t La nouvelle liste des etudiants : ");
                aff_liste(L);
                menu();
            }
            else  printf("\n\t La liste n'est pas triee ! Donc vous ne pouvez pas inserer aucun etudiant.");
        }
        break;
        case 15 :
        {
            suppression_tous(&L);
            printf("\n\t Fin de traitement ! Merci beaucoup.");
        }
        break;
        default :
            printf("\n\t Choix non validee");
            break;
        }
    }
    while(choix!=15);
    return 0;
}
cellule *insertion_debut(cellule *A,student B)
{
    cellule *nouv;
    nouv=(cellule*)malloc(sizeof(cellule));
    nouv->E=B;
    nouv->next=NULL;
    if(A==NULL)  return nouv;
    nouv->next=A;
    A=nouv;
    return A;
}
cellule *insertion_fin(cellule *A,student B)
{
    cellule *nouv,*tmp;
    nouv=(cellule*)malloc(sizeof(cellule));
    nouv->E=B;
    nouv->next=NULL;
    if(A==NULL)  return nouv;
    tmp=A;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=nouv;
    return A;
}
void aff_liste(cellule *A)
{
    cellule *tmp;
    tmp=A;
    int i=1;
    while(tmp!=NULL)
    {
        printf("\n\t L'etudiant numero %d : ",i);
        printf("\n codeID :%d",tmp->E.codeID);
        printf("\n Groupe :%d",tmp->E.groupe);
        printf("\n nom complet :%s  %s",tmp->E.prenom,tmp->E.nom);
        printf("\n Les notes:\n\t Langage C : %f",tmp->E.resultat->c);
        printf("\n\t Algo : %f\n\t Analyse : %f",tmp->E.resultat->algo,tmp->E.resultat->analyse);
        printf("\n\t Algebre : %f",tmp->E.resultat->algebre);
        printf("\n La moyenne = %f",tmp->E.moyenne);
        tmp=tmp->next;
        i++;
    }
}
student Ajouter_cellule(cellule *A,student B)
{
    printf("\n codeID : ");
    scanf("%d",&B.codeID);
    printf(" Groupe : ");
    scanf("%d",&B.groupe);
    printf(" le prenom :");
    fflush(stdin);
    gets(B.prenom);
    printf(" le nom :");
    fflush(stdin);
    gets(B.nom);
    // Alouer la mémoire pour les notes de l'étudiant :
    notes* resultat = (notes*)malloc(sizeof(notes));
    B.resultat = resultat;
    printf(" Les notes : ");
    do
    {
        printf("\n\t Langage C : ");
        scanf("%f",&B.resultat->c);
        if (B.resultat->c < 0 || B.resultat->c > 20)
            printf("\n\t Veuillez entrer un nombre entre 0 et 20.");
    }
    while(B.resultat->c < 0 || B.resultat->c > 20);
    do
    {
        printf("\t Algo : ");
        scanf("%f",&B.resultat->algo);
        if (B.resultat->algo < 0 || B.resultat->algo > 20)
            printf("\n\t Veuillez entrer un nombre entre 0 et 20.");
    }
    while(B.resultat->algo < 0 || B.resultat->algo > 20);
    do
    {
        printf("\t Analyse : ");
        scanf("%f",&B.resultat->analyse);
        if (B.resultat->analyse < 0 || B.resultat->analyse > 20)
            printf("\n\t Veuillez entrer un nombre entre 0 et 20.");
    }
    while(B.resultat->analyse < 0 || B.resultat->analyse > 20);
    do
    {
        printf("\t Algebre : ");
        scanf("%f",&B.resultat->algebre);
        if (B.resultat->algebre < 0 || B.resultat->algebre > 20)
            printf("\n\t Veuillez entrer un nombre entre 0 et 20.\n");
    }
    while(B.resultat->algebre < 0 || B.resultat->algebre > 20);
    // Calculer la moyenne de l'étudiant :
    float s = B.resultat->c + B.resultat->algo + B.resultat->analyse + B.resultat->algebre;
    B.moyenne = s/4;
    printf(" La moyenne = %f",B.moyenne);
    return B;
}

cellule *suppression(cellule *A,int nb){
    cellule *tmp,*p;
    tmp=A;
    if(A==NULL) return NULL;

    if(A->E.codeID==nb)
    {
        A=A->next;
        free(tmp->E.resultat);
        free(tmp);
        return A;
    }
    while(tmp->next!=NULL && tmp->next->E.codeID!=nb)
        tmp=tmp->next;

    if(tmp->next->E.codeID==nb)
    {
        p=tmp->next;
        tmp->next=p->next;
        p->next=NULL;
        free(p->E.resultat);
        free(p);
        return A;
    }
    return A;
}

cellule* Update_student(cellule *L, student T, int codeID) {
    cellule *p = Chercher_student(L, codeID);
    if (p != NULL) {
        p->E = T;
        printf("\n\t Modification reussie.\n");
    } else {
        printf("\n\t Cet etudiant n'est pas trouvee dans la liste.\n");
    }
    return L;
}

cellule *Chercher_student(cellule *A,int nb)
{
    cellule *tmp;
    tmp=A;
    while(tmp!=NULL && tmp->E.codeID!=nb)
    {
        tmp=tmp->next;
    }
    if(tmp==NULL)
        return NULL;
    return tmp;
}
int vrf_liste_triee(cellule *A)
{
    cellule *tmp=A,*p;
    if(tmp==NULL)
        return 0;
    p=tmp->next;

    while(p!=NULL)
    {
        if(tmp->E.moyenne < p->E.moyenne)
            return -1;
        tmp=tmp->next;
        p=p->next;
    }
    return 1;
}
cellule *insertion_milieu(cellule *A,student B)
{
    cellule *nouveau,*tmp,*p;
    nouveau = (cellule*)malloc(sizeof(cellule));
    nouveau->E=B;
    nouveau->next=NULL;
    if(A==NULL)      return nouveau;
    tmp=A;
    p=A;
    while(tmp!=NULL)
    {
        if(A->E.moyenne < B.moyenne)
        {
            nouveau->next=tmp;
            A=nouveau;
            return A;
        }
        else if(tmp->E.moyenne < B.moyenne)
        {
            nouveau->next=tmp;
            p->next=nouveau;
            return A;
        }
        p=tmp;
        tmp=tmp->next;
    }
    nouveau=insertion_fin(A,B);
    return A;
}
cellule *trier_liste(cellule *A)
{
    cellule *tmp,*p;
    student C;
    for(tmp=A; tmp!=NULL; tmp=tmp->next)
    {
        for(p=tmp->next; p!=NULL; p=p->next)
        {
            if(tmp->E.moyenne < p->E.moyenne)
            {
                C=p->E;
                p->E=tmp->E;
                tmp->E=C;
            }
        }
    }
    return A;
}
cellule *Trouver_max(cellule *A)
{
    cellule *tmp,*p;
    tmp=A;
    p=tmp;
    float max;
    max=tmp->E.moyenne;
    while(tmp!=NULL)
    {
        if(tmp->E.moyenne > max)
        {
            max=tmp->E.moyenne;
            p=tmp;
        }
        tmp=tmp->next;
    }
    return p;
}
cellule *Trouver_min(cellule *A)
{
    cellule *tmp,*p;
    tmp=A;
    p=tmp;
    float min;
    min=tmp->E.moyenne;
    while(tmp!=NULL)
    {
        if(tmp->E.moyenne < min)
        {
            min=tmp->E.moyenne;
            p=tmp;
        }
        tmp=tmp->next;
    }
    return p;
}
void afficher_etudiant(cellule *A)
{
    printf("\n codeID :%d",A->E.codeID);
    printf("\n Groupe :%d",A->E.groupe);
    printf("\n nom complet :%s  %s",A->E.prenom,A->E.nom);
    printf("\n Les notes:\n\t Langage C : %f",A->E.resultat->c);
    printf("\n\t Algo : %f\n\t Analyse : %f",A->E.resultat->algo,A->E.resultat->analyse);
    printf("\n\t Algebre : %f",A->E.resultat->algebre);
    printf("\n La moyenne = %f",A->E.moyenne);
}
cellule *trier_alphabie(cellule *A)
{
    cellule *tmp,*p;
    student C;
    for(tmp=A; tmp!=NULL; tmp=tmp->next)
    {
        for(p=tmp->next; p!=NULL; p=p->next)
        {
            if(strcmp(tmp->E.nom,p->E.nom)==1)
            {
                C=p->E;
                p->E=tmp->E;
                tmp->E=C;
            }
        }
    }
    return A;
}
int calcul_nb_etudiant(cellule *A)
{
    cellule *tmp=A;
    int i=0;
    while(tmp!=NULL)
    {
        i++;
        tmp=tmp->next;
    }
    return i;
}
float calcul_moyenne(cellule *A)
{
    cellule *tmp=A;
    int i=0;
    float s=0,m;
    while(tmp!=NULL)
    {
        s=s+tmp->E.moyenne;
        i++;
        tmp=tmp->next;
    }
    m=s/i;
    return m;
}
void etat_etudiant(cellule *A)
{
    cellule *tmp=A;
    while(tmp!=NULL)
    {
        if(tmp->E.moyenne>=12)
            printf("\n\t %s %s est valide ",tmp->E.prenom,tmp->E.nom);
        else  printf("\n\t %s %s n'est pas valide ",tmp->E.prenom,tmp->E.nom);
        tmp=tmp->next;
    }
}
int vrf_liste_alph(cellule *A)
{
    cellule *tmp=A,*p;
    p=tmp->next;
    while(p!=NULL)
    {
        if(strcmp(tmp->E.nom,p->E.nom)==1)
            return 0;
        tmp=tmp->next;
        p=p->next;
    }
    return 1;
}
cellule *insert_mil_alph(cellule *A,student B)
{
    cellule *nouveau,*tmp,*p;
    nouveau = (cellule*)malloc(sizeof(cellule));
    nouveau->E=B;
    nouveau->next=NULL;
    if(A==NULL)      return nouveau;

    if(strcmp(B.nom,A->E.nom)== -1)
    {
        nouveau->next=A;
        A=nouveau;
        return A;
    }
    p=A;
    tmp=A->next;
    while(tmp!=NULL)
    {
        if(strcmp(tmp->E.nom,B.nom)==1)
        {
            nouveau->next=tmp;
            p->next=nouveau;
            return A;
        }
        p=tmp;
        tmp=tmp->next;
    }
    nouveau=insertion_fin(A,B);
    return A;
}

void suppression_tous(cellule **A){
    cellule *tmp;
    while (*A != NULL) {
        tmp = *A;
        *A = (*A)->next;
        free(tmp->E.resultat);
        free(tmp);
    }
}

void menu()
{
    printf("\n");
    system("pause");
    printf("\n");
    system("CLS");
    printf("\n\t //******Menu******// : ");
    printf("\n\t 1->Ajouter un etudiant a la fin d'une liste ");
    printf("\n\t 2->Ajouter un etudiant au debut d'une liste ");
    printf("\n\t 3->Supprimer un etudiant ");
    printf("\n\t 4->Modifier les informationts d'un etudiant ");
    printf("\n\t 5->Chercher un etudiant s'il existe ");
    printf("\n\t 6->insertion dans une liste deja triee (selon leur moyenne) ");
    printf("\n\t 7->Trier la liste des etudiants selon leur moyenne ");
    printf("\n\t 8->Afficher les informations l'etudiant qui a la plus grande moyenne (le majorant) ");
    printf("\n\t 9->Afficher les informations l'etudiant qui a la plus petite moyenne (le minorant) ");
    printf("\n\t 10->Trier la liste des etudiants selon l'ordre alphabetique des noms des etudiants ");
    printf("\n\t 11->Calculer le nombre des etudiants enregistres dans la liste ");
    printf("\n\t 12->Calculer la moyenne generale des etudiants du Genie informatique ");
    printf("\n\t 13->Afficher l'etat de chaque etudiant (valide / non valide) ");
    printf("\n\t 14->insertion dans une liste deja triee (selon l'ordre alphabetique des noms des etudiants)");
    printf("\n\t 15->Fin du traitement ");
}

