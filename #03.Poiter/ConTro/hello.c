#include<stdio.h>

void tong(int a, int b){
    printf("Tong a va b: %d\n", a+b);
}

int main(){
    int i = 20;
    double d = 12.5;

    void *array[] = {&i, &d, &tong};
    void (*conTro)(int, int);
    conTro = &tong;

    printf("Double d %f\n", *(double *)array[1]);
    ((void (*)(int,int))array[2])(7,6); // Ep kieu con tro
}