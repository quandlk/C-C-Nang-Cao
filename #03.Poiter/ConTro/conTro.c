#include<stdio.h>

void tong(int a, int b){
    printf("Tong a va b: %d\n", a+b);
}

int main(){
    int i = 20;
    double d = 12.5;

    void *array[] = {&i, &d, &tong};
    printf("Double d %f\n", *(double *)array[1]);

    // Ep kieu du lieu ve con tro ham
    ((void (*)(int,int))array[2])(7,6); // Ep kieu con tro ham

    // Su dung con tro void
    void *conTroVoid; // Khai bao con tro void
    conTroVoid = array[2];
    ((void (*)(int,int))conTroVoid)(8,9); //Ep kieu con tro void ve con tro ham

    // Su dung con tro ham
    void (*conTro)(int, int); //Khai bao con tro ham
    conTro = array[2]; // Lay dia chi cho con tro
    conTro(9,10);

}