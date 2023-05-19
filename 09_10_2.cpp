#include <iostream>
using namespace std;

#define MAX 4

struct Pegawai{
    int nip;
    string nama;
};

int pilih = 0;
Pegawai Data[MAX];

void TukarPosisi(Pegawai *, Pegawai *);
void CetakArray();
void UrutByNIP();
void UrutByNama();
void Opsi();


int main(){
    int input_nip;
    string input_nama;

    cout << "Masukkan data pegawai!" << endl;
    for(int i = 0; i < MAX; i++){
        cout << i + 1 << ". NIP : ";
        cin >> input_nip;
        cout << "  Nama : ";
        cin >> input_nama;
        Data[i].nip = input_nip;
        Data[i].nama = input_nama;
    }

    do{
        cout << endl;
        cout << "1. Urutkan data pegawai berdasarkan NIP" << endl;
        cout << "2. Urutkan data pegawai berdasarkan Nama" << endl;
        cout << "3. Tampilkan data pegawai\n4. Keluar\nPilihan : ";
        cin >> pilih;

        switch(pilih){
            case 1 :
                UrutByNIP();
                cout << "Data sudah diurutkan (v)" << endl;
                break;
            case 2 :
                UrutByNama();
                cout << "Data sudah diurutkan (v)" << endl;
                break;
            case 3 : CetakArray(); break;
            case 4 : cout << endl << "-- Menutup Program --" << endl; break;
            default : cout << "(!) Pilih bil. bulat 1 sampai 4 (!)" << endl;
        } 
    }while(pilih != 4);

    return 0;
}


void CetakArray(){
    cout << endl << "-- DATA PEGAWAI --" << endl;
    for(int i = 0; i < MAX; i++){
        cout << i + 1 << ". NIP : " << Data[i].nip << endl;
        cout << "  Nama : " << Data[i].nama << endl;
    }
}

void UrutByNIP(){
    do Opsi(); while(pilih != 1 && pilih != 2);

    int i, j, k;
    for(i = 0; i < MAX - 1; i++){
        k = i;
        for(j = i + 1; j < MAX; j++){
            if(pilih == 1) if(Data[k].nip > Data[j].nip) k = j;
            if(pilih == 2) if(Data[k].nip < Data[j].nip) k = j;
        }
        TukarPosisi(&Data[i], &Data[k]);
    }
}

void UrutByNama(){
    do Opsi(); while(pilih != 1 && pilih != 2);

    int i, j, k;
    for(i = 0; i < MAX - 1; i++){
        k = i;
        for(j = i + 1; j < MAX; j++){
            int ii = 0;
            while(Data[k].nama[ii] == Data[j].nama[ii]) ii++;
            if(pilih == 1) if(Data[k].nama[ii] > Data[j].nama[ii]) k = j;
            if(pilih == 2) if(Data[k].nama[ii] < Data[j].nama[ii]) k = j;
        }
        TukarPosisi(&Data[i], &Data[k]);
    }
}

void Opsi(){
    cout << "1. Ascending\n2. Descending" << endl;
    cout << "Pilihan : ";
    cin >> pilih;
}

void TukarPosisi(Pegawai *a, Pegawai *b){
    Pegawai bantu = *a;
    *a = *b;
    *b = bantu;
}