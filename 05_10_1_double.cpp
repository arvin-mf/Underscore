#include <iostream>
using namespace std;

struct nodeCDLL {
    int data;
    nodeCDLL *next;
    nodeCDLL *prev;
};

struct CircularDoubleLL{
    nodeCDLL *head, *tail;

    CircularDoubleLL(){
        head = NULL;
        tail = NULL;
    }
    void AddFirst(int data);
    void AddLast(int data);
    void DeleteData(int data);
    void Print(string komentar);
};

int main(){
    CircularDoubleLL *cdll = new CircularDoubleLL();
    
    cdll->AddLast(20);
    cdll->AddLast(270);
    cdll->AddFirst(48);
    cdll->Print("cek cek");
    cdll->DeleteData(20);
    cdll->Print("cek setelah delete delete");
    cdll->DeleteData(48);
    cdll->Print("cek setelah delete delete");
    cdll->DeleteData(270);
    cdll->Print("cek setelah delete delete");
    cdll->DeleteData(270);
    cdll->Print("cek setelah delete delete");


    return 0;
}


void CircularDoubleLL::AddFirst(int data){
    nodeCDLL *baru = new nodeCDLL();
    baru->data = data;
    if(head == NULL){
        head = tail = baru;
        baru->next = baru;
        baru->prev = baru;
    }else{
        baru->next = head;
        head->prev = baru;
        tail->next = baru;
        baru->prev = tail;
        head = baru;
    }
}

void CircularDoubleLL::AddLast(int data){
    nodeCDLL *baru = new nodeCDLL();
    baru->data = data;
    if(head == NULL){
        head = tail = baru;
        baru->next = baru;
        baru->prev = baru;
    }else{
        baru->next = head;
        head->prev = baru;
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void CircularDoubleLL::DeleteData(int data){
    bool ketemu = false;
    nodeCDLL *hapus;
    hapus = head;
    if(head != NULL){
        while(!ketemu){
            if(hapus->data == data) ketemu = true;
            else{
                if(hapus == tail) break;
                hapus = hapus->next;
            }
        }
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
    }else cout << "Data '" << data << "' tidak ada" << endl;
}

void CircularDoubleLL::Print(string komentar){
    cout << komentar << endl;
    nodeCDLL *cetak;
    cetak = head;
    if(head == NULL) cout << "List kosong!!" << endl;
    else{
        while(cetak != tail){
            cout << cetak->data << " -> ";
            cetak = cetak->next;
        }
        cout << cetak->data << endl;
    }
}