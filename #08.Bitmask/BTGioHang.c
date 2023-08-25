#include<stdio.h>
#include<stdint.h>

int GIO_HANG = 0;

typedef enum
{
    AO        = 1 << 0,
    QUAN      = 1 << 1,
    VAY       = 1 << 2,
    DAM       = 1 << 3,
    NHAN      = 1 << 4,
    VONG_TAY  = 1 << 5,
    GIAY      = 1 << 6,
    TUI       = 1 << 7,
}DO_DUNG_CA_NHAN;
//Gio hang: 0110 0010
//AND
//AO:       0000 0001
//KQ:       0000 0000
void Show_Item()
{
    printf("Danh sach san pham duoc chon: \n");
    if(GIO_HANG & AO) printf("AO\n");
    if(GIO_HANG & QUAN) printf("QUAN\n");
    if(GIO_HANG & VAY) printf("VAY\n");
    if(GIO_HANG & DAM) printf("DAM\n");
    if(GIO_HANG & NHAN) printf("NHAN\n");
    if(GIO_HANG & VONG_TAY) printf("VONG_TAY\n");
    if(GIO_HANG & GIAY) printf("GIAY\n");
    if(GIO_HANG & TUI) printf("TUI\n");
}


void Check_Items(int Items)
{
    printf("Kiem tra san pham: \n");
    
    //Gio hang:    0110 0010
    //so bat ky AND voi 0 thi bang 0
    //Items:       0000 1111  <=== Mon hang can check
    //KQ:          0000 0010

    // Kiem tra xem co phai items can check khong?
    if(Items & AO) 
    {
        // Kiem tra mon hang can check co trong gio hang ko
        if(GIO_HANG & AO) printf("AO da co\n");
        else printf("AO chua co\n");
    }
    // Vien cho gon lai
    if(Items & QUAN){ if(GIO_HANG & QUAN) printf("QUAN da co\n"); else printf("QUAN chua co\n"); }
    if(Items & VAY){ if(GIO_HANG & VAY) printf("VAY da co\n"); else printf("VAY chua co\n"); }
    if(Items & DAM){ if(GIO_HANG & DAM) printf("DAM da co\n"); else printf("DAM chua co\n"); }
    if(Items & NHAN){ if(GIO_HANG & NHAN) printf("NHAN da co\n"); else printf("NHAN chua co\n"); }
    if(Items & VONG_TAY){ if(GIO_HANG & VONG_TAY) printf("VONG_TAY da co\n"); else printf("VONG_TAY chua co\n"); }
    if(Items & GIAY){ if(GIO_HANG & GIAY) printf("GIAY da co\n"); else printf("GIAY chua co\n"); }
    if(Items & TUI){ if(GIO_HANG & TUI) printf("TUI da co\n"); else printf("TUI chua co\n"); }
}

int main()
{
    //Them vao gio hang
    GIO_HANG |= QUAN;
    GIO_HANG |= NHAN;
    GIO_HANG |= GIAY;

    //Xoa khoi gio hang
    GIO_HANG &= ~GIAY;

    //Kiem tra item GIAY trong gio hang
    //if(GIO_HANG & GIAY) printf("co GIAY\n");
    //else printf("Khong co\n");

    Show_Item();

    Check_Items(AO|QUAN|VAY);

    return 0;
}