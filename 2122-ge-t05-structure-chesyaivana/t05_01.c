// 12S21053 - Chesya Ivana J. M Sitorus
// 12S21025 - Noni Jelia Feby Sipayung

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1

typedef enum _genders
{
    MALE,
    FEMALE
} Gender;

typedef struct _mahasiswa
{
    char Nama[30];
    char Nim[30];
    char Tahun[30];
    Gender Gender;
} Mahasiswa;

Mahasiswa createMahasiswa(
    char Nama[],
    char Nim[],
    char Tahun[],
    Gender Gender)
{
    Mahasiswa mahasiswaBaru;

    strcpy(mahasiswaBaru.Nama, Nama);
    strcpy(mahasiswaBaru.Nim, Nim);
    strcpy(mahasiswaBaru.Tahun, Tahun);
    mahasiswaBaru.Gender = Gender;

    return mahasiswaBaru;
}

int main()
{
    char registers[10];
    Mahasiswa mahasiswa[100];
    int FEMALE = 0;
    int MALE = 0;

    scanf("%s", registers);

    if (strcmp(registers, "---") != 0 && strcmp(registers, "register") == 0)
    {
        fflush(stdin);
        int pointer = 0;
        while (TRUE)
        {
            char input[40];
            char readBuffer[4][40];
            int pointerBuffer = 0;
            scanf("%s", input);

            if (strcmp(input, "---") == 0)
            {
                break;
            }

            char *token = strtok(input, "|");
            while (token != NULL)
            {
                strcpy(readBuffer[pointerBuffer++], token);
                token = strtok(NULL, "|");
            }

            if (strcmp(readBuffer[3], "MALE") == 0)
            {
                mahasiswa[pointer++] = createMahasiswa(readBuffer[0], readBuffer[1], readBuffer[2], MALE);
                MALE++;
            }
            else
            {
                mahasiswa[pointer++] = createMahasiswa(readBuffer[0], readBuffer[1], readBuffer[2], FEMALE);
                FEMALE++;
            }
            fflush(stdin);
        }
        printf("%d|%d\n", MALE, FEMALE);
    }
    else
    {
        printf("%d|%d\n", 0, 0);
    }

    return 0;
}