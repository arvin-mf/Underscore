#include <iostream>
using namespace std;

struct node {
     char data;
    struct node *next; 
    struct node *prev;
};
typedef struct node node;
node *head, *tail;

void AddLast(char c);               // Penambahan
void AddFirst(char c);              // Penambahan
void AddToIndex(int index, char c); // Penambahan
void AddAfter(char checkpt, char insert);   //Penyisipan
void AddBefore(char checkpt, char insert);  //Penyisipan
void DeleteLast();                  // Penghapusan
void DeleteFirst();                 // Penghapusan
void DeleteByIndex(int index);      // Penghapusan
void DeleteByData(char trash);      // Penghapusan
void DeleteAfter(char checkpt);     // Penghapusan
void DeleteBefore(char checkpt);    // Penghapusan
void DeleteAll();                   // Penghapusan
void FindDataByIndex(int index);    // Pencarian
void FindIndexByData(char cari);    // Pencarian
node * FindNodeByIndex(int index);  // Pencarian        
void PrintAll();                    // Pengaksesan
void ReversePrintAll();             // Pengaksesan
void PrintFromIndex(int index);     // Pengaksesan
void PrintFromData(char mulai);     // Pengaksesan

void NotFound(char c){
    cout << "Data '" << c << "' tidak ada" << endl;
}

int main(){
    head = tail = NULL;
    
    AddLast('T'), 
    AddFirst('Q'), AddLast('A'), AddFirst('D'),
    AddAfter('A', 'U'), AddBefore('U', 'R'), AddToIndex(6, 'M'),
    PrintAll();
    // DeleteLast(), DeleteFirst(), 
    // DeleteByIndex(4), DeleteByData('U'),
    // DeleteAfter('M'), DeleteBefore('B'),
    // DeleteAll(), 
    // FindDataByIndex(3),
    // FindIndexByData('R');

    // PrintAll();
    // ReversePrintAll();
    // PrintFromIndex(7);
    // PrintFromData('Q');

    // cout << endl << FindNodeByIndex(7)->data << endl;
    
    return EXIT_SUCCESS;
}

void AddLast(char c){
    struct node *baru;
    baru = (node *) malloc(sizeof(node));
    baru->data = c;

    if(head == NULL) head = baru;
    else{
        tail->next = baru;
        baru->prev = tail;
    }
    tail = baru;
}

void AddFirst(char c){
    struct node *baru;
    baru = (node *) malloc(sizeof(node));
    baru->data = c;

    if(head == NULL) tail = baru;
    else{
        baru->next = head;
        head->prev = baru;
    }
    head = baru;
}

void AddToIndex(int index, char c){
    if(index < 0){
        cout << "Indeks merupakan bilangan cacah!" << endl;
        return;
    }
    struct node *baru;
    baru = (node *) malloc(sizeof(node));
    baru->data = c;

    struct node *temp1, *temp2;
    temp1 = head;
    if(index == 0) AddFirst(c);
    else{
        int i = 0;
        while(i != index){
            i++;
            if(temp1 == tail){
                if(index == i) AddLast(c);
                else cout << "Indeks AddToIndex melebihi supply" << endl;
                return;
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = temp1->prev = baru;
        baru->prev = temp2;
        baru->next = temp1;
    }
}

void AddAfter(char checkpt, char insert){
    node *baru;
    baru = (node *) malloc(sizeof(node));
    baru->data = insert;

    node *temp1, *temp2;
    temp1 = head;
    if(temp1 == NULL) NotFound(checkpt);
    else{
        do{
            if(temp1 == tail){
                if(temp1->data == checkpt){
                    AddLast(insert);
                    return;
                }else if(temp2->data != checkpt){
                    NotFound(checkpt);
                    return;
                }
                break;
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }while(temp2->data != checkpt);
        temp2->next = baru;
        temp1->prev = baru;
        baru->next = temp1;
        baru->prev = temp2;
    }
}

void AddBefore(char checkpt, char insert){
    node *baru;
    baru = (node *) malloc(sizeof(node));
    baru->data = insert;

    node *temp1, *temp2;
    temp1 = head;
    if(temp1 == NULL) cout << "Data '" << checkpt << "' tidak ada" << endl;
    else if(temp1->data == checkpt) AddFirst(insert);
    else{
        do{
            temp2 = temp1;
            temp1 = temp1->next;
            if(temp1 == tail){
                if(temp1->data != checkpt){
                    cout << "Data '" << checkpt << "' tidak ada" << endl;
                    return;
                }
                break;
            }
        }while(temp1->data != checkpt);
        temp2->next = baru;
        temp1->prev = baru;
        baru->next = temp1;
        baru->prev = temp2;
    }
}

void DeleteLast(){
    node *temp;
    temp = head;
    if(temp == NULL) cout << "List kosong!!" << endl;
    else{
        if(temp != tail){
            while(temp != tail) temp = temp->next;
            tail = temp->prev;
            free(temp);
        }else DeleteAll();
    }
}

void DeleteFirst(){
    node *temp;
    temp = head;
    if(temp == NULL) cout << "List kosong!!" << endl;
    else{
        if(temp != tail){
            head = head->next;
            free(temp);
        }else DeleteAll();
    }
}

void DeleteByIndex(int index){
    if(index < 0){
        cout << "Indeks merupakan bilangan cacah!" << endl;
        return;
    }
    node *temp1, *temp2;
    temp1 = head;
    int i = 0;
    if(temp1 == NULL) cout << "List kosong!!" << endl;
    else if(index == 0) DeleteFirst();
    else{
        while(i != index){
            i++;
            temp2 = temp1;
            temp1 = temp1->next;
            if(temp1 == tail){
                if(i == index){
                    DeleteLast();
                    return;
                }
                break;
            }
        }
        if(index > i){
            cout << "Indeks DeleteByIndex melebihi supply" << endl;
            return;
        }
        temp2->next = temp1->next;
        temp1->next->prev = temp2;
        free(temp1);
    }
}

void DeleteByData(char trash){
    node *temp1, *temp2;
    temp1 = head;
    if(temp1 == NULL) cout << "List kosong!!" << endl;
    else if(temp1->data == trash) DeleteFirst();
    else{
        while(temp1->data != trash){
            if(temp1 == tail) break;
            temp2 = temp1;
            temp1 = temp1->next;
        }
        if(temp1 == tail){
            if(temp1->data != trash) NotFound(trash);
            else DeleteLast();
        }else{
            temp2->next = temp1->next;
            temp1->next->prev = temp2;
            free(temp1);
        }
    }
}

void DeleteAfter(char checkpt){
    node *temp1, *temp2;
    temp1 = head;
    if(temp1 == NULL) cout << "List kosong!!" << endl;
    else{
        do{
            if(temp1 == tail) break;
            temp2 = temp1;
            temp1 = temp1->next;
        }while(temp2->data != checkpt);
        if(temp1 == tail){
            if(temp2->data == checkpt) DeleteLast();
            else{
                if(temp1->data != checkpt) NotFound(checkpt);
                else cout << "Data '" << checkpt << "' ada pada tail" << endl;
            }
        }else{
            temp2->next = temp1->next;
            temp1->next->prev = temp2;
            free(temp1);
        }
    }
}

void DeleteBefore(char checkpt){
    node *temp1, *temp2;
    temp1 = head;
    if(temp1 == NULL) cout << "List kosong!!" << endl;
    else if(temp1->data == checkpt) cout << "Data '" << checkpt << "' ada pada head" << endl;
    else{
        while(temp1->data != checkpt){
            if(temp1 == tail){
                NotFound(checkpt);
                return;
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
        if(temp2 == head) DeleteFirst();
        else{
            temp1->prev = temp2->prev;
            temp2->prev->next = temp1;
            free(temp2);
        }
    }
}

void DeleteAll(){
    node *temp1, *temp2;
    temp1 = head;
    if(temp1 == NULL) cout << "List kosong!!" << endl;
    else{
        while(temp1 != tail){
            temp2 = temp1;
            temp1 = temp1->next;
            free(temp2);
        }
    }
    free(temp1);
    head = tail = NULL;
}

void FindDataByIndex(int index){
    cout << endl;
    if(index < 0){
        cout << "Indeks merupakan bilangan cacah!" << endl;
        return;
    }
    node *temp;
    temp = head;
    if(temp == NULL){
        cout << "List kosong!!" << endl;
        return;
    }
    int i = 0;
    while(i != index){
        if(temp == tail) break;
        i++;
        temp = temp->next;
    }
    if(index > i) cout << "Indeks FindData melebihi supply" << endl;
    else cout << "Data pada indeks ke-" << index << " : " << temp->data << endl;
}

void FindIndexByData(char cari){
    cout << endl;
    node *temp;
    temp = head;
    if(temp == NULL){
        cout << "List kosong!!" << endl;
        return;
    }
    int i = 0;
    while(temp->data != cari){
        if(temp == tail) break;
        i++;
        temp = temp->next;
    }
    if(temp == tail && temp->data != cari) NotFound(cari);
    else cout << "Data '" << cari << "' berada pada indeks ke-" << i << endl;
}

node * FindNodeByIndex(int index){
    node *helper;
    helper = (node *) malloc(sizeof(node));
    helper->data = '?';

    if(index < 0) return helper;
    struct node *temp;
    temp = head;
    int i = 0;
    while(i != index){
        i++;
        temp = temp->next;
        if(temp == tail) break;
    }
    if(index > i) return helper;
    return temp;
}

void PrintAll(){
    struct node *temp;
    temp = head;
    cout << endl;
    if(temp == NULL) cout << "List kosong!!" << endl;
    else{
        cout << "Indeks\tData" << endl;
        int i = 0;
        while(temp != tail->next){
            cout << i << "\t" << temp->data << endl;
            i++;
            temp = temp->next;
        }
    }
    cout << "------------" << endl;
}

void ReversePrintAll(){
    node *temp;
    temp = head;
    cout << endl;
    if(temp == NULL) cout << "List kosong!!" << endl;
    else{
        int i = 0;
        while(temp != tail){
            i++;
            temp = temp->next;
        }
        cout << "Indeks\tData" << endl;
        for(int index = i; index >= 0; index--){
            cout << index << "\t" << temp->data << endl;
            temp = temp->prev;
        }
    }
    cout << "------------" << endl;
}   

void PrintFromIndex(int index){
    if(index < 0){
        cout << "Indeks merupakan bilangan cacah!" << endl;
        return;
    }
    node *temp;
    temp = head;
    int i = 0;
    cout << endl;
    if(temp == NULL) cout << "List kosong!!" << endl;
    else{
        cout << "Indeks\tData" << endl;
        while(temp != tail){
            if(i >= index) cout << i << "\t" << temp->data << endl;
            temp = temp->next;
            i++;
        }
        if(index > i) cout << "-\t-\nIndeks PrintFromIndex melebihi supply" << endl;
        else cout << i << "\t" << temp->data << endl;
    }
    cout << "------------" << endl;
}

void PrintFromData(char mulai){
    node *temp;
    temp = head;
    bool cek = false;
    int i = 0;
    cout << endl;
    if(temp == NULL) cout << "List kosong!!" << endl;
    else{
        cout << "Indeks\tData" << endl;
        while(temp != tail){
            if(temp->data == mulai) cek = !cek;
            if(cek) cout << i << "\t" << temp->data << endl;
            temp = temp->next;
            i++;
        }
        if(!cek && temp->data != mulai){
            cout << "-\t-" << endl;
            NotFound(mulai);
        }
        else cout << i << "\t" << temp->data << endl;
    }
    cout << "------------" << endl;
}
