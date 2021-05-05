#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
using namespace std;
static int p=0;

class o{
    char otobus_numarasi[20];
    char surucu[20];
    char varis_zamani[20];
    char kalkis_zamani[20];
    char kalkis_yeri[20];
    char varis_yeri[20];
    char koltuk[8][4][10];
public:
    void yukle();
    void tahsis();
    void bos();
    void goster();
    void mevcut();
    void durum(int i);
};

o otobus[10];

void isaret(char oluk){
    for(int i=80;i>0;i--){
        cout<<oluk;
    }
}

void o::yukle(){
    cout<<"Otobus Numarasini Giriniz: "<<endl;
    cin>>otobus[p].otobus_numarasi;
    cout<<"Surucunun Ismini Giriniz: "<<endl;
    cin>>otobus[p].surucu;
    cout<<"Varis Zamanini Giriniz: "<<endl;
    cin>>otobus[p].varis_zamani;
    cout<<"Kalkis Zamanini Giriniz: "<<endl;
    cin>>otobus[p].kalkis_zamani;
    cout<<"Kalkis Yerini Giriniz: "<<endl;
    cin>>otobus[p].kalkis_yeri;
    cout<<"Varis Yerini Giriniz: "<<endl;
    cin>>otobus[p].varis_yeri;

    otobus[p].bos();
    p++;
}

void o::tahsis(){
    int koltuk;
    char numara[5];

    ust:
        cout<<"Otobus Numarasini Giriniz: "<<endl;
        cin>>numara;

    int n;
    for(n=0;n<=p;n++){
        if(strcmp(otobus[n].otobus_numarasi,numara)==0){
            break;
        }
    }

    while(n<=p){
        cout<<"Koltuk Numarasini Giriniz: "<<endl;
        cin>>koltuk;

        if(koltuk>32){
            cout<<"Bu Otobuste Sadece 32 Koltuk Var."<<endl;
        }
        else{
            if(strcmp(otobus[n].koltuk[koltuk/4][(koltuk%4)-1],"Bos")==0){
                cout<<"Yolcunun Adini Giriniz: "<<endl;
                cin>>otobus[n].koltuk[koltuk/4][(koltuk%4)-1];
                break;
            }
            else{
                cout<<"Koltuk Numarasi Zaten Rezerve Edildi."<<endl;
            }
        }

        if(n>p){
            cout<<"Doðru Otobus Numarasini Giriniz: "<<endl;
            goto ust;
        }
    }
}

void o::bos(){
    for(int i=0;i<8;i++){
        for(int j=0;j<4;j++){
            strcpy(otobus[p].koltuk[i][j],"Bos");
        }
    }
}

void o::goster(){
    int n;
    char numara[5];
    cout<<"Otobus Numarasini Giriniz: "<<endl;
    cin>>numara;

    for(n=0;n<=p;n++){
        if(strcmp(otobus[n].otobus_numarasi,numara)==0){
            break;
        }
    }

    while(n<=p){
        isaret('*');
        cout<<"\nOtobus Numarasi: "<<otobus[n].otobus_numarasi<<endl;
        cout<<"Surucu: "<<otobus[n].surucu<<endl;
        cout<<"Varis Zamani: "<<otobus[n].varis_zamani<<endl;
        cout<<"Kalkis Zamani: "<<otobus[n].kalkis_zamani<<endl;
        cout<<"Kalkis Yeri: "<<otobus[n].kalkis_yeri<<endl;
        cout<<"Varis Yeri: "<<otobus[n].varis_yeri<<endl;
        isaret('*');
        otobus[0].durum(n);

        int a=1;
        for(int i=0;i<8;i++){
            for(int j=0;j<4;j++){
                a++;

                if(strcmp(otobus[n].koltuk[i][j],"Bos")!=0){
                    cout<<a-1<<" Numarali Koltuk"<<otobus[n].koltuk[i][j]<<" Adli Kisiye Rezerve Edildi."<<endl;
                }
            }
        }
        break;
    }

    if(n>p){
        cout<<"Dogru Otobus Numarasini Giriniz: "<<endl;
    }
}

void o::durum(int l){
    int s=0, p=0;

    for(int i=0;i<8;i++){
        cout<<"\n";
        for(int j=0;j<4;j++){
            s++;

            if(strcmp(otobus[l].koltuk[i][j],"Bos")==0){
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<otobus[l].koltuk[i][j];
                p++;
            }
            else{
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<otobus[l].koltuk[i][j];
            }
        }
    }
    cout<<endl;
    cout<<otobus[l].otobus_numarasi<<" Numarali Otobuste "<<p<<" Adet Koltuk Bos"<<endl;
}

void o::mevcut(){
    for(int n=0;n<p;n++){
        isaret('*');
        cout<<"Otobus Numarasi: "<<otobus[n].otobus_numarasi<<endl;
        cout<<"Surucu: "<<otobus[n].surucu<<endl;
        cout<<"Varis Zamani: "<<otobus[n].varis_zamani<<endl;
        cout<<"Kalkis Zamani: "<<otobus[n].kalkis_zamani<<endl;
        cout<<"Kalkis Yeri: "<<otobus[n].kalkis_yeri<<endl;
        cout<<"Varis Yeri: "<<otobus[n].kalkis_yeri<<endl;

        isaret('*');
        isaret('_');
    }
}

int main(){
    system("cls");
    int x;

    while(1){
        cout<<"1 -> Yukle"<<endl;
        cout<<"2 -> Rezervasyon"<<endl;
        cout<<"3 -> Goster"<<endl;
        cout<<"4 -> Mevcut Otobusler"<<endl;
        cout<<"5 -> Cikis"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"Tercihini Gir: "<<endl;
        cin>>x;

        switch(x){
        case 1:
            otobus[p].yukle();
            break;
        case 2:
            otobus[p].tahsis();
            break;
        case 3:
            otobus[p].goster();
            break;
        case 4:
            otobus[p].mevcut();
            break;
        case 5:
            exit(0);
        }
    }

    return 0;
}

