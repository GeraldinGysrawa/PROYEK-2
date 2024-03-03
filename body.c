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
