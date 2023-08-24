#include<stdio.h>

int main()
{
    int key = 0;
    top:
    do
    {
        printf("Chuong trinh test\n");
        printf("Case1: Noi dung 1\n");
        printf("Case2: Noi dung 2\n");
        scanf("%d", &key);
    } while (key!=1 && key !=2);
    
    switch (key)
    {
    case 1:
        printf("Chuong trinh 1\n");
        goto top;
        break;
    case 2:
        printf("Chuong trinh 2\n");
        goto top;
        break;
    
    default:
        break;
    }

    return 0;
}