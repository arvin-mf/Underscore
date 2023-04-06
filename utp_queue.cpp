#include <iostream>
using namespace std;

struct node{
    string nama;
    string posisi;
    node *next;
};

node *depan, *penghuni;
string posisi[6] = {"Menteri", "Jendral", "Komandan", "Prajurit", "Medis", "Sipil"};
int n_total = 0, n_masuk = 0;
string input;

string DeteksiNama(string s);
string DeteksiPosisi(string s);

void Tambah();
void Masuk();
void Antrean();
void Eren();


int main(){
    int pilih;

    cout << endl << "-- Kekaisaran Eldia Forever --" << endl;

    do{
        cout << "\n1: Tambah\n2: Masuk\n3: Antrean\n4: Eren" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilih;
        switch(pilih){
            case 1: Tambah(); break;
            case 2: Masuk(); break;
            case 3: Antrean(); break;
            case 4:
                Eren();
                cout << endl;
                break;
            default:
                cout << "(!) bil. bulat interval 1 - 4 (!)" << endl;
        }

    }while(pilih != 4);


    return 0;
}


string DeteksiNama(string s){
    string nama;
    int i = 0;
    while(s[i] != ' '){
        nama += s[i];
        i++;
    }
    return nama;
}

string DeteksiPosisi(string s){
    string posisi;
    int cek = 0;
    for(int i = 0; i < s.length(); i++){
        if(cek > 0) posisi += s[i];
        if(s[i] == ' ') cek++;
    }
    return posisi;
}

void Tambah(){

}

void Masuk(){

}

void Antrean(){

}

void Eren(){

}