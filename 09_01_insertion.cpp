#include <iostream>
using namespace std;

#define MAX 12

int Data[MAX];

void StraightInsertSort(){
	int i, j, x;
	for(i = 1; i < MAX; i++){
		x = Data[i];
		j = i - 1;
		while (x > Data[j]){
			Data[j + 1] = Data[j];
			j--;
			if(j == -1) break;
		}
		Data[j + 1] = x;
	}
}

int main(){
	int i;
	srand(0);

	cout << "DATA SEBELUM TERURUT" << endl;
	for(i = 0; i < MAX; i++){
		Data[i] = (int) rand()/1000 + 1;
		cout << "Data ke-" << i << "\t: " << Data[i] << endl;
	}

	StraightInsertSort();

	cout << endl;
	cout << "DATA SETELAH TERURUT" << endl;
	for(i = 0; i < MAX; i++)
		cout << "Data ke-" << i << "\t: " << Data[i] << endl;
}
