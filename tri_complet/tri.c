/* $Id: tri.c 1517 2009-12-01 11:14:28Z zalila $ */

#include <stdio.h>
#include <string.h>
#include "types.h"
#include "fonctions.h"

/* ===================================================================== */

void swap (ITEM a[], int l, int r)
{
  ITEM s;
  s = a[r];
  a[r] = a[l];
  a[l] = s;
}

void quicksort (ITEM a[], int l, int r, compare_t less)
{ 
  int i, j;
  ITEM p;
  if (r > l)
    { 
      p = a[r]; i = l-1; j = r;
      while (TRUE)
	{ 
	  while ((*less) (a[++i], p)) ;
	  while ((*less) (p, a[--j])) if (j == l) break;
	  if (i >= j) break;
	  swap(a, i, j);
	}
      swap(a, i, r);
      quicksort(a, l, i-1, less);
      quicksort(a, i+1, r, less);
    } 
}

void Trier (ITEM items[], int nb_items, compare_t less)
{
  quicksort (items, 0, nb_items-1, less);
}

int inf_age_croissant (ITEM l, ITEM r) {
  return l.age < r.age;
}

int inf_age_decroissant (ITEM l, ITEM r) {
  return l.age > r.age;
}

int inf_alpha_nom (ITEM l, ITEM r) {
  return strcmp (l.nom, r.nom) < 0? 1 : 0;
}

int inf_alpha_prenom (ITEM l, ITEM r) {
  return strcmp (l.prenom, r.prenom) < 0? 1 : 0;
}

/* ===================================================================== */

void Choix (ITEM items[], int nb_items)
{
  char cas[10];
  
  while (TRUE) {
    printf("*** Tri :\n");
    printf("- 1 ou A - numerique selon l'Age (croissant)\n");
    printf("- 2 ou D - numerique selon l'age (Decroissant)\n");
    printf("- 3 ou N - alphabetique sur le Nom\n");
    printf("- 4 ou P - alphabetique sur le Prenom\n");
    
    scanf("%s", cas);
    
    switch (cas[0]) {
    case '1': case 'A': case 'a':
      Trier(items, nb_items, inf_age_croissant);
      return;
    case '2': case 'B': case 'b':
      Trier(items, nb_items, inf_age_decroissant);
      return;
    case '3': case 'N': case 'n':
      Trier(items, nb_items, inf_alpha_nom);
      return;
    case '4': case 'P': case 'p':
      Trier(items, nb_items, inf_alpha_prenom);
      return;
      
    default:
      printf("! Choix incorrect [%s] : entrer une autre valeur\n\n", cas);
    }
  }
}

/* ===================================================================== */

int main (void)
{
  ITEM items[MAX_ITEM];
  int nb_items;
  
  Lire(items, &nb_items);
  Choix(items, nb_items);
  Afficher(items, nb_items);
  return 0;
}


