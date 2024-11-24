#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
typedef struct{
        char identifiant[10];
        char password[10];
        char nom[10];
        char prenom[10];
        char email[10];
    }User;
User users[20];
int i=1;



void ajout(){
    int ad,j,cmp,c=0,a=0,b=0;
    char test[10],testcmp[10],id[10],pass[10];
    while(a==0){
        printf("donner votre id pour verifier si vous etes un admin : ");
        scanf("%s",id);
    ad=strcmp(id,"admin");
    if(ad==0)
        a++;
    }
    while(b==0){
        printf("donner votre password pour verifier si vous etes un admin : ");
        scanf("%s",pass);
    ad=strcmp(pass,"admin");
    if(ad==0)
        b++;
    }
    printf("entrer l'identifiant : ");
    scanf("%s",test);
    for(j=0;j<i;j++){
        cmp=strcmp(test,users[j].identifiant);
        if(cmp==0)
            c++;
    }
    if(c>0){
        printf("deja existe\n");
    }
    if(c==0){
        strcpy(users[i].identifiant,test);
        printf("entrer le nom : ");
        scanf("%s",users[j].nom);
        printf("entrer le prenom : ");
        scanf("%s",users[j].prenom);
        printf("entrer l'email : ");
        scanf("%s",users[j].email);
        printf("entrer le password : ");
        scanf("%s",users[j].password);
        i++;
        textcolor(2);
        cprintf("\n\nuser created\n");
    }
}



void login(User tab_u[20],int i){
    int k,comp,passcomp, c=0;
    char id[10], pass[10];
    printf("entrer votre identifiant : ");
    scanf("%s",id);
    for(k=0; k<i; k++){
        comp = strcmp(id, tab_u[k].identifiant);
        if(comp == 0){
            c++;
            break;
        }
    }
    if(c!=0){
        printf("entrer votre password : ");
        scanf("%s", pass);
        passcomp = strcmp(pass, tab_u[k].password);
        while(passcomp != 0){
            printf("mot de passe incorrect, entrer a nouveau le mot de passe : ");
            scanf("%s", pass);
            passcomp = strcmp(pass, tab_u[k].password);
        }
        textcolor(2);
            cprintf("\nbienvenue %s\n",id);
    } else {
        printf("identifiant n'existe pas !\n");
    }
}



void ch_pass(User tab_u[20],int i){
    int k=0,comp=0,c=0;
    char nom[10];
    re : printf("entrer votre identifiant : ");
    scanf("%s",nom);
    for(k=0;k<i;k++){
        comp=strcmp(nom,tab_u[k].identifiant);
        if(comp==0){
            c++;
        }
    }
        if(c==1){
            printf("entrer le nouveau password : ");
            scanf("%s",tab_u[k].password);
            textcolor(2);
            cprintf("Done!\n");

        }
        else{
            goto re;
        }
    }



void ch_pass_by_admin(User tab_u[20],int i){
    int k=0,comp,test,a=0,b=0;
    char id[10],pass[10],id2[10];
    while(a==0){
        printf("entrer votre id pour verifier si vous etes un admin : ");
        scanf("%s",id);
    comp=strcmp(id,"admin");
    if(comp==0)
        a++;
    }
    while(b==0){
        printf("donner votre password pour verifier si vous etes un admin : ");
        scanf("%s",pass);
    comp=strcmp(pass,"admin");
    if(comp==0)
        b++;
    }
    printf("donner l'identifiant : ");
    scanf("%s",id2);
    for(k=0;k<i;k++){
        comp=strcmp(id2,tab_u[k].identifiant);
        if(comp==0){
           re : printf("donner le nouveau password : ");
            scanf("%s",tab_u[k].password);
            textcolor(2);
            cprintf("Done!\n");
            break;
        }
        if(comp!=0)
            goto re;
    }
}



void affiche_liste(User users[20],int i){
        int j=0;
        for(j=0;j<i;j++)
        puts(users[j].identifiant);
}



void delete_user(){
    char id[10], tmp[10],pass[10];
    int a=0,b=0,ad,k,j,comp,c=0,d=0;
    while(a==0){
        printf("donner votre id pour verifier si vous etes un admin : ");
        scanf("%s",id);
    ad=strcmp(id,"admin");
    if(ad==0)
        a++;
    }
    while(b==0){
        printf("donner votre password pour verifier si vous etes un admin : ");
        scanf("%s",pass);
    ad=strcmp(pass,"admin");
    if(ad==0)
        b++;
    }
    repeat : printf("entrer l'identifiant de l'ustilisateur a supprimme: ");
    scanf("%s", id);
    for(k=0; k<i; k++){
        comp = strcmp(id, users[k].identifiant);
        if(comp == 0){
            c++;
            break;
        }
    }
    if(c==1){
        for(j=k;j<i;j++){
            strcpy(users[j].identifiant, users[j+1].identifiant);
            strcpy(users[j].password, users[j+1].password);
            strcpy(users[j].nom, users[j+1].nom);
            strcpy(users[j].prenom, users[j+1].prenom);
            strcpy(users[j].email, users[j+1].email);
        }
        i--;
        textcolor(2);
        cprintf("User deleted\n");
    }
    if(c==0){
        printf("Utilisateur n'existe pas\n");
        d++;
        if(d==3){
        printf("\nVous avez essayer 3 fois !! Repeter apres\n");
    }
        else
        goto repeat;
    }
}



void main(){
    int j;
    int choix,c=0;
    strcpy(users[0].identifiant,"admin");
    strcpy(users[0].password,"admin");
    while(c>=0&&c<=7){
    printf("1-Ajouter un utilisateur\n");
    printf("2-Login\n");
    printf("3-Changer le password par un utilisateur\n");
    printf("4-Changer le password par l'admin\n");
    printf("5-Afficher la liste des utilisateur\n");
    printf("6-Supprimmer un utilisateur\n");
    printf("7-Quiter\n");
    printf("donner votre choix : ");
    scanf("%d",&choix);

    if(choix==1){
        ajout();
    }

    if(choix==2){
        login(users,i);
    }

    if(choix==3){
        ch_pass(users,i);
    }

    if(choix==4){
        ch_pass_by_admin(users,i);
    }

    if(choix==5){
        affiche_liste(users,i);
    }

    if(choix==6){
        delete_user();
    }

    if(choix==7){
        printf("Bye!");
        exit(1);
    }

    system("pause");
    system("cls");
}
}
