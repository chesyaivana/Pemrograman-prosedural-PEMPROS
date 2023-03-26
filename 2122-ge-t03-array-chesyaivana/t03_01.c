// NIM - Name
// NIM - Name

#include <stdio.h>

int main(int _argc, char **_argv)
{
    int array = 0;
    scanf("%d", &array);

    int banyak[array];
    int minimun, maximum;

    minimun = maximum = 0;
    
    for (int a = 0; a < array; ++a)
    {
        scanf("%d", &banyak[a]);

        if (minimun > banyak[a])
        {
            minimun = banyak[a];
        }

        if (maximum < banyak[a])
        {
            maximum = banyak[a];
        }
    }
    printf("\n%d", minimun);
    printf("\n%d", maximum);
    return 0;
}
