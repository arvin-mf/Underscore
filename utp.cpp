#include <iostream>
using namespace std;

#define MAX 10

struct node{
    string nama;
    node *next;
};

node *paling_bawah[MAX];
string lemari[MAX];
int banyak_lemari = 0;

int DeteksiJenis(string s);

void Push(string s);
void Pop();
void Display();


int main(){
    cout << "Masing-masing lemari berisi pakaian dengan jenis yang sama" << endl;
    do{
        cout << "Banyak lemari (banyak jenis) : " << endl;
        cin >> banyak_lemari;
        if(banyak_lemari > 10) cout << "(!) interval ==> bil. bulat 1 - 10" << endl;
    }while(banyak_lemari > 10);

    for(int i = 0; i < banyak_lemari; i++){
        cout << "Nama jenis ke-" << i + 1 << " : ";
        cin >> lemari[i];
    }



    return 0;
}


int DeteksiJenis(string s){
    int indeks, cekpoin = 0;
    string jenis, nama;
    for(int i = 0; i < s.length(); i++){
        if(cekpoin > 0) nama += s[i];
        if(s[i] == ' ') cekpoin++;
        if(cekpoin == 0){
            jenis += s[i];
            for(int j = 0; j < banyak_lemari; j++){
                if(jenis == lemari[j]){
                    indeks = j;
                    break;
                }
            }
        }
    }
    return indeks;
}

void Push(string s){
    node *baru = new node;
    baru->nama = s;
    baru->next = NULL;
    int jenis = DeteksiJenis(s);
    node *temp;
    temp = paling_bawah[jenis];
    if(temp == NULL){
        
    }else{

    }
}

void Pop(){

}

void Display(){

}