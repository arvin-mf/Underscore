#include <iostream>
using namespace std;

struct nodeCSLL {
    int data;
    nodeCSLL *next;
};

struct CircularSingleLL{
    nodeCSLL *head, *tail;
    int jumlah;

    CircularSingleLL(){
        head = NULL;
        tail = NULL;
        jumlah = -1;
    }

    void AddFirst(int data){
        nodeCSLL *baru = new nodeCSLL();
        baru->data = data;
        if(head == NULL){
            head = tail = baru;
            baru->next = baru;
            jumlah = 0;
        }else{
            baru->next = head;
            tail->next = baru;
            head = baru;
            jumlah++;
        }
    }

    void AddLast(int data){
        nodeCSLL *baru = new nodeCSLL();
        baru->data = data;
        if(head == NULL){
            head = tail = baru;
            baru->next = baru;
            jumlah = 0;
        }else{
            baru->next = head;
            tail->next = baru;
            tail = baru;
            jumlah++;
        }
    }

    void DeleteData(int data){
        bool ketemu = false;
        int i = 0;
        nodeCSLL *hapus, *sebelumnya;
        hapus = head;
        while(!ketemu && (i <= jumlah)){
            if(hapus->data == data) ketemu = true;
            else{
                sebelumnya = hapus;
                hapus = hapus->next;
            }
            i++;
        }
        if(ketemu){
            if(hapus == head){
                head = hapus->next;
                tail->next = head;
                delete hapus;
            }else{
                if(hapus == tail) tail = sebelumnya;
                sebelumnya->next = hapus->next;
                delete hapus;
            }
            jumlah--;
        }else cout << "Data '" << data << "' tidak ada" << endl;
    }

    void DeleteFirst(){
        if(head == NULL) cout << "Queue kosong" << endl;
        else{
            nodeCSLL *bantu;
            bantu = head;
            if(bantu == tail){
                delete bantu;
                head = tail = NULL;
                return;
            }
            head = head->next;
            tail->next = head;
            delete bantu;
            jumlah--;
        }
    }

    void DeleteLast(){
        if(head == NULL) cout << "Queue kosong" << endl;
        else{
            nodeCSLL *bantu;
            bantu = head;
            if(bantu == tail){
                delete bantu;
                head = tail = NULL;
                return;
            }
            while(bantu->next != tail) bantu = bantu->next;
            delete tail;
            tail = bantu;
            tail->next = head;
            jumlah--;
        }
    }

    void Print(string komentar){
        cout << komentar << endl;
        int i = -1;
        nodeCSLL *cetak;
        cetak = head;
        while(i < jumlah){
            cout << cetak->data << ((i == jumlah - 1) ? "" : " -> ");
            cetak = cetak->next;
            i++;
        }
        cout << endl;
    }
};

int main(){
    CircularSingleLL *csll = new CircularSingleLL();
    
    csll->AddLast(20);
    // csll->AddLast(270);
    // csll->AddFirst(48);
    csll->Print("cek cek");
    csll->DeleteData(20);
    csll->Print("cek setelah delete delete");


    return 0;
}