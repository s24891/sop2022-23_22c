#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file ;
    int n, number, i;
    int *tab;
    file = fopen("file.txt", "r");
    
    if (file == NULL) {
        printf("Could not open the file\n");
        return 1;
    }
    fscanf(file, "%d", &n);
    tab = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &number);
       tab[i] = number;
    }
    for (i = n; i >= 0; i--)
    {
         printf("%d\n",tab[i-1]);
    }
       free(tab);
    fclose(file);

return 0;
}