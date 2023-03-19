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
// void AddAfter(char c);
// void AddBefore(char c);

node FindByIndex(int index);        
void PrintAll();

int main(){
    head = tail = NULL;
    PrintAll();
    
    AddLast('T');
    AddFirst('Q');
    AddLast('A');
    AddFirst('D');
    AddToIndex(-0, 'M'),
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
    if(temp1 == NULL) head = tail = baru;
    else if(index == 0) AddFirst(c);
    else{
        int i = 0;
        while(i != index){
            temp2 = temp1;
            temp1 = temp1->next;
            i++;
            if(temp2 == tail) break;
        }
        if(index > i){
            cout << "Indeks AddToIndex melebihi supply" << endl;
            return;
        }
        if(temp2 == tail){
            AddLast(c);
            return;
        }
        temp2->next = temp1->prev = baru;
        baru->prev = temp2;
        baru->next = temp1;
    }
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