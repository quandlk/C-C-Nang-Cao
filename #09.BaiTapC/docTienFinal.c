#include<stdio.h>
#include<string.h>

unsigned char soHangLe[] = "000000000000"; //Truyen vao tung so don le

struct viTriChu
{
    char chuSo[11];
};
struct viTriChu chuSoLe[12];
struct viTriChu chuSoChucTram[12];


char soCanDem[] = "100001"; //1001001 20100001001 1000001 21001001 1021001001 10001 200010000000

void dienChu(unsigned char giaTriSo, char *giaTriChu, int dacBiet)
{
    switch (giaTriSo)
        {
        case 1:
            if(dacBiet == 1)
            {
                strcpy(giaTriChu, "Mot'");
            }
            else if (dacBiet == 10)
            {
                strcpy(giaTriChu, "Muoi`");
            }
            else // khong dac biet
            {
                strcpy(giaTriChu, "Mot");
            }
            
            break;
        case 2:
            strcpy(giaTriChu, "Hai");
            break;
        case 3:
            strcpy(giaTriChu, "Ba");
            break;
        case 4:
            strcpy(giaTriChu, "Bon");
            break;
        case 5:
            if(dacBiet==5)
            {
                strcpy(giaTriChu, "Lam");
            }
            else
            {
                strcpy(giaTriChu, "Nam");
            }
            break;
        case 6:
            strcpy(giaTriChu, "Sau");
            break;
        case 7:
            strcpy(giaTriChu, "Bay");
            break;
        case 8:
            strcpy(giaTriChu, "Tam");
            break;
        case 9:
            strcpy(giaTriChu, "Chin");
            break;
        case 0:
            if(dacBiet == 101)
            {
                strcpy(giaTriChu, "Le");
            }
            break;    
        default:
            break;
        }
}

void checkKT(int viTri)
{
    int checkKhong = 0;
    int checkKhongBf = 0;
    for(int j = viTri - 3; j < viTri; j++)
    {
        checkKhong = checkKhong + soHangLe[j];
    }
    for(int j = viTri; j < viTri + 3; j++)
    {
        checkKhongBf = checkKhongBf + soHangLe[j];
    }
    
    if(checkKhong >= 1  && checkKhongBf != 0)
    {
        strcpy(chuSoLe[viTri].chuSo, "Khong Tram");
    }
}

int main(int argc, char const *argv[])
{
    if(sizeof(soCanDem) > 13)
    {
        printf("Vuot qua gioi han 12 chu so.! \n");
        return 0;
    }

    int ThDacBiet = 0;
    int t = sizeof(soHangLe) - sizeof(soCanDem); // 5 Chenh lech 2 chuoi so can doc va khung so le
    int j = 0; 
    int k = 0; // Kiem soat bo 3 so hang tram, chuc, dvi
    printf("========================================================\n");
    for (int i = 0; i < 12; i++)
    {
        // Lam sach khung so
        soHangLe[i] = 0;
        soCanDem[i] = soCanDem[i] - 48;
        // Nap tung chu so vao hang soHangLe
        if (i>=t)
        {
            soHangLe[i] = (soCanDem[j]);
            j++;
        }
        else
        {
            soHangLe[i] = 0;
        }
        //printf("i = %d so Hang le %d \n",i,soHangLe[i] );

    }

    //printf("========================================================\n");
    int sum = 0;
    for (int i = 0; i < 12; i++)
    {
        char *prt = chuSoLe[i].chuSo;
        sum = sum + soHangLe[i]; // Xac dinh khong phai lai vi tri dau tien
        if(i == 0 || i == 3 || i == 6 || i == 9)
        {
            if(soHangLe[i] != 0)
            {
                dienChu(soHangLe[i],prt,ThDacBiet);
            }
            if(soHangLe[i] == 0) // TH dac biet
            {
                //if(soHangLe[i+1] !=0 && soHangLe[i-1] !=0)
                // Xu ly chi hien "Khong Tram" mot lan khong duoc lien ke nhau VD 1000001
                // Khong hien "Khong Tram" dau tien trong chuoi

                if(i == 3 || i == 6 || i == 9)
                {
                    checkKT(i);
                }

            }
        }
        if (i == 1 || i == 4 || i == 7 || i == 10)
        {
            if(soHangLe[i] != 0)
            {
                dienChu(soHangLe[i],prt,10); // TH dac biet Mot ->muoif
            }
            if(soHangLe[i] == 0 && soHangLe[i+1] !=0 && sum > 0) // TH dac biet
            {
                strcpy(chuSoLe[i].chuSo,"Le");
                //dienChu(soHangLe[i],prt,101); // TH DB "Le"
            }
        }
        if (i == 2 || i == 5 || i == 8 || i == 11)
        {
            if(soHangLe[i] != 0)
            {
                dienChu(soHangLe[i],prt,0);
                if(soHangLe[i-1]>1) // TH Dac biet cua 1
                {
                    dienChu(soHangLe[i],prt,1);
                }
                if(soHangLe[i] == 5 && soHangLe[i-1] != 0)// TH Dac biet cua 5
                {
                    dienChu(soHangLe[i],prt,5);
                }
            }
            if(soHangLe[i] == 0) // TH dac biet k
            {
     
            }
        }

        //printf("%d Chu hang le %s \n",i, chuSoLe[i].chuSo );

        // XU LY HANG TY, TRAM, TRIEU, NGAN..
        if((i==0||i==3||i==6||i==9) && soHangLe[i] != 0)
        {
            strcpy(chuSoChucTram[i].chuSo, "Tram");
        }
        if((i==1||i==4|i==7|i==10) && soHangLe[i] !=0 && soHangLe[i] !=1)
        {
            strcpy(chuSoChucTram[i].chuSo, "Muoi");
        }
        // TH i=2, 5, 8, 11
        if((soHangLe[i] + soHangLe[i-1] + soHangLe[i-2]) != 0)
        {
            if(i==2) 
            {
                strcpy(chuSoChucTram[i].chuSo, "Ty");
            }
            if(i==5)
            {
                strcpy(chuSoChucTram[i].chuSo, "Trieu");
            } 
            if(i==8)
            {
                strcpy(chuSoChucTram[i].chuSo, "Ngan"); 
            }
        }
        
        //printf("%d Chu hang chuc tram %s \n",i, chuSoChucTram[i].chuSo );
    }

    
    for (int i = 0; i < 12; i++)
    {
        char *ptrChuSoLe = chuSoLe[i].chuSo;
        char *ptrchuSoChucTram = chuSoChucTram[i].chuSo;

        if(*ptrChuSoLe != 0)
        {
            printf("%s ",chuSoLe[i].chuSo);
        }
        if(*ptrchuSoChucTram != 0)
        {
            printf("%s ",chuSoChucTram[i].chuSo);
        }
    }
    printf("Dong.\n");
    printf("========================================================\n");
    return 0;
}
