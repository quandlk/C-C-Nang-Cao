#include<stdio.h>
#include<setjmp.h>
#include<stdlib.h>

int main(){
    int val;
    jmp_buf butffer;

    val = setjmp(butffer); // Gia tri setjum(butffer) ban dau la 0

    if(val !=0){
        printf("val = 0\n");
        exit(0);
    }

    // Nhay den ham setjmp(butffer) o dong 9. 
    // Va gan gia tri la 1 cho ham setjmp(butffer)
    printf("Testpoint \n");
    longjmp(butffer, 1);
    return 0;
}