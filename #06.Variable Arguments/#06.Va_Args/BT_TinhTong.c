#include<stdio.h>
#include<stdarg.h>

int tong(int num,...){
    double sum = 0.0;
    va_list va;
    va_start(va,num);
    double *prtD = (double *)&va;
    printf("Dia chi cua va: %p\n", va);
    for(int i = 0; i < num; i++)
    {
        
        printf("%p\n", va);
        printf("%f\n", va_arg(va,double));
        printf("Gia tri dia chi va: %f\n", (double *)va);
        printf("Gia tri con tro: %f tai dia chi %p\n", *prtD, prtD);
        prtD = prtD + 8;
        printf("\n");
    }
    va_end(va);
    return sum;
}

int main()
{
    printf("tong cac so: %d\n", tong(7, 5.0, 4.2, 4.9, 1, 3.0));
    return 0;
}