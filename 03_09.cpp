#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

struct node {
    char data;
    struct node *next; 
};
typedef struct node node;
node *head, *tail;

void PrintAll();
void AddLast(char item);                // penambahan
void AddFirst(char item);               // penambahan
void AddBefore(char input, char patok); // penyisipan
void AddAfter(char input, char patok);  // penyisipan
void DeleteFirst();                     // penghapusan
void DeleteLast();                      // penghapusan
void DeleteByData(char patok);          // penghapusan
void FindData(char patok);              // pencarian
void ChangeData(char patok, char baru); // pengaksesan

int main(){
    head = tail = NULL;
    AddFirst('A');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;
    AddFirst('B');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;
    AddFirst('C');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;
    AddFirst('D');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;

    PrintAll();
    
    // DeleteFirst();
    // DeleteLast();
    // AddBefore('E', 'A');
    // AddLast('E', 'C');
    // DeleteByData('C');
    // FindData('K');
    // ChangeData('C', 'P');

    // PrintAll();

    getch();    
    return EXIT_SUCCESS;
}

void PrintAll(){
    node *pTemp;
    pTemp = head;
    if(pTemp == NULL) cout << "List kosong" << endl;
    else{
        cout << endl;
        do{
            cout << "Data : " << pTemp->data << " " << endl;
            pTemp = pTemp->next;
        }while(pTemp != tail->next);
        cout << "Akhir list" << endl;
    }
}

void AddLast(char item){ // Add Node After Tail
    struct node *pNew;
    pNew = (node *) malloc(sizeof(node));
    pNew->data = item;
    if (head == NULL) head = pNew;
    else tail->next = pNew;
    tail = pNew;
}

void AddFirst(char item){ // AddNodeBeforeHead
    struct node *pNew;
    pNew = (node *) malloc(sizeof(node));
    pNew->data = item;
    if (head == NULL) tail = pNew;
    else pNew->next = head;
    head = pNew;
}

void AddBefore(char input, char patok){
    node *insert, *pTemp1, *pTemp2;
    insert = (node *)  malloc(sizeof(node));
    insert->data = input;
    pTemp1 = head;
    while(pTemp1->data != patok){
        pTemp2 = pTemp1;
        pTemp1 = pTemp1->next;
    }
    if(pTemp1 == head){
        AddFirst(input);
        return;
    }
    insert->next = pTemp2->next;
    pTemp2->next = insert;
}

void AddAfter(char input, char patok){
    node *insert, *pTemp;
    insert = (node *)  malloc(sizeof(node));
    insert->data = input;
    pTemp = head;
    while(pTemp->data != patok) pTemp = pTemp->next;
    if(pTemp == tail){
        AddLast(input);
        return;
    }
    insert->next = pTemp->next;
    pTemp->next = insert;
}

void DeleteFirst(){
    if(head == NULL) cout << "List kosong!!" << endl;
    else{
        node *pTemp;
        pTemp = head;
        if(pTemp == tail) delete pTemp;
        else{
            head = head->next;
            delete pTemp;
        }
    }
}

void DeleteLast(){
    node *pTemp1, *pTemp2;
    if (head == NULL) cout << "List kosong!!" << endl;
    else{
        pTemp1 = head;
        if (pTemp1 == tail) delete pTemp1;
        else{
            do{
                pTemp2 = pTemp1;
                pTemp1 = pTemp1->next;
            }while (pTemp1 != tail);
            delete pTemp1;
            tail = pTemp2;
        }
    }
}

void DeleteByData(char patok){
    node *pJunk, *pTemp;
    pJunk = head;
    while(pJunk->data != patok){
        pTemp = pJunk;
        pJunk = pJunk->next;
    }
    if(pJunk == tail) DeleteLast();
    else if(pJunk == head) DeleteFirst();
    else{
        pTemp->next = pJunk->next;
        delete pJunk;
    }
}

void FindData(char patok){
    node *temp;
    temp = head;
    int cek = 0;
    do{
        if(temp->data == patok) cek++;
        temp = temp->next;
    }while(temp != tail->next);
    if(cek > 0) cout << "Data '" << patok << "' ditemukan" << endl;
    else cout << "Data '" << patok << "' tidak ditemukan" << endl;
}

void ChangeData(char patok, char baru){
    node *temp;
    temp = head;
    while(temp->data != patok) temp = temp->next;
    temp->data = baru;
}