#include<stdio.h>
// Prototype
void identify_identical(int values[], int n);
int main(int argc, char *argv[]){
    printf("Welcome to Algorithmic Thinking!\n");
    int a[5] = {1, 2, 3, 1, 5};
    identify_identical(a, 5);
    return 0;
}


void identify_identical(int values[], int n) {
     int i, j;
     for (i = 0; i < n; i++){
         for (j = i+1; j < n; j++){
             if (values[i] == values[j]) {
                 printf("Twin integers found.\n");
                 return;
             }
         }
     }
     printf("No two integers are alike\n");
}
