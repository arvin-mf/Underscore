#include <iostream>
using namespace std;

struct nodeCSLL {
    int data;
    nodeCSLL *next;
};

struct CircularSingleLL{
    nodeCSLL *head, *tail;

    CircularSingleLL(){
        head = NULL;
        tail = NULL;
    }
    void AddFirst(int data);
    void AddLast(int data);
    void DeleteData(int data);
    void DeleteFirst();
    void DeleteLast();
    void Print(string komentar);
};

int main(){
    CircularSingleLL *csll = new CircularSingleLL();
    
    csll->AddLast(20);
    csll->AddLast(270);
    csll->AddFirst(48);
    csll->Print("cek cek");
    csll->DeleteData(48);
    csll->Print("cek setelah delete delete");
    csll->DeleteData(270);
    csll->Print("cek setelah delete delete");
    csll->DeleteData(20);
    csll->Print("cek setelah delete delete");
    csll->DeleteData(20);
    csll->Print("cek setelah delete delete");


    return 0;
}


void CircularSingleLL::AddFirst(int data){
    nodeCSLL *baru = new nodeCSLL();
    baru->data = data;
    if(head == NULL){
        head = tail = baru;
        baru->next = baru;
    }else{
        baru->next = head;
        tail->next = baru;
        head = baru;
    }
}

void CircularSingleLL::AddLast(int data){
    nodeCSLL *baru = new nodeCSLL();
    baru->data = data;
    if(head == NULL){
        head = tail = baru;
        baru->next = baru;
    }else{
        baru->next = head;
        tail->next = baru;
        tail = baru;
    }
}

void CircularSingleLL::DeleteData(int data){
    bool ketemu = false;
    nodeCSLL *hapus, *sebelumnya;
    hapus = head;
    if(head != NULL){
        while(!ketemu){
            if(hapus->data == data) ketemu = true;
            else{
                if(hapus == tail) break;
                sebelumnya = hapus;
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
            tail->next = head;
            delete hapus;
        }else{
            if(hapus == tail) tail = sebelumnya;
            sebelumnya->next = hapus->next;
            delete hapus;
        }
    }else cout << "Data '" << data << "' tidak ada" << endl;
}

void CircularSingleLL::DeleteFirst(){
    if(head == NULL) cout << "List kosong" << endl;
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
    }
}

void CircularSingleLL::DeleteLast(){
    if(head == NULL) cout << "List kosong" << endl;
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
    }
}

void CircularSingleLL::Print(string komentar){
    cout << komentar << endl;
    nodeCSLL *cetak;
    cetak = head;
    if(cetak == NULL) cout << "List kosong!!" << endl;
    else{
        while(cetak != tail){
            cout << cetak->data << " -> ";
            cetak = cetak->next;
        }
        cout << cetak->data << endl;
    }
}