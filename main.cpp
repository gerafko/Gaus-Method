#include <stdio.h>
#include <conio.h>

const int N = 3; // кол-во уравнений
float matrix[N][N+1] = {{-4,  1, -2,-14},       //сама система
                 { 2,-14,  5, 11},
                 { 1,  1, -3,  0}};
float otvet[N] = {0};

void print_matrix()
{
    for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N+1 ; j++){
                printf("%.2f\t",matrix[i][j]);
            }
            printf("\n");
    }
}

int main()
{
    int i , j , k;
    float d;

    print_matrix();

    //////Прямой ход////////////////////////////
    for(i = 0 ; i < N-1 ; i++){
      for(j = i+1 ; j < N ; j++){
        d = (matrix[j][i]/matrix[i][i]);
        printf("S%i - (S%i * %.2f)\n", j+1, i+1, d);
        for(k = i; k < N+1 ; k++)
                matrix[j][k]-=(matrix[i][k]*d);
      }
      printf("\n");
      print_matrix();
    }
    printf("\n\n\n");

    ////Обратный ход//////////////////////////////
    otvet[N-1] = matrix[N-1][N-1] / matrix[N-1][N];
    for(i = N-2  ; i >= 0 ; i--){
        for(j = 0 , d = 0 ; j < N-i-1 ; j++)
            d+=(otvet[N-j-1]*matrix[i][N-j-1]*(-1));

        otvet[i] = (matrix[i][N]+d) / matrix[i][i];
    }

    /////Вывод корней/////////////////////////////
    for(i = 0 ; i < N ; i++)
        printf("X%i = %.2f\n", i+1, otvet[i]);

    getch();
}
