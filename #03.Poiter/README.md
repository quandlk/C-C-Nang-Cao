# Con Trỏ

Giá trị con trỏ lưu là địa chỉ của một đối tượng (biến, hàm,..) khác. Con trỏ có thể tham chiếu *dán tiếp* đến địa chỉ mà nó đang trỏ đến.

**Khai báo một con trỏ (Declaring pointers**):
- Ví dụ khai báo một con trỏ kiểu `int`:
```
int *ptr;
```
- Khi muốn con trỏ quản lý một biến thì kiểu dữ liệu của con trỏ và kiểu biến phải trùng nhau.

**Gán giá trị cho con trỏ**
- Giá trị của con trỏ là một địa chỉ của một đối tượng. Ví dụ gán địa chỉ biến `a` cho con trỏ `ptr`. Ta dùng toán tử `&` - là toán tử lấy địa chỉ của một biến.
```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 330; // Khai báo biến a
    int *ptr; // Khai báo con trỏ ptr cùng kiểu dữ liệu với a
    ptr = &a; // lấy giá trị địa chỉ biến a gán cho ptr
    printf("Dia chi cua bien a: %d\n", &a);
    printf("Gia tri cua con tro ptr: %d", ptr);
    return 0;
}
```
Lưu ý: *Địa chỉ* của biến `a`; và *giá trị* của con trỏ `ptr`.

KQ:
```
Dia chi cua bien a: 327394
Gia tri cua con tro ptr: 327394
```

**Giải tham chiếu - Lấy giá trị của địa chỉ mà con trỏ đang quản lý**
-  Mục đích là lấy giá trị biến hay đối tương mà con trỏ đang trỏ đến. Ví dụ:
```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 330; // Khai báo biến a
    int *ptr; // Khai báo con trỏ ptr cùng kiểu dữ liệu với a
    ptr = &a; // lấy giá trị địa chỉ biến a gán cho ptr
    printf("Dia chi cua bien a: %d\n", &a);
    printf("Gia tri cua con tro ptr: %d\n", ptr);
    //
    printf("Gia tri cua bien a: %d\n", a);
    printf("Gia tri cua bien ma con tro ptr dang quan ly: %d", *ptr);

    *ptr = 1000; // => a = 1000
    return 0;
}
```