#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

// Fungsi untuk mengenkripsi sandi dengan pergeseran sederhana
void encryptPassword(char *password, int shift) {
    int i;
    for (i = 0; password[i] != '\0'; ++i) {
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

// Fungsi untuk membaca sandi terenkripsi dari file
void readEncryptedPassword(char *encryptedPassword) {
    FILE *file = fopen("save_pw.txt", "r");
    if (file != NULL) {
        fgets(encryptedPassword, MAX_PASSWORD_LENGTH, file);
        fclose(file);
    }
}

int main() {
    char storedEncryptedPassword[MAX_PASSWORD_LENGTH];
    char enteredPassword[MAX_PASSWORD_LENGTH];
    int shift = 3; // Pergeseran enkripsi yang digunakan

    // Baca sandi terenkripsi dari file
    readEncryptedPassword(storedEncryptedPassword);

    // Dekripsi sandi yang terbaca dari file
    char storedPassword[MAX_PASSWORD_LENGTH];
    strcpy(storedPassword, storedEncryptedPassword); // Salin ke variabel baru untuk diubah
    encryptPassword(storedPassword, -shift); // Dekripsi sandi

    // Meminta pengguna untuk memasukkan sandi
    printf("Masukkan sandi: ");
    fgets(enteredPassword, MAX_PASSWORD_LENGTH, stdin);
    enteredPassword[strcspn(enteredPassword, "\n")] = NULL; // Menghapus karakter newline dari input

    // Enkripsi sandi yang dimasukkan oleh pengguna
    encryptPassword(enteredPassword, shift);

    // Bandingkan sandi yang dimasukkan oleh pengguna dengan sandi yang telah didekripsi dari file
    if (strcmp(storedPassword, enteredPassword) == 0) {
        printf("Sandi benar. Akses ke catatan diizinkan.\n");
        // Tempatkan logika untuk membuka catatan di sini
    } else {
        printf("Sandi salah. Akses ke catatan tidak diizinkan.\n");
    }

    return 0;
}

