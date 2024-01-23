/* $Id: fonctions_basiques.c 1451 2009-10-20 07:23:13Z zalila $ */

#include<stdlib.h>
#include<math.h>

int pgcd (int a, int b) 
{
  return 1;
}

int ppcm (int a, int b) 
{
  return a * b / pgcd (a, b);
}

int* diviseurs (int a) 
{
  return NULL;
}
