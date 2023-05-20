#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 256
#define CHAT_FILE_PATH "/tmp/chat.txt"

// Funkcja do odczytywania wiadomości z pliku
void read_messages() {
    FILE *chat_file = fopen(CHAT_FILE_PATH, "r");
    if (chat_file == NULL) {
        printf("Nie można otworzyć pliku z wiadomościami.\n");
        return;
    }

    char message[MAX_MESSAGE_LENGTH];
    while (fgets(message, MAX_MESSAGE_LENGTH, chat_file) != NULL) {
        printf("%s", message);
    }

    fclose(chat_file);
}

// Funkcja do zapisywania wiadomości do pliku
void write_message(const char *message) {
    FILE *chat_file = fopen(CHAT_FILE_PATH, "a");
    if (chat_file == NULL) {
        printf("Nie można otworzyć pliku z wiadomościami.\n");
        return;
    }

    fprintf(chat_file, "%s\n", message);
    fclose(chat_file);
}

int main() {
    // Główna pętla programu
    while (1) {
        // Odczytaj istniejące wiadomości
        read_messages();

        // Pobierz nową wiadomość od użytkownika
        char new_message[MAX_MESSAGE_LENGTH];
        printf("> ");
        fgets(new_message, MAX_MESSAGE_LENGTH, stdin);

        // Usuń znak nowej linii z końca wiadomości
        new_message[strcspn(new_message, "\n")] = '\0';

        // Zapisz nową wiadomość do pliku
        write_message(new_message);
    }

    return 0;
}
