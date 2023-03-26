#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa
{
    char NIM[255];
    char Nama[255];
    char GPA[255];
};

char *scan(char var[])
{
    char *words = (char *)malloc(sizeof(char) * 100);
    int pointers = 0;

    while (1)
    {
        char karakter = getchar();

        if (karakter != '\r' && karakter != '\n')
        {
            words[pointers] = karakter;
            words[++pointers] = '\0';
        }
        else
        {
            if (karakter == '\r')
            {
                continue;
            }

            if (karakter == '\n')
            {
                return (char *)words;
                break;
            }
        }
    }
}

struct Mahasiswa tambahMahasiswa(
    char nim[],
    char nama[],
    char GPA[])
{
    struct Mahasiswa mahasiswaBaru;

    strcpy(mahasiswaBaru.Nama, nama);
    strcpy(mahasiswaBaru.NIM, nim);
    strcpy(mahasiswaBaru.GPA, GPA);

    return mahasiswaBaru;
}

int main()
{
    struct Mahasiswa listMahasiswa[100];
    char *command;
    int batas = 0;
    int index = 0;
    int pointerMahasiswa = 0;

    while (1)
    {
        char tempVar[4][60];
        int attrIndex = 0;
        command = scan(command);

        if (strcmp(command, "---") == 0)
        {
            break;
        }
        else
        {
            if (strcmp(command, "student-show-all") == 0)
            {
                batas = pointerMahasiswa;
            }
            else
            {
                char *tokenize = strtok(command, "#");
                while (tokenize != NULL)
                {
                    if (strcmp(tokenize, "student-add") == 0)
                    {
                        tokenize = strtok(NULL, "#");
                    }
                    else
                    {
                        strcpy(tempVar[attrIndex++], tokenize);
                        tokenize = strtok(NULL, "#");
                    }
                }

                listMahasiswa[pointerMahasiswa++] = tambahMahasiswa(tempVar[0], tempVar[1], tempVar[2]);
            }
        }
        fflush(stdin);
    }

    for (int index = 0; index < batas; ++index)
    {
        printf("%s|%s|%s\n", listMahasiswa[index].NIM, listMahasiswa[index].Nama, listMahasiswa[index].GPA);
    }
}