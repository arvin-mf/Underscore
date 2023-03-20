#include <iostream>
using namespace std;

struct node {
   //bagian data 
     char data;
   //pointer ke node selanjutnya
    struct node *next; 
    struct node *prev;
};
typedef struct node node;
node *head, *tail;

void AddLast(char c);               // Penambahan
void AddFirst(char c);              // Penambahan
void AddToIndex(int index, char c); // Penambahan
void AddAfter(char checkpt, char insert);
void AddBefore(char checkpt, char insert);
void DeleteLast();
void DeleteFirst();

node FindByIndex(int index);        
void PrintAll();

void NotFound(char c){
    cout << "Data '" << c << "' tidak ada" << endl;
}

int main(){
    head = tail = NULL;
    PrintAll();
    
    AddLast('T'), AddFirst('Q'), AddLast('A'), AddFirst('D'),
    AddAfter('A', 'U'), AddBefore('U', 'R'), AddToIndex(6, 'M'),
    DeleteLast(), 
    PrintAll();

    cout << FindByIndex(-1).data << endl;
    

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
        while(temp != tail) temp = temp->next;
        tail = temp->prev;
        delete temp;
    }
}

void DeleteFirst(){

}

node FindByIndex(int index){
    if(index < 0) return node{.data = '?'};
    struct node *temp;
    temp = head;
    int i = 0;
    while(i != index){
        i++;
        temp = temp->next;
        if(temp == tail) break;
    }
    if(index > i) return node{.data = '?'};
    return *temp;
}

void PrintAll(){
    struct node *temp;
    temp = head;
    cout << endl;
    if(temp == NULL) cout << "List kosong!!" << endl;
    else{
        cout << "Indeks\tData" << endl;
        int i = 0;
        do{
            cout << i << "\t" << temp->data << endl;
            i++;
            temp = temp->next;
        }while(temp != tail->next);
    }
    cout << "------------" << endl;
}