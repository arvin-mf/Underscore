#include <iostream>
using namespace std;

struct node{
    char data;
    struct node *next;
};

typedef struct node node;
node *first_in;

int choice;
char item;
int count = 0;
int keluar = 0;

void AddLast(char item){
    node *n = new node;
    n->data = item;
    n->next = NULL;
    if(first_in == NULL) first_in = n;
    else{
        node *t;
        t = first_in;
        while(t->next != NULL) t = t->next;
        t->next = n;
    }
}

void push(char item){
    AddLast(item);
    cout << "\n# PUSH : Index : " << count << ", Push : " << item << endl;
    count++;
}

void RemoveLast(){
    node *hapus, *t = NULL;
    hapus = first_in;
    while(hapus->next != NULL){
        t = hapus;
        hapus = hapus->next;
    }
    item = hapus->data;
    delete hapus;
    if(t != NULL) t->next = NULL;
    else first_in = NULL;
}

void pop(){
    if(first_in==NULL) cout << "\n## Stack kosong";
    else{
        RemoveLast();
        cout << "\n##POP hasil:" << item;
        cout << "\n##jumlah item dalam stack : " << --count << endl;
    }
}

void printAll(){
    cout << "\n## Stack Size : " << count;
    node *temp = new node;
    temp = first_in;
    if(temp == NULL) cout << "\nStack kosong!!" << endl;
    else{
        int i = 0;
        do{
            cout << "\n## No Urut/index : " << i << ", Value : " << temp->data;
            temp = temp->next;
            i++;
        }while(temp != NULL);
        cout << endl;
    }
    
}

void menu(){
    cout << "\nPilih operasi (1:push, 2:pop, 3:print) : ";
    cin >> choice;
    switch(choice){
        case 1:
            cout << "Masukkan huruf yang akan dipush : ";
            cin >> item;
            push(item);
            break;
        case 2: pop(); break;
        case 3: printAll(); break;
        default: keluar = 1;
    }
}


int main(){

    do menu(); while (keluar == 0);


    return 0;
}