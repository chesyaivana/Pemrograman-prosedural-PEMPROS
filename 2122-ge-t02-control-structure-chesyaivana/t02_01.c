// NIM - Name
// NIM - Name

#include <stdio.h>

int main()
{
    int quantity;
    float harga;
    float diskon;
    float total;

    scanf("%d", &quantity);
    scanf("%f", &harga);

    // Casting ke float
    total = (float)harga * quantity;

    // Pengecheckan total
    if (total > 50000 && total < 100000)
    {
        diskon = total * 0.05;
    }
    else if (total >= 100000 && total <= 500000)
    {
        diskon = total * 0.1;
    }
    else if (total > 500000)
    {
        diskon = total * 0.15;
    }
    else
    {
        diskon = 0;
    }

    // Pengecheckan diskon
    if (diskon == 0)
    {
        printf("---\n");
        printf("%.2f\n", total);
    }
    else
    {
        printf("%.2f\n", diskon);
        printf("%.2f\n", total - diskon);
    }

    return 0;
}