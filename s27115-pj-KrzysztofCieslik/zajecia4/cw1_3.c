#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Enter the height of the Christmas tree as a parameter of the program call.\n");
        return 1;
    }

    int n =atoi(argv[1]);
    char blank = ' ';
    char treeChunk = '*';
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n - i - 1; k++) {
        printf("%c", blank);
        }

        for (int k = 0; k < (i + 1); k++) {
        printf("%c", treeChunk);
        }
    
        for (int k = i; k > 0; k--) {
        printf("%c", treeChunk);
        }
    
    printf("\n");
    }
}