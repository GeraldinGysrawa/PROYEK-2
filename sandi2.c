#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptPassword(char *password, int shift) {
    int i;
    for (i = 0; password[i] != NULL; ++i) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            password[i] = 'A' + ((password[i] - 'A' + shift) % 26);
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            password[i] = 'a' + ((password[i] - 'a' + shift) % 26);
        }
    }
}

void saveEncryptedPassword(char *encryptedPassword) {
    FILE *file = fopen("save_pw.txt", "a+"); 
    if (file != NULL) {
        fputs(encryptedPassword, file);
        fputc('\n', file); 
        fclose(file);
    }
}

int main() {
    char password[10];
    int shift = 3; 
    printf("Masukkan sandi: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = NULL; 

    encryptPassword(password, shift);

    saveEncryptedPassword(password);
    printf("Catatan telah dikunci.\n");

    return 0;
}

