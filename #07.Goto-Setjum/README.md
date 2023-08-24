# Lệnh Goto và Setjum
## GOTO
- Goto không có tính toán cục. Chỉ sử dụng được trong cục bộ một hàm.
- Cấu trúc bao gồm lệnh `goto label;` và vị trị chương trình muốn di chuyển đến `label: statement;`

**Ví Dụ:**
```c
#include <stdio.h>
  
int main () {
    int a = 10;
 
    TEST:do {
        if( a == 15) {
            // quay ve do khi a = 15 (bo qua lenh print)
            a = a + 1;
            goto TEST;
        }
        printf("Gia tri cua a: %d\n", a);
        a++;
    } while( a < 20 );
  
   return 0;
}
```

**Kết quả:**
```
Gia tri cua a: 10
Gia tri cua a: 11
Gia tri cua a: 12
Gia tri cua a: 13
Gia tri cua a: 14
Gia tri cua a: 16
Gia tri cua a: 17
Gia tri cua a: 18
Gia tri cua a: 19
```
---
## Setjum
- Sử dụng được toàn cục.
- Gọi thư viện `#include<setjmp.h>` để sử dụng.
- Khi gọi hàm: `longjmp()` con trỏ chương trình (PC) sẽ chạy đến: `setjmp()` và truyền giá trị được gán cho `setjmp()`.

**Ví Dụ:**
```c
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
```
Trong ví dụ trên giá trị `val = setjmp(butffer);` được gán có giá trị 0. Khi chương trình chạy đến lệnh `longjmp(butffer, 1);` Con trỏ chương trình sẽ quay lại tại ví trí hàm `setjmp(butffer)` và gán giá trị là 1 cho nó.

**Kết quả:**
```
Testpoint
val = 0
```