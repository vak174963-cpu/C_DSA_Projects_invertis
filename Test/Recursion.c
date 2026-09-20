#include <stdio.h>

int main()
{
    int matrix[3][3] = {
        {0, 0, 5},
        {0, 0, 0},
        {2, 0, 0}
    };

    int sparse[10][3];
    int i, j, k = 1;

    // First row: rows, columns, non-zero elements
    sparse[0][0] = 3;
    sparse[0][1] = 3;

    // Find non-zero elements
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(matrix[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    sparse[0][2] = k - 1;

    // Display 3-tuple representation
    printf("Row  Column  Value\n");

    for(i = 0; i < k; i++)
    {
        printf("%d     %d      %d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }

    return 0;
}

