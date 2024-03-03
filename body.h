#ifndef BODY_H
#define BODY_H

#define MAX_CATATAN 1000 // Jumlah maksimum catatan yang dapat disimpan
#define MAX_KEY 100 // Panjang maksimum kunci enkripsi

// Struktur untuk menyimpan catatan
struct Catatan {
    int no;
    char judul[100];
    char tanggal[20];
    char isi[1000];
};

// Fungsi untuk menambahkan catatan baru
void tambahCatatan();

// Fungsi untuk mengenkripsi teks menggunakan algoritma Vigenere
void enkripsiVigenere(char teks[], char kunci[]);

#endif
