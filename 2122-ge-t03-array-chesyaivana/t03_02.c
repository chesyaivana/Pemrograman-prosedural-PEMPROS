// NIM - Name
// NIM - Name

#include <stdio.h>

int main(int _argc, char **_argv)
{
     // Menentukan banyak nya program akan diulang
    int bnykLoop = 0;
    // Variabel yang menyimpan angka dari user (-100 s/d 100)
    short angka = 0;
    // Variabel untuk menyimpan nilai max dan min yg menjadi output
    int max = 0;
    int min = 0;

    // Nilai rata"
    int total = 0;

    // Input banyaknya looping
    scanf("%d", &bnykLoop);

    // Jarak terjauh
    int nilaiJarak[bnykLoop];
    int jarak = 0;

    // Looping untuk mengulang program
    for (int i = 0; i < bnykLoop; i++)
    {
        // Input angka dari user
        scanf("%hd", &angka);

        // Check min
        if (angka < min)
        {
            min = angka;
        }

        // Check max
        if (angka > max)
        {
            max = angka;
        }

        // Save angka dari user ke variabel total
        total = angka + total;

    }

    printf("%d\n%d\n%.2f\n", min, max, ((float)total / (float)bnykLoop));
    
return 0;
}

  
