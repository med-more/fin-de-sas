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
