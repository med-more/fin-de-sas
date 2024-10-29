#include<stdio.h>
#include<stdlib.h>
#include<string.h>



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
