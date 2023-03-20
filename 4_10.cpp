#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

struct Mahasiswa {
   //bagian data 
     string nim;
     string nama;
     double ipk;
   //pointer ke Mahasiswa selanjutnya
    struct Mahasiswa *next; 
    struct Mahasiswa *prev;
};
typedef struct Mahasiswa Mahasiswa;
Mahasiswa *head, *tail;

void PrintMahasiswaAscending () {
    Mahasiswa *pTemp;
    pTemp = head;
    int x = 1;
    cout << "======List Mahasiswa======" << endl;
    if (pTemp == NULL) cout << "       List Kosong\n" << endl;
    else {
        cout << endl;
        do{
            cout << "Data " << x << " : "  << endl;
            cout << "NIM    : " << pTemp->nim << endl;
            cout << "Nama   : " << pTemp->nama << endl;
            cout << "IPK    : " << pTemp->ipk << endl;
            cout << endl;
            pTemp = pTemp->next;
            x++;
        }while(pTemp != tail->next);
        cout << "Akhir list" << endl;
    }

}

void PrintMahasiswaDescending () {
    Mahasiswa *pTemp;
    pTemp = tail;
    int x = 1;
    cout << "===== List Mahasiswa =====" << endl;
    if (pTemp == NULL) cout << "       List Kosong\n" << endl;
    else {
        do {
            cout << "Data ke " << x << " : "  << endl;
            cout << "NIM    : " << pTemp->nim << endl;
            cout << "Nama   : " << pTemp->nama << endl;
            cout << "IPK    : " << pTemp->ipk << endl;
            cout << endl;
            pTemp = pTemp->prev;
            x++;
        }while(pTemp != head->prev);
        cout << "Akhir List" << endl;
    }
}

void AddMahasiswa () {
    Mahasiswa *pNew;
    pNew = new Mahasiswa;

    cout << "Masukkan data Mahasiswa: " << endl;
    cout << "NIM: ";
    cin >> pNew->nim;
    cout << "Nama: ";
    cin >> pNew->nama;
    cout << "IPK: ";
    cin >> pNew->ipk;
   
    if (head == NULL){
        head = tail = pNew;
    } else if (pNew->ipk == head->ipk && pNew->ipk == tail->ipk){
        tail->next = pNew;
        pNew->prev = tail;
        tail = pNew;
    } else if (pNew->ipk <= head->ipk) {
        pNew->next = head;
        head->prev = pNew;
        head = pNew;
    } else if (pNew->ipk >= tail->ipk) {
        tail->next = pNew;
        pNew->prev = tail;
        tail = pNew;
    } else  {
        Mahasiswa *temp1, *temp2, *temp3;
        temp1 = head;
        while (temp1->ipk < pNew->ipk) {
            temp2 = temp1;
            temp1 = temp1->next;

        }
        pNew->next = temp1;
        pNew->prev = temp2;
        temp2->next = pNew;
        temp1->prev = pNew;
        
    }
}

int main () {
    head = tail = NULL;
    int input;
    string nim, nama;
    double ipk;
    do {
        cout << "==========================\nPilih operasi:\n1.Add Mahasiswa\n2.Print Ascending\n3.Print Descending\nPilihan: ";
        cin >> input;
        switch (input) {
            case 1: 
            AddMahasiswa(); break;

            case 2:
            PrintMahasiswaAscending(); break;

            case 3:
            PrintMahasiswaDescending(); break;

            default : break;
        }

    } while (true);
}

