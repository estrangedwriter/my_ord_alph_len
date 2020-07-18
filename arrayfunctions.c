/*
** QWASAR PROJECT, 2020
** my_ord_alph_len
** File description: This file includes the array functions for the program.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countwords(char* param_1) {
  
  int index = 0, count = 0;

  for ( index = 0; param_1[index] != '\0'; index++) {
    if (param_1[index] == 32)
      count++;
  }
  count++;
  return count;
}

int* strlenarray(char* param_1) {

  int index = 0, index2 = 0, count = 0, sizearray = countwords(param_1), length = strlen(param_1);
  int* strlenarray1;

  strlenarray1 = malloc(sizeof(int) * sizearray);

  for ( index = 0; index <= length; index++) {  
    count++;

    if (param_1[index] == 32) {
      strlenarray1[index2] = count - 1;
      count = 0;
      index2++;
    }
    else if (param_1[index] == '\0') {
      strlenarray1[index2] = count - 1;
      count = 0;
      break;
    }
  }
  return strlenarray1;
}

void chararray(char* param_1, int s, char array[s][256]) {
  
  int index = 0, index2 = 0, index3 = 0, length = strlen(param_1);
  char buffer[256];
    
  for ( ; index <= length; index++) {
    
    if (param_1[index] != 32) {
      buffer[index2] = param_1[index];
      index2++;
    }

    if (param_1[index] == 32) {
      buffer[index2] = param_1[index];
      buffer[index2+1] = '\0';
      strcpy(array[index3], buffer);
      index3++;
      index2 = 0;
    }

    else if (param_1[index] == '\0') {
      strcat(buffer," ");
      strcpy(array[index3], buffer);
      break;
    }
  }
}