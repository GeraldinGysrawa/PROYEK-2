#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NOTES 100
#define MAX_LENGTH 1000

// Struktur untuk menyimpan catatan
typedef struct {
    char title[50];
    char content[MAX_LENGTH];
} Note;

// Fungsi untuk membersihkan layar
void clearScreen() {
    system("cls");
}

// Fungsi untuk menampilkan logo kucing di tengah layar
void displayCatLogo() {
    // Menampilkan logo kucing
    printf("\t\t\t\t\t  /\\_/\\ \n");
    printf("\t\t\t\t\t ( >.< )	   ><(((('>   \n");
    printf("\t\t\t\t\t  > ~ < 	^^^^^^^^^^^^\n");
}

// Fungsi untuk menampilkan logo kucing menyapa
void animateCat() {
    // Menampilkan logo kucing menyapa
    printf("\t\t\t\t\t\t\t   /\\_/\\\n");
    printf("\t\t\t\t\t\t\t  ( -.- )\n");
    printf("\t\t\t\t\t\t\t   > ^ < \n");
    printf("\n \t\t\t\t Kucing menyapa...");
    usleep(2000000); // Jeda 2 detik
    printf("\n \t\t\t\t Maaf catatan yang kamu cari tidak ada.\n");
}

// Fungsi untuk menampilkan input judul dan isi catatan
void displayInputNote() {
    clearScreen(); // Membersihkan layar terminal
    displayCatLogo();
    printf("\t\t\t\t +-----------------------------------------------+\n");
    printf("\t\t\t\t +           MASUKKAN JUDUL DAN ISI CATATAN       +\n");
    printf("\t\t\t\t +-----------------------------------------------+\n");
}

// Fungsi untuk menampilkan border dan daftar catatan jika ada
void displayBorderAndNotes(Note notes[], int count) {
    clearScreen(); // Membersihkan layar terminal
    displayCatLogo();
    printf("\t\t\t\t +-----------------------------------------------+\n");
    printf("\t\t\t\t +	     SELAMAT DATANG DI MY MEMO		 +\n");	
    printf("\t\t\t\t +-----------------------------------------------+\n");
    printf("\n");
    if (count > 0) {
        printf("\t\t\t\t +-----------------------------------------------+\n");
        printf("\t\t\t\t +              Daftar Catatan:               +\n");
        printf("\t\t\t\t +            	---------------                  +\n");
        for (int i = 0; i < count; i++) {
            printf("\t\t\t\t + %d. %-40s +\n", i + 1, notes[i].title);
        }
        for (int i = count; i < 10; i++) {
            printf("\t\t\t\t + %-45s +\n", "");
        }
        printf("\t\t\t\t +-----------------------------------------------+\n");
    } else {
        printf("\t\t\t\t Tidak ada catatan.\n");
    }
}

// Fungsi untuk menampilkan isi catatan berdasarkan indeks
void displayNoteContent(Note notes[], int index) {
    clearScreen(); // Membersihkan layar terminal
    displayCatLogo();
    printf("\t\t\t\t Judul: %s\n", notes[index].title);
    printf("\t\t\t\t Isi:\n%s\n", notes[index].content);
}

int main() {
    Note notes[MAX_NOTES];
    int count = 0;
    char choice[10];

    // Loop untuk menu
    while (1) {
        printf("\t\t\t\t Menu:\n");
        printf("\t\t\t\t 1. Tampilkan Catatan\n");
        printf("\t\t\t\t 2. Tambah Catatan Baru\n");
        printf("\t\t\t\t 3. Cari Catatan\n");
        printf("\t\t\t\t 4. Keluar\n");
        printf("\t\t\t\t Pilih menu (1/2/3/4): ");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            displayBorderAndNotes(notes, count);
            if (count > 0) {
                printf("\t\t\t\t Pilih nomor catatan untuk melihat detail (atau 0 untuk kembali): ");
                int index;
                scanf("%d", &index);
                if (index > 0 && index <= count) {
                    displayNoteContent(notes, index - 1);
                }
            }
            sleep(2); // Tunggu 2 detik sebelum kembali ke menu
        } else if (strcmp(choice, "2") == 0) {
            displayInputNote(); // Menampilkan input judul dan isi catatan
            if (count < MAX_NOTES) {
                printf("\t\t\t\t Judul : ");
                scanf("%s", notes[count].title);
                printf("\t\t\t\t Isi (panjang maksimum 1000 karakter):\n");
                scanf(" %[^\n]", notes[count].content); // Membaca teks hingga akhir baris
                count++;
                printf("\t\t\t\t Catatan berhasil ditambahkan.\n");
            } else {
                printf("\t\t\t\t Batas maksimum catatan telah tercapai.\n");
            }
            sleep(2); // Tunggu 2 detik sebelum kembali ke menu
        } else if (strcmp(choice, "3") == 0) {
            char searchTitle[50];
            int found = 0;
            printf("\t\t\t\t Masukkan judul catatan yang ingin dicari: ");
            scanf("%s", searchTitle);
            for (int i = 0; i < count; i++) {
                if (strcmp(notes[i].title, searchTitle) == 0) {
                    displayNoteContent(notes, i);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                clearScreen(); // Membersihkan layar terminal
                animateCat();
            }
            sleep(2); // Tunggu 2 detik sebelum kembali ke menu
        } else if (strcmp(choice, "4") == 0) {
            printf("\t\t\t\t Program selesai.\n");
            break;
        } else {
            printf("\t\t\t\t Pilihan tidak valid.\n");
            sleep(2); // Tunggu 2 detik sebelum kembali ke menu
        }
    }
    return 0;
}

