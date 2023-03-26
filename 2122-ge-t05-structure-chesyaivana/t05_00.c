// 12S21053 _ Chesya Ivana J. M Sitorus
// 12S21025 - Noni Jelia Feby Sipayung

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum _grade
//enum adalah kumpulan nilai yang bersifat konstan. 
//Di enum, kita bisa memberikan nilai awaldari variable yang kita buat.
{
    GRADE_A,  // 0
    GRADE_AB, // 1
    GRADE_B,  // 2
    GRADE_C,  // 3
    GRADE_E   // 4
} Grade;

typedef struct _mhs
{
    char nama[30];
    char matkul[30];
    Grade gradeMatkul;
} Mahasiswa;

int main()
{
    Mahasiswa chesya;

    // Isi attribute
    strcpy(chesya.nama, "Chesya Ivana J. M Sitorus");
    strcpy(chesya.matkul, "Pemrograman Prosedural");
    chesya.gradeMatkul = GRADE_A;

    // Output
    printf("Nama\t: %s\nMatkul\t: %s\n", chesya.nama, chesya.matkul);

    // Check Grade
    switch (chesya.gradeMatkul)
    {
    case GRADE_A:
        printf("Nilai\t: Sangat Memuaskan");
        break;

    case GRADE_AB:
        printf("Nilai\t: Memuaskan");
        break;

    case GRADE_B:
        printf("Nilai\t: Baik");
        break;

    case GRADE_C:
        printf("Nilai\t: Cukup");
        break;

    case GRADE_E:
        printf("Nilai\t: Early Warning");
        break;
    }
}