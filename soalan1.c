#include <stdio.h>

int main() {
    float suhu[7];
    float jumlah = 0, purata;
    float maks, min;
    int hariMaks = 0;
    int i, hariKemaskini;
    float suhuBaru;

    // Input suhu bagi 7 hari berturut-turut
    printf("Masukkan suhu bagi 7 hari berturut-turut:\n");
    for (i = 0; i < 7; i++) {
        printf("Hari %d: ", i + 1);
        scanf("%f", &suhu[i]);
        jumlah += suhu[i];
    }

    // Kira purata, suhu tertinggi dan terendah
    purata = jumlah / 7;
    maks = min = suhu[0];

    for (i = 1; i < 7; i++) {
        if (suhu[i] > maks) {
            maks = suhu[i];
            hariMaks = i;
        }
        if (suhu[i] < min) {
            min = suhu[i];
        }
    }

    // Papar laporan suhu
    printf("\n=== LAPORAN SUHU HARIAN ===\n");
    printf("Purata suhu: %.2f°C\n", purata);
    printf("Suhu tertinggi: %.2f°C (Hari %d)\n", maks, hariMaks + 1);
    printf("Suhu terendah : %.2f°C\n", min);

    // Pilihan untuk kemaskini suhu
    printf("\nAdakah anda ingin kemaskini suhu untuk mana-mana hari? (1 = Ya, 0 = Tidak): ");
    int pilihan;
    scanf("%d", &pilihan);

    if (pilihan == 1) {
        printf("Masukkan nombor hari untuk dikemaskini (1-7): ");
        scanf("%d", &hariKemaskini);

        if (hariKemaskini >= 1 && hariKemaskini <= 7) {
            printf("Masukkan suhu baharu bagi Hari %d: ", hariKemaskini);
            scanf("%f", &suhuBaru);
            suhu[hariKemaskini - 1] = suhuBaru;

            printf("\nSenarai suhu selepas dikemaskini:\n");
            for (i = 0; i < 7; i++) {
                printf("Hari %d: %.2f°C\n", i + 1, suhu[i]);
            }
        } else {
            printf("Nombor hari tidak sah.\n");
        }
    }

    printf("\nAturcara tamat dengan jayanya.\n");
    return 0;
}
