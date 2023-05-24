#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n;
    char blank;
    char treeChunk;
    int i;
    int k;
    n=atoi(argv[1]);
    blank = ' ';
         treeChunk = '*';
   
    if (argc != 2) {
        printf("Enter the height of the Christmas tree as a parameter of the program call.\n");
        return 1;
    }

    
  


    for (i = 0; i < n; i++) {
        for (k = 0; k < n - i - 1; k++) {
        printf("%c", blank);
        }

        for (k = 0; k < (i + 1); k++) {
        printf("%c", treeChunk);
        }
    
        for (k = i; k > 0; k--) {
        printf("%c", treeChunk);
        }
    
    printf("\n");
    }
    return 0;
}