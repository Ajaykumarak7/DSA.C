#include <stdio.h>
#define N 4

// Function to transpose a matrix
void transpose(int mat[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            mat[i][j] = mat[i][j] + mat[j][i] - (mat[j][i] = mat[i][j]);
}
void reverseRow(int mat[N][N], int row)
{
    int start = 0;
    int end = N - 1;

    while (start < end)
    {
        mat[row][start] = mat[row][start] + mat[row][end] - (mat[row][end] = mat[row][start]);
        start++;
        end--;
    }
}
void rotateClockwise(int mat[N][N])
{
    transpose(mat);
    for (int i = 0; i < N; i++)
        reverseRow(mat, i);
}
void rotateAntiClockwise(int mat[N][N])
{
    transpose(mat);
    for (int i = 0; i < N; i++)
        reverseRow(mat, i);
}
void display(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);

        printf("\n");
    }
}
int main()
{
    int mat[N][N] =
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13,14,15,16,17}};
    printf("Original matrix:\n");
    display(mat);
    rotateClockwise(mat);
    printf("\nRotated matrix by 90 degrees clockwise:\n");
    display(mat);
    rotateClockwise(mat);
    printf("\nRotated matrix by another 90 degrees clockwise:\n");
    display(mat);
    rotateClockwise(mat);
    printf("\nRotated matrix by another 90 degrees clockwise:\n");
    display(mat);
    rotateClockwise(mat);
    printf("\nRotated matrix by another 90 degrees clockwise:\n");
    display(mat);

    return 0;
}
