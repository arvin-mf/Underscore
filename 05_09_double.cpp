#include <iostream>
using namespace std;

struct nodeCDLL {
    int data;
    nodeCDLL *next;
    nodeCDLL *prev;
};

struct CircularDoubleLL{
    nodeCDLL *head, *tail;
    int jumlah;

    CircularDoubleLL(){
        head = NULL;
        tail = NULL;
        jumlah = -1;
    }

    void AddFirst(int data){
        nodeCDLL *baru = new nodeCDLL();
        baru->data = data;
        if(head == NULL){
            head = tail = baru;
            baru->next = baru;
            baru->prev = baru;
            jumlah = 0;
        }else{
            baru->next = head;
            head->prev = baru;
            tail->next = baru;
            baru->prev = tail;
            head = baru;
            jumlah++;
        }
    }

    void AddLast(int data){
        nodeCDLL *baru = new nodeCDLL();
        baru->data = data;
        if(head == NULL){
            head = tail = baru;
            baru->next = baru;
            baru->prev = baru;
            jumlah = 0;
        }else{
            baru->next = head;
            head->prev = baru;
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
            jumlah++;
        }
    }

    void DeleteData(int data){
        bool ketemu = false;
        int i = 0;
        nodeCDLL *hapus;
        hapus = head;
        while(!ketemu && (i <= jumlah)){
            if(hapus->data == data) ketemu = true;
            else hapus = hapus->next;
            i++;
        }
        if(ketemu){
            if(hapus == head){
                if(hapus == tail){
                    delete hapus;
                    head = tail = NULL;
                    return;
                }
                head = hapus->next;
            }
            if(hapus == tail) tail = hapus->prev;
            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;
            delete hapus;
            jumlah--;
        }else cout << "Data '" << data << "' tidak ada" << endl;
    }

    void Print(string komentar){
        cout << komentar << endl;
        int i = -1;
        nodeCDLL *cetak;
        cetak = head;
        if(head == NULL) cout << "Queue kosong!!" << endl;
        else{
            while(i < jumlah){
                cout << cetak->data << ((i == jumlah - 1) ? "" : " -> ");
                cetak = cetak->next;
                i++;
            }
            cout << endl;
        }
    }
};

int main(){
    CircularDoubleLL *cdll = new CircularDoubleLL();
    
    cdll->AddLast(20);
    cdll->AddLast(270);
    cdll->AddFirst(48);
    cdll->Print("cek cek");
    cdll->DeleteData(48);
    cdll->Print("cek setelah delete delete");


    return 0;
}