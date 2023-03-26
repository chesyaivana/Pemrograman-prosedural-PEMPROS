#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mahasiswa{
    char NIM[10];
    char Nama[30];
    int usia;
};

struct mahasiswa createmahasiswa(char NIM[], char Nama[], int usia){
    struct mahasiswa mahasiswabaru;
    strcpy(mahasiswabaru.NIM, NIM);
    strcpy(mahasiswabaru.Nama, Nama);
    mahasiswabaru.usia= usia;

    return mahasiswabaru;
};

int main(){

    struct mahasiswa dachi;
    struct mahasiswa ivana;
    struct mahasiswa joshua;

    dachi=createmahasiswa("12S21052", "Griselda", 18);
    ivana=createmahasiswa("12S21053", "Chesya Ivana J. M Sitorus", 18);
    joshua=createmahasiswa("11319029", "Joshua Ryandafres Pangaribuan", 20);

    printf("NIM\t: %s\nNama\t: %s\nUsia\t: %d\n", dachi.NIM, dachi.Nama, dachi.usia);
    printf("NIM\t: %s\nNama\t: %s\nUsia\t: %d\n", ivana.NIM, ivana.Nama, ivana.usia);
    printf("NIM\t: %s\nNama\t: %s\nUsia\t: %d\n", joshua.NIM, joshua.Nama, joshua.usia);
}