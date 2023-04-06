#include <iostream>
using namespace std;

#define MAX 10

struct node{
    string nama;
    node *next;
};

node *paling_bawah[MAX];
string lemari[MAX];
int indeks, banyak_lemari = 0;

string DeteksiString(string s);

void Push();
void Pop();
void Display();


int main(){
    int pilihan;

    cout << "Masing-masing lemari berisi pakaian dengan jenis yang sama" << endl;
    do{
        cout << "Banyak lemari (banyak jenis) : ";
        cin >> banyak_lemari;
        if(banyak_lemari > 10) cout << "(!) interval ==> bil. bulat 1 - 10 (!)" << endl;
    }while(banyak_lemari > 10);

    for(int i = 0; i < banyak_lemari; i++){
        cout << "Nama jenis ke-" << i + 1 << " : ";
        cin >> lemari[i];
    }

    do{
        cout << endl << "--------------------------" << endl;
        cout << "1: Tambah\n2: Ambil\n3: Lihat\n4: Keluar\n";
        cout << "Pilihan Anda : ";
        cin >> pilihan;
        switch(pilihan){
        case 1: Push();     break;
        case 2: Pop();      break;
        case 3: Display();  break;
        case 4:
            cout << "Keluar, menutup program" << endl;
            break;
        default: cout << "(!) Pilih antara 1 sampai 4! (!)" << endl;
        }
    }while(pilihan != 4);

    return 0;
}

string DeteksiString(string s){
    int cekpoin = 0;
    string jenis, nama;
    for(int i = 0; i < s.length(); i++){
        if(cekpoin > 0) nama += s[i];
        if(s[i] == ' ') cekpoin++;
        if(cekpoin == 0){
            jenis += s[i];
            for(int j = 0; j < banyak_lemari; j++){
                if(jenis == lemari[j]) indeks = j;
            }
        }
    }
    return nama;
}

void Push(){
    string input;
    cout << "Masukkan nama pakaian : ";
    cin.ignore(); //karena sebelumnya kita sempat melakukan 'cin >>'
    getline(cin, input);

    node *baru = new node;
    baru->nama = DeteksiString(input);
    baru->next = NULL;

    node *temp;
    temp = paling_bawah[indeks];
    if(temp == NULL) paling_bawah[indeks] = baru;    
    else{
        bool cek = false;
        if(temp->nama == baru->nama) cek = true;
        while(temp->next != NULL){
            temp = temp->next;
            if(temp->nama == baru->nama) cek = true;
        }
        if(!cek) temp->next = baru;
        else{
            delete baru;
            cout << "Nama pakaian sudah ada sebelumnya ;)" << endl;
        }
    }
}

void Pop(){
    if(banyak_lemari == 0) cout << "Tidak ada lemari" << endl;
    else{
        int i, pilih;
        cout << "Pilih lemari untuk mengambil" << endl;
        for(i = 0; i < banyak_lemari; i++)
            cout << i + 1 << ": " << lemari[i] << endl;
        cout << "Pilihan : ";
        cin >> pilih;

        node *temp, *tahan;
        temp = paling_bawah[pilih - 1];
        if(temp == NULL) cout << "Lemari " << lemari[pilih - 1] << " kosong" << endl;
        else if(temp->next == NULL){
            cout << lemari[pilih - 1] << " " << temp->nama << " diambil" << endl;
            delete temp;
            paling_bawah[pilih - 1] = NULL;
        }else{
            while(temp->next != NULL){
                tahan = temp;
                temp = temp->next;
            }
            cout << lemari[pilih - 1] << " " << temp->nama << " diambil" << endl;
            delete temp;
            tahan->next = NULL;
            if(tahan == paling_bawah[pilih - 1]) paling_bawah[pilih - 1] = tahan;
        }
        cout << "Baiklah" << endl;
    }
}

void Display(){
    if(banyak_lemari != 0){
        int i, pilih;
        cout << "Pilih lemari untuk ditampilkan" << endl;
        for(i = 0; i < banyak_lemari; i++)
            cout << i + 1 << ": " << lemari[i] << endl;
        cout << i + 1 << ": Semua lemari" << endl;
        cout << "Pilihan : ";
        cin >> pilih;
        cout << "v v v v v v v v v" << endl;

        if(pilih == i + 1){
            for(int k = 0; k < banyak_lemari; k++){
                node *temp;
                temp = paling_bawah[k];
                cout << endl;
                if(temp == NULL) cout << "Lemari " << lemari[k] << " kosong" << endl;
                else{
                    int q = 0;
                    cout << "Lemari " << lemari[k] << endl;
                    while(temp != NULL){
                        cout << "-> " << temp->nama << endl;
                        q++;
                        temp = temp->next;
                    }
                    cout << "Total pakaian = " << q << endl;
                }
            }
        }else{
            node *temp;
            temp = paling_bawah[pilih - 1];
            if(temp == NULL) cout << "Lemari " << lemari[pilih - 1] << " kosong" << endl;
            else{
                int q = 0;
                cout << "Lemari " << lemari[pilih - 1] << endl;
                while(temp != NULL){
                    cout << "-> " << temp->nama << endl;
                    q++;
                    temp = temp->next;
                }
                cout << "Total pakaian = " << q << endl;
            }
        }
        cout << endl << "Baiklah" << endl;
    }
}