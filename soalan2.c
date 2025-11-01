#include <stdio.h>
#include <string.h>

// Takrif struktur pelajar
struct Pelajar {
    char id[10];
    char nama[50];
    float markah;
};

int main() {
    struct Pelajar pelajar[5];
    int i;
    float markahTertinggi = 0;
    int indeksTertinggi = 0;
    char cariID[10];
    int jumpa = 0;

    // Input maklumat pelajar
    printf("Masukkan maklumat bagi 5 orang pelajar:\n");
    for (i = 0; i < 5; i++) {
        printf("\nPelajar %d\n", i + 1);
        printf("Masukkan ID Pelajar: ");
        scanf("%s", pelajar[i].id);
        printf("Masukkan Nama Pelajar: ");
        scanf(" %[^\n]", pelajar[i].nama);
        printf("Masukkan Markah: ");
        scanf("%f", &pelajar[i].markah);
    }

    // Papar semua rekod pelajar
    printf("\n=====================================================\n");
    printf("| %-5s | %-25s | %-7s |\n", "ID", "Nama", "Markah");
    printf("=====================================================\n");
    for (i = 0; i < 5; i++) {
        printf("| %-5s | %-25s | %7.2f |\n", pelajar[i].id, pelajar[i].nama, pelajar[i].markah);
    }
    printf("=====================================================\n");

    // Cari pelajar dengan markah tertinggi
    markahTertinggi = pelajar[0].markah;
    for (i = 1; i < 5; i++) {
        if (pelajar[i].markah > markahTertinggi) {
            markahTertinggi = pelajar[i].markah;
            indeksTertinggi = i;
        }
    }

    printf("\nPelajar dengan markah tertinggi:\n");
    printf("ID: %s\n", pelajar[indeksTertinggi].id);
    printf("Nama: %s\n", pelajar[indeksTertinggi].nama);
    printf("Markah: %.2f\n", pelajar[indeksTertinggi].markah);

    // Cari pelajar berdasarkan ID
    printf("\nMasukkan ID pelajar untuk dicari: ");
    scanf("%s", cariID);

    for (i = 0; i < 5; i++) {
        if (strcmp(pelajar[i].id, cariID) == 0) {
            jumpa = 1;
            printf("\nPelajar dijumpai!\n");
            printf("ID: %s\n", pelajar[i].id);
            printf("Nama: %s\n", pelajar[i].nama);
            printf("Markah: %.2f\n", pelajar[i].markah);
            break;
        }
    }

    if (!jumpa) {
        printf("\nPelajar dengan ID %s tidak dijumpai.\n", cariID);
    }

    printf("\nAturcara tamat dengan jayanya.\n");
    return 0;
}

