#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 50 



typedef struct{  //structure de date de creation de tache 
	int jour;
	int mois;
	int annee;
}date_echeance;


typedef struct{  // structure de tache
	char titre[40];
	char description[100];
	date_echeance dates;
	int priorite;
}tache;


//fonction qui permet de creer une nouvelle tache
tache add(){
	tache ta; //objet jdid de type tache
	
	printf("entrer le titre de tache :");
	scanf("%s", &ta.titre);
	
	printf("entrer la description de tache :");
	scanf("%s", &ta.description);
	
	printf("entrer la date de tache\n");
	
	printf("jour :");!
	scanf("%d", &ta.dates.jour);
	
	printf("mois :");
	scanf("%d", &ta.dates.mois);
	
	printf("annee :");
	scanf("%d", &ta.dates.annee);
	
	printf("entrer la priorite de tache (0 low / 1 hight) :");
	scanf("%d", &ta.priorite);
	
	return ta;
}

//fonction pour affichge des taches
void afficher(tache ta){
	printf("----------------------- Informations de %s ----------------------\n", ta.titre);
	printf("\n Titre : %s\n", ta.titre);
    printf("\n description : %s\n", ta.description);
    printf("\n----date de creation----\n");
    printf("\n %d / %d / %d \n", ta.dates.jour,  ta.dates.mois,  ta.dates.annee);
    printf("\n priorite : %s\n", ta.priorite? "Hight" : "Low"); //hight::true  low::false
}

//fonction pour modifier une tache
void edit(tache ta[], int index){
	printf("modifier les information de : %s \n", ta[index].titre);

        printf("entrer le nouveu titre :");
        scanf("%s", &ta[index].titre);

        printf("entrer le nouveu description :");
        scanf("%s", &ta[index].description);

        printf("modifier la date de creation \n");
        
        printf("entrer la nouvelle jour : ");
        scanf("%d", &ta[index].dates.jour);
        
        printf("entrer la nouvelle mois : ");
        scanf("%d", &ta[index].dates.mois);
        
        printf("entrer la nouvelle annee : ");
        scanf("%d", &ta[index].dates.annee);

        printf("entrer le nouveu priorite :");
        scanf("%d", &ta[index].priorite);
}

//fonction de suppression d'une tache 
void delet(tache taches[], int nbr_tache, int index){
	for(int i=index; i<(nbr_tache)-1; i++){
		taches[i]=taches[i+1]; //tache 4 suppreimer la tache 5 ghatwlli f case 4 
	}
		nbr_tache--; 
}

int main(){
	int choix;
	tache taches[max];
	int nbr_tache=0;
	
	do{
		printf("\n********Menu********\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher les taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Supprimer une tache\n");
        printf("6. Quitter\n");
        
        printf("votre choix :");
        scanf("%d", &choix);
        
        switch(choix){
        	case 1:
        		taches[nbr_tache]=add(); //ajout d'une nouvelle tache dans le tableau taches en fonction de la fonction add
        		nbr_tache++; //incrementation des nbr de taches
        	break;
        	
        	case 2:
        		int i;
        		if(nbr_tache==0){ //condition pour verification de tache exist ou non 
        			printf("pas de tache pour afficher");
				}
				else{
					printf("entrer l'index pour afficher :");
					scanf("%d" ,&i);
					afficher(taches[i]); //affichage de l'index i dans tableau taches[]
				}	
        	break;
        	
        	case 3:
        		int index; 
        		if(nbr_tache==0){ //condition pour verification de tache exist ou non 
        			printf("pas de tache pour afficher");
				}
					printf("entrer l'index pour modifier :");
				    scanf("%d", &index);
					if(index>=0 && index<=nbr_tache){ //condition pour verifier if index a modifier exist ou non 
						edit(taches, index);
					}
        	
					else{
						printf("pas de tache a modifier");
					}	
        	break;
				
        	case 4:
        		if(nbr_tache==0){
        			printf("pas de tache a supprimer");
				}
				else{
					int index;
					printf("entrer l'index de tache a supprimer :");
					scanf("%d", &index);
					if(index>=0 && index<nbr_tache){
						delet(taches, nbr_tache, index);
						printf("tache supprimer");
					}
					else{
						printf("indice invalide");
					}
						
				}
        	break;
		}
	}while(choix<6);
	
	
}
