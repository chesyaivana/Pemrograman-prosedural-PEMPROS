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

        // Save nilai angka ke variabel nilaiJarak[bnykLoop]
        nilaiJarak[i] = angka;
    }

    for (int i = 0; i < bnykLoop - 1; i++)
    {
        int jarakSekarang = nilaiJarak[i] - nilaiJarak[i + 1];

        // Jarak selalu positif
        if (jarakSekarang < 0)
        {
            // Tetap Positif
            jarakSekarang = jarakSekarang * -1;
        }

        // Check jarak terjauh
        if (jarakSekarang > jarak)
        {
            jarak = jarakSekarang;
        }
    }

    printf("%d\n%d\n%.2f\n%d\n", min, max, ((float)total / (float)bnykLoop), jarak);
  return 0;
}
