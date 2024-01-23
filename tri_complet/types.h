/* $Id: types.h 1517 2009-12-01 11:14:28Z zalila $ */

#define FALSE 0
#define TRUE 1
#define MAX_ITEM 100

typedef struct {
  char nom[30], prenom[20];
  int age;
} ITEM;

typedef int (*compare_t) (ITEM, ITEM);
