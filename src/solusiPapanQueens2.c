#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int baris;
    int kolom;
} Posisi;

Posisi buatPosisi(int baris, int kolom) {
    Posisi posisi;
    posisi.baris = baris;
    posisi.kolom = kolom;
    return posisi; 
}

typedef struct {
    Posisi posisiSekarang;
    int nextAlphabet;
} Alphabet;

char matriks[600][600];
Alphabet alphaList[26];
int currentAlphabetIndex = -1;
int firstAlphabetIndex = -1;

void buatAlphaList(Alphabet *alphabet) {
    for (int i = 0; i < 26; i++) {
        alphabet[i].posisiSekarang.baris = -1;
        alphabet[i].posisiSekarang.kolom = -1;
        alphabet[i].nextAlphabet = -1;
    }
}

int dapatBanyakAlphabet() {
    int banyakAlphabet = 0;
    for (int i = 0; i < 26; i++) {
        if (alphaList[i].nextAlphabet != -1) {
            banyakAlphabet++;
        }
    }
    return banyakAlphabet;
}

void displayMatriks(int jumlahBaris, int jumlahKolom) {
    for (int i = 0; i < jumlahBaris; i++) {
        for (int j = 0; j < jumlahKolom; j++) {
            printf("%c ", matriks[i][j]);
        }
        printf("\n");
    }
}

int panjangBarisValiddanSimpan(char *baris, int panjangBaris, int indeksBaris) {
    int panjangBarisTemp = 0; 
    int iAlpha = 0;
    for (int i = 0; i < panjangBaris; i++) {
        char karakter = baris[i];
        int karakterInt = (int) baris[i];
        if (karakterInt >= 65 && karakterInt <= 90 /* huruf besar */) {
            panjangBarisTemp++;
        } else if (karakterInt == 32 /* spasi */ || karakterInt == 13 /* enter */) {
            continue;
        } else {
            panjangBarisTemp = -1;
            break;
        }
        matriks[indeksBaris][iAlpha] = karakter;
        iAlpha++;
        int indeksAlphabet = karakterInt - 65;
        if (alphaList[indeksAlphabet].nextAlphabet == -1) {
            if (firstAlphabetIndex == -1) {
                firstAlphabetIndex = indeksAlphabet;
                currentAlphabetIndex = firstAlphabetIndex;
                alphaList[indeksAlphabet].nextAlphabet = firstAlphabetIndex;
            } else {
                alphaList[currentAlphabetIndex].nextAlphabet = indeksAlphabet;
                currentAlphabetIndex = indeksAlphabet;
                alphaList[indeksAlphabet].nextAlphabet = firstAlphabetIndex;
            }
        }
    }
    return panjangBarisTemp;
}

bool apkhPosisiDekat(Posisi posisi1, Posisi posisi2) {
    if (abs(posisi1.baris - posisi2.baris) <= 1 && abs(posisi1.kolom - posisi2.kolom) <= 1) {
        return true;
    }
    return false;
}

bool apkhPosisiValid(Posisi posisi) {
    int i = firstAlphabetIndex;
    bool selesai = false;
    
    while(!selesai) {
        if (alphaList[i].posisiSekarang.baris != -1 && alphaList[i].posisiSekarang.kolom != -1) {
            if (alphaList[i].posisiSekarang.baris == posisi.baris || 
                alphaList[i].posisiSekarang.kolom == posisi.kolom || 
                apkhPosisiDekat(alphaList[i].posisiSekarang, posisi)) {
                    return false;
            }
        }
        i = alphaList[i].nextAlphabet;
        if (i == firstAlphabetIndex) {
            selesai = true;
        }
    }
    return true;
}

bool cariPosisiSelanjutnya(int dimensi) {
    int startBaris, startKolom;
    int currIdx = currentAlphabetIndex;
    char charTujuan = (char) (currIdx + 65);

    if (alphaList[currIdx].posisiSekarang.baris == -1) {
        startBaris = 0;
        startKolom = 0;
    } else {
        int barisSekarangTemp = alphaList[currIdx].posisiSekarang.baris;
        int kolomSekarangTemp = alphaList[currIdx].posisiSekarang.kolom;
        matriks[barisSekarangTemp][kolomSekarangTemp] = charTujuan; 
        startBaris = barisSekarangTemp;
        startKolom = kolomSekarangTemp + 1;
        alphaList[currIdx].posisiSekarang = buatPosisi(-1, -1);
    }

    for (int i = startBaris; i < dimensi; i++) {
        int starBaris2 = (i == startBaris) ? startKolom : 0;
        for (int j = starBaris2; j < dimensi; j++) {
            if (matriks[i][j] == charTujuan) {
                Posisi cekPosisi = buatPosisi(i, j);
                if (apkhPosisiValid(cekPosisi)) {
                    alphaList[currIdx].posisiSekarang = cekPosisi;
                    matriks[i][j] = charTujuan + 32;
                    return true;
                }
            }
        }
    }
    return false;
}

int findAlphabetBefore(int indeksAlphabet) {
    int i = firstAlphabetIndex;
    bool selesai = false;
    while (!selesai) {
        if (alphaList[i].nextAlphabet == indeksAlphabet) {
            return i;
        }
        i = alphaList[i].nextAlphabet;
        if (i == firstAlphabetIndex) {
            selesai = true;
        }
    }
    return -1;
}

int main() {
    FILE *fptr;
    char namaFile[1000];
    printf("%s", "Selamat datang di program Solusi Papan Queens!\n");
    printf("%s", "Masukkan nama file: ");
    fgets(namaFile, sizeof(namaFile), stdin);
    size_t len = strlen(namaFile);
    if (len > 0 && namaFile[len-1] == '\n') {
        namaFile[len-1] = '\0';
    }

    printf("\nMembuka file...\n");
    fptr = fopen(namaFile, "r");
    if (fptr == NULL) {
        char namaFileTxt[1005];
        strcpy(namaFileTxt, namaFile);
        strcat(namaFileTxt, ".txt");
        fptr = fopen(namaFileTxt, "r");
        if (fptr == NULL) {
            printf("File tidak ditemukan!\n");
            return 1;
        }
    }
    printf("File berhasil dibuka\n");
    printf("\nMembaca file...\n");
    int jumlahKolom = 0;
    int jumlahBaris = 0;
    char barisKarakter[600];
    buatAlphaList(alphaList);
    firstAlphabetIndex = -1;
    currentAlphabetIndex = -1;
    
    while (fgets(barisKarakter, sizeof(barisKarakter), fptr) != NULL) {
        int panjangBarisAsliTemp = strlen(barisKarakter);
        if (panjangBarisAsliTemp > 0 && barisKarakter[panjangBarisAsliTemp-1] == '\n') {
            barisKarakter[panjangBarisAsliTemp-1] = '\0';
        }
        int panjangBarisValidTemp = panjangBarisValiddanSimpan(barisKarakter, strlen(barisKarakter), jumlahBaris);
        if (panjangBarisValidTemp == 0) {
            continue;
        }
        jumlahBaris++;
        if (panjangBarisValidTemp != -1 && jumlahBaris == 1) {
            jumlahKolom = panjangBarisValidTemp;
        }
        if (jumlahBaris > jumlahKolom) {
            printf("Kesalahan: dimensi papan tidak persegi\n");
            fclose(fptr); return 1;
        }
        if (panjangBarisValidTemp == -1) {
            printf("Kesalahan: ditemukan karakter tidak valid pada baris %d papan\n", jumlahBaris);
            fclose(fptr); return 1;
        }   
        if (panjangBarisValidTemp != jumlahKolom) {
            printf("Kesalahan: baris %d papan tidak konsisten\n", jumlahBaris);
            fclose(fptr); return 1;
        }
    }
    
    int totalAlfabet = dapatBanyakAlphabet();
    printf("Dimensi: %d x %d\nJumlah warna: %d\n", jumlahBaris, jumlahKolom, totalAlfabet);
    if (jumlahBaris != jumlahKolom) {
        printf("Kesalahan: dimensi papan tidak persegi\n");
        fclose(fptr); return 1;
    }
    if (totalAlfabet != jumlahBaris) {
        printf("Kesalahan: jumlah warna (huruf) tidak sama dengan dimensi papan\n");
        fclose(fptr); return 1;
    }
    if (jumlahBaris == 0) {
        printf("File kosong\n");
        fclose(fptr); return 1;
    }
    
    printf("\nPapan awal:\n");
    displayMatriks(jumlahBaris, jumlahKolom);
    
    printf("\nMencari solusi...\n");
    currentAlphabetIndex = firstAlphabetIndex;
    bool selesai = false;
    bool isSolved = false;
    int i = 1;
    int iterasi = 0;
    clock_t waktuMulai = clock();
    while (!selesai) {
        iterasi++;
        if (currentAlphabetIndex == firstAlphabetIndex) {
            printf("Pencarian ke-%d (dari warna awal)\n", i);
            i++;
        }
        bool isFound = cariPosisiSelanjutnya(jumlahBaris);
        
        if (isFound) {
            if (alphaList[currentAlphabetIndex].nextAlphabet == firstAlphabetIndex) {
                isSolved = true;
                selesai = true;
            } else {
                currentAlphabetIndex = alphaList[currentAlphabetIndex].nextAlphabet;
            }
        } else {
            alphaList[currentAlphabetIndex].posisiSekarang = buatPosisi(-1, -1);
            
            if (currentAlphabetIndex == firstAlphabetIndex) {
                selesai = true;
            } else {
                currentAlphabetIndex = findAlphabetBefore(currentAlphabetIndex);
            }
        }
    }
    clock_t waktuSelesai = clock();
    double waktuPencarian = ((double)(waktuSelesai - waktuMulai) / CLOCKS_PER_SEC) * 1000.0;
    
    printf("Pencarian solusi selesai\n");
    printf("Waktu pencarian: %.2f ms\n", waktuPencarian);
    printf("Jumlah iterasi: %d\n", iterasi);
    if (isSolved) {
        printf("\nSolusi ditemukan (Huruf kecil adalah Ratu):\n");
        displayMatriks(jumlahBaris, jumlahKolom);
    } else {
        printf("Tidak ditemukan solusi\n");
    }
    
    fclose(fptr);
    return 0;
}