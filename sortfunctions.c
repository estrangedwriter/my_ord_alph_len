/*
** QWASAR PROJECT, 2020
** my_ord_alph_len
** File description: This file includes the sort functions for the program.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *xp, int *yp) {

    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void lengthsort(int n, char name[][256] , int arr[]) {

   int i, j;
   char temp[256];

   for (i = 0; i <= n-1; i++)    {

        for (j = 0; j < n-i-1; j++)  {

            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                strcpy(temp,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],temp);
            }
        }
    }
}

void alphasort(int n, char name[][256], int arr[]) {

  int index, index2;
  char temp[256];

  for (index = 0; index < n-1; index++) {
    
    for (index2 = 0; index2 < n - 1; index2++)
      
      if (arr[index] == arr[index+1]) {
        
        if ( strcasecmp(name[index], name[index+1]) > 0) {
          strcpy(temp, name[index]);
          strcpy(name[index], name[index+1]);
          strcpy(name[index+1], temp);
        }
      }
    }
  }