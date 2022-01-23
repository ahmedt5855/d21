#include <stdio.h>
int main() {
   int totalrows, space, rows, sign;
    printf("Enter the number of rows: ");
   scanf("%d", &totalrows);
   for(rows=1;rows<=totalrows;rows++)
   {
       //print space
       for(space=1;space<=totalrows-rows;space++)
        printf(" ");
        //print *
   for(sign=1;sign<=(2*rows)-1;sign++)
    printf("*");

   printf("\n");
   }

   return 0;
}
