#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct { //structure de date
    int jour;
    int mois;
    int annee;
} date_echeance;

typedef struct {  //structure de tache
    char titre[40];
    char description[100];
    date_echeance dates;
    int priorite;
    int status;
} tache;

//fonction pour validationN de date
int valide(int jour, int mois, int annee) {
    if (annee < 2024) return 0;

    if (mois < 1 || mois > 12) return 0;

    int les_mois[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if (jour < 1 || jour > les_mois[mois]) return 0;

    return 1; 
}

//fonction ajouter nouvelle tache
tache add() {
    tache ta; // Objet jdid de type tache

    printf("Entrer le titre de tache : ");
    scanf(" %[^\n]%*c", ta.titre);

    printf("Entrer la description de tache : ");
    scanf(" %[^\n]%*c", ta.description);

    // checking date
    while (1) {
        printf("Entrer la date de tache (JJ MM AAAA): ");
        scanf("%d %d %d", &ta.dates.jour, &ta.dates.mois, &ta.dates.annee);

        if (valide(ta.dates.jour, ta.dates.mois, ta.dates.annee)) {
            break; // ila kan date valide loop exit
        } else {
            printf("Date invalide. Veuillez entrer une date valide.\n");
        }
    }

    // check priorite 1/0
    do {
        printf("Entrer la priorite de tache (0 low / 1 high) : ");
        scanf("%d", &ta.priorite);
    } while (ta.priorite != 0 && ta.priorite != 1);

    do {
        printf("Entrer la status de tache (0 incomplete / 1 complet) : ");
        scanf("%d", &ta.status);
    } while (ta.status != 0 && ta.status != 1);

    return ta;
}

// Function pour afficher tache
void afficher(tache ta) {
    printf("\n---------------------- Informations de %s ----------------------\n", ta.titre);
    printf("\nTitre : %s\n", ta.titre);
    printf("\nDescription : %s\n", ta.description);
    printf("\n---- Date de creation ----\n");
    printf("\n%02d/%02d/%d\n", ta.dates.jour, ta.dates.mois, ta.dates.annee);
    printf("\nPriorite : %s\n", ta.priorite ? "High" : "Low");
    printf("\nStatus : %s\n", ta.status ? "Complet" : "Incomplete");
}

// Function modifier tache
void edit(tache ta[], int index, int s) {
    printf("Modifier les informations de : %s \n", ta[index].titre);

    switch (s) {
        case 1:
            printf("Entrer le nouveau titre : ");
            scanf(" %[^\n]%*c", ta[index].titre);
            break;
        case 2:
            printf("Entrer le nouveau description : ");
            scanf(" %[^\n]%*c", ta[index].description);
            break;
        case 3:
            // date validation
            while (1) {
                printf("Modifier la date (JJ MM AAAA) : ");
                scanf("%d %d %d", &ta[index].dates.jour, &ta[index].dates.mois, &ta[index].dates.annee);
                if (valide(ta[index].dates.jour, ta[index].dates.mois, ta[index].dates.annee)) {
                    break; 
                } else {
                    printf("Date invalide. Veuillez entrer une date valide.\n");
                }
            }
            break;
        case 4:
            do {
                printf("Valeur invalide. Entrer la priorite de tache (0 low / 1 high) : ");
                scanf("%d", &ta[index].priorite);
            } while (ta[index].priorite != 0 && ta[index].priorite != 1);
            break;
        case 5:
            do {
                printf("Valeur invalide. Entrer la status de tache (0 incomplete / 1 complet) : ");
                scanf("%d", &ta[index].status);
            } while (ta[index].status != 0 && ta[index].status != 1);
            break;
        default:
            printf("Choix invalide\n");
    }
}

// Function pour supprimmer tache
void delet(tache taches[], int nbr_tache, int index) {
    for (int i = index; i < nbr_tache - 1; i++) {
        taches[i] = taches[i + 1]; 
    }
}

// Function pour filtrer par priorite
void fp(tache taches[], int nbr_tache, int pr) {
    printf("Les taches avec priorite : %s\n", pr ? "High" : "Low");
    for (int i = 0; i < nbr_tache; i++) {
        if (taches[i].priorite == pr) {
            afficher(taches[i]);
        }
    }
}

// Function pour filtrer par status
void status(tache taches[], int nbr_tache, int st) {
    printf("Les taches avec status : %s\n", st ? "complet" : "incomplete");
    for (int i = 0; i < nbr_tache; i++) {
        if (taches[i].priorite == st) {
            afficher(taches[i]);
        }
    }
}

//fonction pour validation de suppression
int confirm(tache taches[], int index){
    int v;
    printf("voulez vous supprimer cette tache ? (1 oui// 0 non) :");
    scanf("%d", &v);
    return v;
}



int main() {
    int choix;
    tache taches[MAX];
    int nbr_tache = 0;

    do {
        printf("\n******** Menu ********\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher les taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Supprimer une tache\n");
        printf("5. Filtrer par priorite\n");
        printf("5. Filtrer par status\n");
        printf("7. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                taches[nbr_tache] = add(); // Add new task
                nbr_tache++; // Increment task count
                break;

            case 2:
                if (nbr_tache == 0) {
                    printf("Pas de tache pour afficher\n");
                } else {
                    int i;
                    printf("Entrer l'index pour afficher : ");
                    scanf("%d", &i);
                    if (i >= 0 && i < nbr_tache) {
                        printf("\n-------------------------- Tache %d -----------------------------\n", i + 1);
                        afficher(taches[i]); // Display task at index i
                    } else {
                        printf("Index invalide\n");
                    }
                }
                break;

            case 3: {
                if (nbr_tache == 0) {
                    printf("Pas de tache pour modifier\n");
                } else {
                    int index, el;
                    printf("Vous avez %d taches\n", nbr_tache);
                    printf("Entrer l'index pour modifier : ");
                    scanf("%d", &index);
                    if (index >= 0 && index < nbr_tache) {
                        printf("Modifier l'element :\n");
                        printf("1. Titre\n2. Description\n3. Date\n4. Priorite\n5. Status\n");
                        printf("Votre choix : ");
                        scanf("%d", &el);
                        edit(taches, index, el); 
                    } else {
                        printf("Index invalide\n");
                    }
                }
                break;
            }

            case 4:
                if (nbr_tache == 0) {
                    printf("Pas de tache a supprimer\n");
                } else {
                    int index;
                    int v;
                    printf("Entrer l'index de tache a supprimer : ");
                    scanf("%d", &index);
                    if (index >= 0 && index < nbr_tache) {
                        if (confirm(taches, index))
                        {
                            delet(taches, nbr_tache, index);
                            nbr_tache--;
                            printf("Tache supprimee\n");
                        }
                        else
                        {
                            printf("supression anuller");
                        }   
                    } else {
                        printf("Indice invalide\n");
                    }
                }
                break;

            case 5: {
                int pr;
                if (nbr_tache == 0) {
                    printf("Pas de tache pour filtrer\n");
                } else {
                    printf("Entrer la priorite pour filtrer (0 Low / 1 High) : ");
                    scanf("%d", &pr);
                    fp(taches, nbr_tache, pr); 
                }
                break;
            }

             case 6: {
                int st;
                if (nbr_tache == 0) {
                    printf("Pas de tache pour filtrer\n");
                } else {
                    printf("Entrer la status pour filtrer (1 complete / 0 incomplete) : ");
                    scanf("%d", &st);
                    fp(taches, nbr_tache, st); 
                }
                break;
            }

            case 7:
                printf("Au revoir!\n");
                break;

            default:
                printf("Choix invalide\n");
                break;
        }
    } while (choix != 6);

    return 0;
}
