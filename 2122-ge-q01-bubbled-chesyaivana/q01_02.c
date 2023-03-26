// 12S21053 - Chesya Ivana J. M Sitorus

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(char arr[])
{
    int n = strlen(arr);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    // Declare variabel
    char inputWords[100];
    int index = 0;

    // Proses input data / kata ke inputWords[100]
    while (1)
    {
        // Function getchar() untuk mengambil input per karakter
        char ch = getchar();

        // Jika input karakter bukan '\r' dan '\n'
        if (ch != '\r' && ch != '\n')
        {
            // Maka masukkan karakter ke inputWords[index]
            inputWords[index] = ch;
            // dan increment index untuk tempat \0
            inputWords[++index] = '\0';
        }
        else
        {

            // Jika pointer tidak berada di awal maka lanjutkan
            // untuk mengambil input dari user.
            if (ch == '\r')
            {
                continue;
            }

            // Jika user menekan enter maka input selesai
            if (ch == '\n')
            {
                break;
            }
        }
    }

    // Cara menghilangkan delimiter koma
    /*
        1. Memecah inputWords menjadi array of character menggunakan strtok()
           Syntax strtok() :
                strtok(variabel_input, delimiter)

                cth :
                strtok(inputWords,",")

        2. Hasil pemecahan disimpan kedalam array of character yang baru
    */

    // Array yang baru untuk menyimpan hasil pecahan array of character
    char lines[255];
    index = 0;
    char *pecahan = strtok(inputWords, ",");
    while (pecahan != NULL)
    {
        lines[index] = pecahan[0];
        lines[++index] = '\0';
        pecahan = strtok(NULL, ",");
    }

    bubbleSort(lines);

    for (int i = 0; i < strlen(lines); ++i)
    {
        if (i == strlen(lines) - 1)
        {
            printf("%c", lines[i]);
            break;
        }
        else
        {
            printf("%c,", lines[i]);
        }
    }
}