#include <stdio.h>

#define R1 2
#define C1 3
#define R2 3
#define C2 2

void multiplyMatrix(int m1[][C1], int m2[][C2])
{
    int result[R1][C2];

    printf("Resultant matrix is:\n");

    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < R2; k++)
            {
                result[i][j] += m1[i][k] * m2[k][j];
            }
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m1[R1][C1] = {{1, 2, 3}, {4, 5, 6}};
    int m2[R2][C2] = {{7, 8}, {9, 10}, {11, 12}};

    if (C1 != R2)
    {
        printf("Matrix multiplication not possible\n");
        return 0;
    }

    multiplyMatrix(m1, m2);

    return 0;
}
