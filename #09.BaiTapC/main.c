#include <stdio.h>

void inHoaSauDauCham(char *text) {
    int vietHoa = 1;

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            vietHoa = 1;
        } else if (vietHoa && text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] - 'a' + 'A';
            vietHoa = 0;
        }
    }
}

int timDoanVan(const char *text, const char *canTim) {
    while (*text) {
        const char *p1 = text;
        const char *p2 = canTim;

        while (*p1 && *p2 && *p1 == *p2) {
            p1++;
            p2++;
        }

        if (!*p2) {
            return 1; // Tìm thấy canTim trong text
        }

        text++;
    }

    return 0; // Không tìm thấy canTim trong text
}

void thayDoanVan(char *text, const char *oldSubstr, const char *newSubstr) {
    char result[1000]; // Một mảng kết quả tạm thời
    int resultIndex = 0;
    int i = 0;

    while (text[i]) {
        int j = 0;
        while (text[i + j] == oldSubstr[j]) {
            j++;
            if (oldSubstr[j] == '\0') {
                // Tìm thấy oldSubstr trong text
                for (int k = 0; newSubstr[k]; k++) {
                    result[resultIndex++] = newSubstr[k];
                }
                i += j;
            }
        }

        result[resultIndex++] = text[i++];
    }

    result[resultIndex] = '\0';

    // Sao chép kết quả từ result vào text
    for (i = 0; result[i]; i++) {
        text[i] = result[i];
    }
    text[i] = '\0';
}

int main() {
    char word[] = "At the same time. there is a need to increase sustainability? step up circular economy and strongly digitize administrative processes. and improve environment protection.";
    
    // 1. Sau dau '.' '?' '!' viết In Hoa
    inHoaSauDauCham(word);
    printf("1. Sau dau '.' viet Hoa: %s\n", word);
    
    // 2. Tìm kiếm đoạn văn bản
    const char *searchText = "hoc lap trinh C";
    if (timDoanVan(word, searchText)) {
        printf("2. Tim kiem chuoi '%s' -> co\n", searchText);
    } else {
        printf("2. Tim kiem chuoi '%s' -> khong co\n", searchText);
    }
    
    // 3. Tìm và thay thế
    const char *oldText = "increase sustainability";
    const char *newText = "hello world";
    thayDoanVan(word, oldText, newText);
    printf("3. Tim va thay the: %s\n", word);
    
    return 0;
}