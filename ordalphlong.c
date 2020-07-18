/*
**
** QWASAR.IO -- ord_alphlong
**
** @param {char*} param_1
**
** @return {char*}
**
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototypes.h"

char* ord_alphlong(char* param_1) {

  int s = countwords(param_1);
  int* intarr = strlenarray(param_1);;
  char arr[s][256];  
  int length = strlen(param_1);

  chararray(param_1, s, arr);
  lengthsort(s,arr,intarr);
  alphasort(s, arr, intarr);
  alphasort(s, arr, intarr);

  char* returnvalue;
  returnvalue = malloc(sizeof(char) * length);
  
  int index, index2 = 0, index3 = 0;

  for (index = 0; index < length; index++) {
  
    if (index2 >= s) 
      break;
    
    returnvalue[index] = arr[index2][index3];
    index3++;

    if (arr[index2][index3] == '\0') { 
      index2++;
      index3 = 0;
    }    
  }
  
  index2 = 0; index3 = 0;

  for (index = 0; index < length; index++) {
    
    if (returnvalue[index] == 32) {
      if( strlen(arr[index2+1]) > strlen(arr[index2]) ) {
        returnvalue[index] = '^';
        index2++;
      }
    }
  }
  free(intarr);

  return returnvalue;
}

int main () {
  char* param_1 = "A a b B cc ca cd";
  char* param_2 = "Never take a gamble you are not prepared to lose";
  char* param_3 = "After all this time Always said Snape";
  printf("%s\n", ord_alphlong(param_1));
  printf("%s\n", ord_alphlong(param_2));
  printf("%s\n", ord_alphlong(param_3));

  int s = countwords(param_3);
  int* intarr = strlenarray(param_3);;
  char arr[s][256];  

  chararray(param_3, s, arr);
  lengthsort(s,arr,intarr);
  alphasort(s, arr, intarr);
  alphasort(s, arr, intarr);

  for (int index = 0; index < s; index++) {
    printf("%s ", arr[index]);

  }
  printf("%d\n", strcmp("this", "said"));
}