#include<stdio.h>
#include<setjmp.h>

int val;
jmp_buf buffer;

void test1(){
    int key = 0;
    do
    {
        printf("CT test1\n");
        printf("Nhan 1 quay lai\n");
        scanf("%d", &key);
    } while (key != 1);
    longjmp(buffer, 1);
}

void test2(){
    int key = 0;
    do
    {
        printf("CT test2\n");
        printf("Nhan 2 quay lai\n");
        scanf("%d", &key);
    } while (key != 2);
    longjmp(buffer, 2);
}

int main(){
    val = setjmp(buffer);
    int key = 0;
    do
    {
        printf("CT test1\n");
        printf("Nhan 1 de vao test1()\n");
        printf("Nhan 2 de vao test2()\n");
        scanf("%d", &key);
    } while (key != 1 && key != 2);
    longjmp(buffer, 1);

    switch (key)
    {
    case 1:
        key = 0;
        test1();
        break;
    case 2:
        key = 0;
        test2();
        break;
    default:
        break;
    }
}