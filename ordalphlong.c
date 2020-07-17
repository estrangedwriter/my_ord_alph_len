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
#include <ctype.h>

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

int strcicmp(char const *a, char const *b) {

    for (;; a++, b++) {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d != 0 || !*a)
            return d;
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
      if( strlen(arr[index2+1]) > strlen(arr[index2]) )
        returnvalue[index] = '^';
        index2++;
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
  int length = strlen(param_3);

  chararray(param_3, s, arr);
  lengthsort(s,arr,intarr);
  alphasort(s, arr, intarr);
  alphasort(s, arr, intarr);

  for (int index = 0; index < s; index++) {
    printf("%s ", arr[index]);

  }
  printf("%d\n", strcmp("this", "said"));
}