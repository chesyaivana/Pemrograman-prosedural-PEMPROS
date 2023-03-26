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
    char MALE_NAME[60][40];
    char FEMALE_NAME[60][40];

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
                strcpy(MALE_NAME[MALE++], readBuffer[0]);
            }
            else
            {
                mahasiswa[pointer++] = createMahasiswa(readBuffer[0], readBuffer[1], readBuffer[2], FEMALE);
                strcpy(FEMALE_NAME[FEMALE++], readBuffer[0]);
            }
            fflush(stdin);
        }
        printf("%d|%d\n", MALE, FEMALE);
        if(MALE != 0){
            for (int index = 0; index < MALE; ++index)
            {
                printf("%s|", MALE_NAME[index]);
            }
            printf("\n");
        }

        for (int index = 0; index < FEMALE; ++index)
        {
            printf("%s|", FEMALE_NAME[index]);
        }
        printf("\n");
    }
    else
    {
        printf("%d|%d\n", 0, 0);
    }

    return 0;
}
