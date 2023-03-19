#include <iostream>
#include <conio.h>

using namespace std;

struct node {
    string nim;
    string nama;
    double ipk;
    struct node *next;
};
typedef struct node Mahasiswa;
Mahasiswa *head, *tail;

void PrintAll();
void AddByAdmin(string n, string a, double ip);
void AddByUser();

int main(){
    head = tail = NULL;

    PrintAll();

    AddByAdmin("001", "Rasyid", 3.56);
    AddByAdmin("002", "Regas", 3.89);
    AddByUser();
    AddByUser();

    PrintAll();

    getch();    
    return EXIT_SUCCESS;
}

void PrintAll(){
    Mahasiswa *pTemp;
    pTemp = head;
    cout << endl << "---- Print List ----" << endl;
    if(pTemp == NULL) cout << "List kosong" << endl;
    else{
        cout << endl;
        do{
            cout << "Data :" << endl;
            cout << "NIM    : " << pTemp->nim << endl;
            cout << "Nama   : " << pTemp->nama << endl;
            cout << "IPK    : " << pTemp->ipk << endl;
            pTemp = pTemp->next;
        }while(pTemp != tail->next);
        cout << "Akhir list" << endl;
    }
}

void AddByAdmin(string n, string a, double ip){
    Mahasiswa *baru;
    baru = (Mahasiswa *) malloc(sizeof(Mahasiswa));
    baru->nim = n;
    baru->nama = a;
    baru->ipk = ip;
    if(head == NULL){
        head = tail = baru;
    }else if(baru->ipk == head->ipk && head->ipk == tail->ipk){
        tail->next = baru;
        tail = baru;
    }else{
        if(baru->ipk > head->ipk){
            baru->next = head;
            head = baru;
        }else if(baru->ipk < tail->ipk){
            tail->next = baru;
            tail = baru;
        }else{
            Mahasiswa *temp1, *temp2;
            temp1 = head;
            while(temp1->ipk >= baru->ipk){
                temp2 = temp1;
                temp1 = temp1->next;
            }
            baru->next = temp1;
            temp2->next = baru;
        }
    }
}

void AddByUser(){
    Mahasiswa *baru;
    baru = (Mahasiswa *) malloc(sizeof(Mahasiswa));
    string n, a;
    double ip;
    cout << endl << "Masukkan data" << endl;
    cout << "NIM  : ";
    cin >> n;
    cout << "Nama : ";
    cin >> a;
    cout << "IPK  : ";
    cin >> ip;
    baru->nim = n;
    baru->nama = a;
    baru->ipk = ip;
    if(head == NULL){
        head = tail = baru;
    }else if(baru->ipk == head->ipk && head->ipk == tail->ipk){
        tail->next = baru;
        tail = baru;
    }else{
        if(baru->ipk > head->ipk){
            baru->next = head;
            head = baru;
        }else if(baru->ipk < tail->ipk){
            tail->next = baru;
            tail = baru;
        }else{
            Mahasiswa *temp1, *temp2;
            temp1 = head;
            while(temp1->ipk >= baru->ipk){
                temp2 = temp1;
                temp1 = temp1->next;
            }
            baru->next = temp1;
            temp2->next = baru;
        }
    }
}