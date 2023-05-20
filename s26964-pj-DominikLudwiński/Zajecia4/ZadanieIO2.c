#include <stdio.h>

#define BYTES_PER_LINE 16

void printHexViewer(FILE *file) {
    unsigned char buffer[BYTES_PER_LINE];
    size_t bytesRead;
    unsigned long offset = 0;

    while ((bytesRead = fread(buffer, 1, BYTES_PER_LINE, file)) > 0) {
        printf("%08lx ", offset);
        
        for (size_t i = 0; i < BYTES_PER_LINE; i++) {
            if (i < bytesRead) {
                printf("%02X ", buffer[i]);
            } else {
                printf("   ");
            }
            
            if (i == BYTES_PER_LINE / 2 - 1) {
                printf(" ");
            }
        }
        
        printf(" ");
        
        for (size_t i = 0; i < bytesRead; i++) {
            if (buffer[i] >= 32 && buffer[i] <= 126) {
                printf("%c", buffer[i]);
            } else {
                printf(".");
            }
        }
        
        printf("\n");
        
        offset += bytesRead;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Podaj nazwę pliku jako argument programu.\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Nie można otworzyć pliku.\n");
        return 1;
    }

    printf("Loading file: %s\n\n", argv[1]);
    printHexViewer(file);
    printf("\nClosing file: %s\n", argv[1]);

    fclose(file);

    return 0;
}
