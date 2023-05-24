#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file ;
    int n, number, i;
    file = fopen("file.txt", "r");
    
    if (file == NULL) {
        printf("Could not open the file\n");
        return 1;
    }
    fscanf(file, "%d", &n);
    
    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &number);
        printf("%d\n",number);
    }
    
    fclose(file);
 
return 0;
}
