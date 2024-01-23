/* $Id: tri.c 1516 2009-12-01 10:43:40Z zalila $ */

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

void quicksort (ITEM a[], int l, int r)
{ 
  int i, j;
  ITEM p;
  if (r > l)
    { 
      p = a[r]; i = l-1; j = r;
      while (TRUE)
	{ 
	  while (a[++i].age < p.age) ;
	  while (a[--j].age > p.age) if (j == l) break;
	  if (i >= j) break;
	  swap(a, i, j);
	}
      swap(a, i, r);
      quicksort(a, l, i-1);
      quicksort(a, i+1, r);
    } 
}

void Trier (ITEM items[], int nb_items)
{
  quicksort (items, 0, nb_items-1);
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
      Trier(items, nb_items);
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


