# Đối số biến thiên (Variable Arguments)
## Mục đích sử dụng
- Sử dụng trong trường hợp khi tạo một hàm nhưng không biết có bao nhiêu tham số sẽ được truyền vào.
- Để sử dụng cần sử dụng thư viện: `#include <stdarg.h>`
## Syntax
- Để khai báo ta sử dụng cấu trúc `data_type function_name(data_type variable_name, ...);` trong đó `...` đại diện cho số lượng các tham số không xác định được truyền vào:
```c
#include <stdio.h>
#include <stdarg.h>

double tong(int num, ...)
{
    va_list va; // Biến truy từng phần từ trong danh sách
    va_start(va, num); // Khợi tạo biết va_list là một danh sách đối số. Với số lượng đối số là biến num
    .
    .
    .
    va_end(va_list); // Thu hồi vùng nhớ được gán cho biến va_list
}
```