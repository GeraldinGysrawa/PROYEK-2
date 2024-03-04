#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NOTES 100
#define MAX_LENGTH 1000

typedef struct {
    char title[50];
    char content[MAX_LENGTH];
} Note;

void clearScreen() {
    system("cls");
}

void displayCatLogo() {
    printf("\t\t\t\t\t  /\\_/\\ \n");
    printf("\t\t\t\t\t ( >.< )	   ><(((('>   \n");
    printf("\t\t\t\t\t  > ~ < 	^^^^^^^^^^^^\n");
}

void animateCat() {
    printf("\t\t\t\t\t\t\t   /\\_/\\\n");
    printf("\t\t\t\t\t\t\t  ( -.- )\n");
    printf("\t\t\t\t\t\t\t   > ^ < \n");
    printf("\n \t\t\t\t Kucing menyapa...");
    usleep(2000000);
    printf("\n \t\t\t\t Maaf catatan yang kamu cari tidak ada.\n");
}

void displayInputNote() {
    clearScreen();
    displayCatLogo();
    printf("\t\t\t\t +-----------------------------------------------+\n");
    printf("\t\t\t\t +           MASUKKAN JUDUL DAN ISI CATATAN       +\n");
    printf("\t\t\t\t +-----------------------------------------------+\n");
}

void displayBorderAndNotes(Note notes[]) {
    clearScreen();
    displayCatLogo();
    printf("\t\t\t\t +-----------------------------------------------+\n");
    printf("\t\t\t\t +	     SELAMAT DATANG DI MY MEMO		 +\n");	
    printf("\t\t\t\t +-----------------------------------------------+\n");
    printf("\n");

    int hasNotes = 0;
    int i; // pindahkan deklarasi i di sini
    for (i = 0; i < MAX_NOTES; i++) {
        if (notes[i].title[0] != '\0') {
            hasNotes = 1;
            break;
        }
    }

    if (hasNotes) {
        printf("\t\t\t\t +-----------------------------------------------+\n");
        printf("\t\t\t\t +              Daftar Catatan:               +\n");
        printf("\t\t\t\t +            	---------------                  +\n");
        for (i = 0; i < MAX_NOTES; i++) {
            if (notes[i].title[0] != '\0') {
                printf("\t\t\t\t + %-40s +\n", notes[i].title);
            }
        }
        printf("\t\t\t\t +-----------------------------------------------+\n");
    } else {
        printf("\t\t\t\t Tidak ada catatan.\n");
    }
}




void displayNoteContent(Note notes[], int index) {
    clearScreen();
    displayCatLogo();
    printf("\t\t\t\t Judul: %s\n", notes[index].title);
    printf("\t\t\t\t Isi:\n%s\n", notes[index].content);
}

// Fungsi untuk menyimpan catatan ke file
void saveNotesToFile(Note notes[]) {
    FILE *file = fopen("catatan.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk penyimpanan.\n");
        return;
    }

    int i;
    for (i = 0; i < MAX_NOTES; i++) {
        if (notes[i].title[0] != NULL) {
            fprintf(file, "%s\n%s\n", notes[i].title, notes[i].content);
        }
    }

    fclose(file);
}

// Fungsi untuk membaca catatan dari file
void loadNotesFromFile(Note notes[]) {
    FILE *file = fopen("catatan.txt", "r");
    if (file == NULL) {
        printf("Tidak ada catatan yang tersimpan.\n");
        return;
    }

    int i = 0;
    while (fscanf(file, "%[^\n]\n%[^\n]\n", notes[i].title, notes[i].content) == 2) {
        i++;
        if (i >= MAX_NOTES) {
            break;
        }
    }

    fclose(file);
}

int main() {
    Note notes[MAX_NOTES];
    loadNotesFromFile(notes); // Memuat catatan dari file saat program dimulai
    char choice[10];

    while (1) {
        printf("\t\t\t\t Menu:\n");
        printf("\t\t\t\t 1. Tampilkan Catatan\n");
        printf("\t\t\t\t 2. Tambah Catatan Baru\n");
        printf("\t\t\t\t 3. Cari Catatan\n");
        printf("\t\t\t\t 4. Keluar\n");
        printf("\t\t\t\t Pilih menu (1/2/3/4): ");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            displayBorderAndNotes(notes);
            sleep(2);
        } else if (strcmp(choice, "2") == 0) {
            displayInputNote();
            int i;
            for (i = 0; i < MAX_NOTES; i++) {
                if (notes[i].title[0] == '\0') {
                    printf("\t\t\t\t Judul : ");
                    scanf("%s", notes[i].title);
                    printf("\t\t\t\t Isi (panjang maksimum 1000 karakter):\n");
                    scanf(" %[^\n]", notes[i].content);
                    printf("\t\t\t\t Catatan berhasil ditambahkan.\n");
                    saveNotesToFile(notes); // Menyimpan catatan ke file setelah menambahkan catatan baru
                    break;
                }
            }
            if (i == MAX_NOTES) {
                printf("\t\t\t\t Batas maksimum catatan telah tercapai.\n");
            }
            sleep(2);
        } else if (strcmp(choice, "3") == 0) {
            char searchTitle[50];
            printf("\t\t\t\t Masukkan judul catatan yang ingin dicari: ");
            scanf("%s", searchTitle);
            int i;
            int found = 0;
            for (i = 0; i < MAX_NOTES; i++) {
                if (strcmp(notes[i].title, searchTitle) == 0) {
                    displayNoteContent(notes, i);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                clearScreen();
                animateCat();
            }
            sleep(2);
        } else if (strcmp(choice, "4") == 0) {
            printf("\t\t\t\t Program selesai.\n");
            break;
        } else {
            printf("\t\t\t\t Pilihan tidak valid.\n");
            sleep(2);
        }
    }
    return 0;
}

