<<<<<<< Updated upstream
=======
<<<<<<< Updated upstream
=======
#include "body.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Fungsi untuk mengenkripsi teks menggunakan algoritma Vigenere
void enkripsiVigenere(char teks[], char kunci[]) {
    int teksLen = strlen(teks);
    int kunciLen = strlen(kunci);
    int i, j;

    for (i = 0, j = 0; i < teksLen; ++i) {
        if (isalpha(teks[i])) {
            int shift = tolower(kunci[j % kunciLen]) - 'a';
            int base = islower(teks[i]) ? 'a' : 'A';
            teks[i] = ((teks[i] - base + shift) % 26 + base);
            j++;
        }
    }
}

// Fungsi untuk menambahkan catatan baru
void tambahCatatan() {
    struct Catatan catatan;

    printf("Masukkan judul catatan: ");
    scanf(" %s", catatan.judul);

    printf("Masukkan tanggal catatan (DD/MM/YYYY): ");
    scanf(" %s", catatan.tanggal);

    printf("Masukkan isi catatan:\n");
    scanf(" %[^\n]s", catatan.isi);

    // Enkripsi isi catatan sebelum disimpan
    char kunci[MAX_KEY];
    printf("Masukkan kunci enkripsi: ");
    scanf(" %s", kunci);

    enkripsiVigenere(catatan.isi, kunci);
    enkripsiVigenere(catatan.judul, kunci);

    FILE *file = fopen("catatan.txt", "a");
    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        return;
    }

    // Menulis catatan ke file
    fprintf(file, "%s %s %s\n", catatan.judul, catatan.tanggal, catatan.isi);

    fclose(file);

    printf("Catatan berhasil ditambahkan.\n");
}


/*IKHSAN*/
// Fungsi untuk mendekripsi teks menggunakan algoritma Vigenere
void dekripsiVigenere(char teks[], char kunci[]) {
    int teksLen = strlen(teks);
    int kunciLen = strlen(kunci);
    int i, j;

    for (i = 0, j = 0; i < teksLen; ++i) {
        if (isalpha(teks[i])) {
            int shift = tolower(kunci[j % kunciLen]) - 'a';
            int base = islower(teks[i]) ? 'a' : 'A';
            teks[i] = ((teks[i] - base - shift + 26) % 26 + base);
            j++;
        }
    }
}

// Fungsi untuk menampilkan daftar catatan
void tampilkanCatatan(struct Catatan *catatan, int jumlahCatatan) {
    printf("\t\t\tNo.  | Judul               | Tanggal\n");
    printf("\t\t\t--------------------------------------\n");
    for (int i = 0; i < jumlahCatatan; i++) {
        printf("\t\t\t%-5d| %-20s| %s\n", catatan[i].id, catatan[i].judul, catatan[i].tanggal);
    }
    printf("\t\t\t--------------------------------------\n");
}

// Fungsi untuk menampilkan isi catatan
void tampilkanIsiCatatanBerdasarkanJudul(struct Catatan *catatan, int jumlahCatatan, char *judul, char *kunciEnkripsi) {
    int ditemukan = 0;
    for (int i = 0; i < jumlahCatatan; i++) {
        if (strcmp(catatan[i].judul, judul) == 0) {
            ditemukan = 1;
            printf("\n\t\t\t=== Isi Catatan ===\n\n");
            printf("\t\t\tJudul : %s\n", catatan[i].judul);
            printf("\t\t\tTanggal: %s\n", catatan[i].tanggal);
            printf("\t\t\t-----------------------------------------\n");
            printf("\t\t\tIsi Pesan:\n");
            
            // mendekripsi dan menampilkan isi catatan
            char decryptedContent[500];
            strcpy(decryptedContent, catatan[i].konten);
            dekripsiVigenere(decryptedContent, kunciEnkripsi);
            printf("\n");
            printf("\t\t\t%s\n", decryptedContent);

            printf("\t\t\t-----------------------------------------\n");
            break;
        }
    }
    if (!ditemukan) {
        printf("Catatan dengan judul '%s' tidak ditemukan.\n", judul);
    }
}

// fungsi untuk mengedit catatan
void editCatatanBerdasarkanJudul(struct Catatan *catatan, int jumlahCatatan, char *judul, char *kunciEnkripsi) {
    for (int i = 0; i < jumlahCatatan; i++) {
        if (strcmp(catatan[i].judul, judul) == 0) {
            // Dekripsi catatan sebelum mengedit
            dekripsiVigenere(catatan[i].konten, kunciEnkripsi);
            
            printf("\t\t\tJudul: ");
            scanf(" %[^\n]s", catatan[i].judul);
            printf("\t\t\tTanggal (YYYY-MM-DD): ");
            scanf(" %[^\n]s", catatan[i].tanggal);
            printf("\t\t\tIsi pesan: ");
            scanf(" %[^\n]s", catatan[i].konten);
            
            // Enkripsi kembali catatan setelah mengedit
            enkripsiVigenere(catatan[i].konten, kunciEnkripsi);
            
            printf("Catatan dengan judul '%s' berhasil diubah.\n", judul);
            return;
        }
    }
    printf("Catatan dengan judul '%s' tidak ditemukan.\n", judul);
}

// fungsi untuk menghapus catatan
void hapusCatatanBerdasarkanJudul(struct Catatan *catatan, int *jumlahCatatan, char *judul) {
    int ditemukan = 0;
    for (int i = 0; i < *jumlahCatatan; i++) {
        if (strcmp(catatan[i].judul, judul) == 0) {
            ditemukan = 1;
            for (int j = i; j < *jumlahCatatan - 1; j++) {
                catatan[j] = catatan[j + 1];
            }
            (*jumlahCatatan)--;
            printf("Catatan dengan judul '%s' berhasil dihapus.\n", judul);
            break;
        }
    }
    if (!ditemukan) {
        printf("Catatan dengan judul '%s' tidak ditemukan.\n", judul);
    } else {
        simpanCatatanKeFile(catatan, *jumlahCatatan, "Catatan.txt");
    }
}
>>>>>>> Stashed changes
>>>>>>> Stashed changes
