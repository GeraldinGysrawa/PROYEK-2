#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk mengenkripsi sandi dengan pergeseran sederhana
void encryptPassword(char *password, int shift) {
    int i;
    for (i = 0; i < 10; ++i) {
        // Periksa apakah karakter huruf besar
        if (password[i] >= 'A' && password[i] <= 'Z') {
            password[i] = 'A' + ((password[i] - 'A' + shift) % 26);
        }
        // Periksa apakah karakter huruf kecil
        else if (password[i] >= 'a' && password[i] <= 'z') {
            password[i] = 'a' + ((password[i] - 'a' + shift) % 26);
        }
    }
}

// Fungsi untuk menyimpan sandi yang dienkripsi ke dalam file
void saveEncryptedPassword(char *encryptedPassword) {
    FILE *file = fopen("save_pw.txt", "r++");
    if (file != NULL) {
        fputs(encryptedPassword, file);
        fclose(file);
    }
}

int main() {
    char password[10];
    int shift = 3; // Pergeseran enkripsi yang digunakan

    // Meminta pengguna membuat sandi baru
    printf("Masukkan sandi: ");
    fgets(password, sizeof(password), stdin);

    // Menghapus newline character dari input
//    size_t length = strlen(password);
//    if (password[length - 1] == '\n') {
//        password[length - 1] = NULL;
//    }

    // Mengenkripsi sandi
    encryptPassword(password, shift);

    // Menyimpan sandi yang dienkripsi ke dalam file
    saveEncryptedPassword(password);
    printf("Catatan telah dikunci.\n");

    return 0;
}

