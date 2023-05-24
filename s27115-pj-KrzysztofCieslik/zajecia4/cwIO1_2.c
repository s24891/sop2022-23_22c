#include <stdio.h>

#define BUFFER_SIZE 16

void printHexDump(const char *file) {
      FILE *input;
       int bytesRead;
        unsigned long address ;
          int i;

    unsigned char buffer[BUFFER_SIZE];
   
    printf("Loading file: %s\n\n", file);

  
    input = fopen(file, "rb"); 
    if (input == NULL) {
        printf("Cannot open file: %s\n", file);
        return;
    }

   
    address= 0;
  
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        printf("%08lX  ", address);

        for (i = 0; i < BUFFER_SIZE; i++) {
            if (i < bytesRead) {
                printf("%02X ", buffer[i]);
            } else {
                printf("   ");
            }

            if (i == BUFFER_SIZE / 2 - 1) {
                printf(" ");
            }
        }

        printf(" ");
        for (i = 0; i < bytesRead; i++) {
            if (buffer[i] >= 32 && buffer[i] <= 126) {
                printf("%c", buffer[i]);
            } else {
                // zdecydowalem sie na wyswietlenie kropki jesli znak nie 
                //jest ASCII tak jak to jest zrealizowane w wiekszosci mi znanych edytorow hex
                printf(".");
            }
        }

        printf("\n");

        address += bytesRead;
    }

    fclose(input);

    printf("\nClosing file: %s\n", file);
}

int main(int argc, char *argv[]) {
    char *file;
    if (argc != 2) {
        printf("Provide the file name as a parameter.\n");
        return 1;
    }
    file = argv[1];
    printHexDump(file);
    return 0;
}