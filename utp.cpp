#include <iostream>
using namespace std;

#define MAX 10

struct node{
    string nama;
    node *next;
};

node *paling_bawah[MAX];
string lemari[MAX];
int banyak_lemari;
int indeks;
string inputString;

string DeteksiString(string s);

void Push();
void Pop();
void Display(int p);


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

    // for(int i = 0; i < banyak_lemari; i++) cout << i + 1 << ". " << lemari[i] << endl;

    do{
        cout << "\n1: Tambah\n2: Ambil\n3: Lihat\n4: Keluar\n";
        cout << "Pilihan Anda : ";
        cin >> pilihan;
        switch(pilihan){
        case 1: Push(); break;
        case 2:

            break;
        case 3:

            break;
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
    cout << "Masukkan nama pakaian : ";
    cin.ignore(); //karena sebelumnya kita sempat melakukan 'cin >>'
    getline(cin, inputString);

    node *baru = new node;
    baru->nama = DeteksiString(inputString);
    baru->next = NULL;

    node *temp;
    temp = paling_bawah[indeks];
    if(temp == NULL) paling_bawah[indeks] = baru;    
    else{
        while(temp->next != NULL) temp = temp->next;
        temp->next = baru;
    }
}

void Pop(){

}

void Display(int p){

}