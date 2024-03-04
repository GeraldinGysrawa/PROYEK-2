#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Fungsi untuk mendekripsi sandi yang dienkripsi
void decryptPassword(char *password, int shift) {
    int i;
    for (i = 0; password[i] != '\0'; ++i) {
        // Periksa apakah karakter huruf besar
        if (password[i] >= 'A' && password[i] <= 'Z') {
            password[i] = 'Z' - (( 'Z' - password[i] + shift) % 26);
        }
        // Periksa apakah karakter huruf kecil
        else if (password[i] >= 'a' && password[i] <= 'z') {
            password[i] = 'z' - (('z' - password[i] + shift) % 26);
        }
    }
}

// Fungsi untuk membaca sandi yang dienkripsi dari file
void readEncryptedPassword(char *encryptedPassword) {
    FILE *file = fopen("save_pw.txt", "r");
    if (file != NULL) {
        fgets(encryptedPassword, 100, file);
        fclose(file);
    }
}

// Fungsi untuk menyimpan sandi yang dienkripsi ke dalam file tanpa menghapus data sebelumnya
void saveEncryptedPassword(char *encryptedPassword) {
    FILE *file = fopen("save_pw.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s\n", encryptedPassword);
        fclose(file);
    }
}

int main() {
    char password[100]; // Ukuran sandi yang lebih besar
    int shift = 3; // Pergeseran enkripsi yang digunakan

    // Meminta pengguna untuk memasukkan sandi
    printf("Masukkan sandi: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // Menghapus karakter newline dari input

    // Mengenkripsi sandi
    encryptPassword(password, shift);

    // Menyimpan sandi yang dienkripsi ke dalam file
    FILE *file = fopen("save_pw.txt", "w");
    if (file != NULL) {
        fputs(password, file);
        fclose(file);
    }
    printf("Catatan telah dikunci.\n");

    // Meminta pengguna untuk memasukkan sandi untuk membuka catatan
    printf("Masukkan sandi untuk membuka catatan: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // Menghapus karakter newline dari input

    // Membaca sandi yang disimpan dari file dan mendekripsinya
    char storedEncryptedPassword[100];
    readEncryptedPassword(storedEncryptedPassword);
    decryptPassword(storedEncryptedPassword, shift);

    // Memeriksa apakah sandi yang dimasukkan oleh pengguna cocok dengan sandi yang disimpan
    if (strcmp(password, storedEncryptedPassword) == 0) {
        printf("Catatan telah terbuka.\n");

        // Tambahkan logika untuk membuka catatan di sini
    } else {
        printf("Kata sandi salah. Catatan gagal dibuka.\n");
    }

    return 0;
}

