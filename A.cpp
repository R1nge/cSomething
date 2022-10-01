#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float a[3][2];
//Не нужно указывать Прототип т.к функция указана до main
//int length(int q, int r)

int length(int q, int r)
{
    //Возвращаешь int, так что нет смысла создавать переменную
    return sqrt((pow((a[q][1] - a[r][1]), 2) + pow((a[q][2] - a[r][2]), 2) + pow((a[q][3] - a[r][3]), 2)));
}

bool isTriangle()
{
    bool A = length(1, 2) > length(2, 3) + length(3, 1); 
    bool B = length(3, 1) > length(1, 2) + length(2, 3);
    bool C = length(1, 2) > length(3, 1) + length(2, 3);
    
    bool a = (A > 0 && B > 0 && C > 0);
    bool b =  A == (B + C);
    bool c = B == (A +C);
    bool d = C == (A + B);
    
    return (a && b ||c || d);
}

int main()
{
    //Держи все переменные в минимальном scope
    //https://www.geeksforgeeks.org/scope-of-variables-in-c/
    //Получаю размер массива, вместо хард кода, так не надо ничего менять при изменении размера массива, к тому же производительность не важна
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) 
    {
        printf("Enter coordinates of point ");

        if (i == 0) { printf("A \n"); } 
        else if (i == 1) { printf("B \n"); } 
        else if (i == 2) { printf("C \n"); }

        for (int j = 0; j < sizeof(a[0])/sizeof(a[0][0]); j++) 
        {
            if(j == 0) { printf("X \n"); }
            else if (j == 1) { printf("Y \n"); }
            scanf("%f", &a[i][j]); // & возвращает значение из памяти, без него изменяется поинтер
        }
    }
    //Какая та проблема в матешей, зачем тебе 3д координаты, треугольник же 2д
    if (isTriangle) 
    {
        float p = length(1, 2) + length(2, 3) + length(3, 1);
        float temp = 
        (a[0][0] - a[2][0])
        * (a[1][1] - a[2][1]) - 
        (a[1][0] - a[2][0]) 
        * (a[0][1] - a[2][1]);
        
        float S = abs(temp) / 2;

        printf("result %f", S);
    } 
    else 
    {
        printf("Not");
    }
}
