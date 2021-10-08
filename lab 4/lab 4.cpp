#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <stack> 
using namespace std;

struct node {
	int numb;
	node* next;
};
struct graf {
	node** nodes;
	int size;
};

void deep(int** a, int num, int* versh, int size) {
	versh[num] = 1;
	cout << num << " -> ";

	for (int i = 0; i < size; i++) {
		if (a[num][i] != 0 && versh[i] != 1)
			deep(a, i, versh, size);
	}

}
void deepDarkAss(graf* grafon, int num, int* versh){
	versh[num] = 1;
	node* buf = grafon->nodes[num];
	cout << num  << " -> ";
	
	while (buf != NULL) {
		if (versh[buf->numb] == 0)
			deepDarkAss(grafon, buf->numb, versh);
		buf = buf->next;
	}
 }
void norec(graf* grafon, int num, int* versh, int size) {
	// auto stack = new int(size);
	stack <int> steck;
	versh[num] = 1;
	node* buf = grafon->nodes[num];
	cout << num << " -> ";
	steck.push(num);
	int q;
	while (!steck.empty()) {

	
		buf = grafon->nodes[num];
		//num = buf->numb;
			while (buf != 0) {
				if (versh[buf->numb] == 0) {
					cout << buf->numb << " -> ";
					steck.push(buf->numb);
					versh[buf->numb] = 1;
					buf = grafon->nodes[buf->numb];
				} 
				else
					buf = buf->next;
			}
		versh[num] = 1;
		num = steck.top();
		steck.pop();
	}
}
graf* sozdat(int versh) {

	graf* grafon = new graf;
	grafon->size = versh;
	grafon->nodes = new node* [versh];
	for (int i = 0; i < versh; i++) {
		grafon->nodes[i] = NULL;
	}
	return grafon;
}
node* sozdatnode(int index) {
	node* newnode = new node;
	newnode->numb = index;
	newnode->next = NULL;
	return newnode;
}

void addgran(graf* grafon, int from, int to) {
	node* newnode = sozdatnode(from);
	if (grafon->nodes[to] == 0) {
		grafon->nodes[to] = newnode;
		newnode = NULL;
	}
	node* buf = grafon->nodes[to];
	while (buf->next != NULL) {
		buf = buf->next;
	}
	buf->next = newnode;

	newnode = sozdatnode(to);
	if (grafon->nodes[from] == 0) {
		grafon->nodes[from] = newnode;
		return;
	}
	buf = grafon->nodes[from];
	while (buf->next != NULL) {
		buf = buf->next;
	}
	buf->next = newnode;
}
void main(){
srand(time(0));
setlocale (LC_ALL, "Russian");
int size;

//cout <<  "������� ����������� �������"<< " ";
//cin >> size;
//cout << endl;
//
//int** arr = new int* [size];
//
//for (int count = 0; count < size; ++count)
//    arr[count] = new int[size];
//
//for(int row = 0;row< size;row++){
//	arr[row][row] = 0;
//	for(int col = row+1;col< size;col++){
//		arr[row][col] = rand()%2;
//		arr [col][row] = arr[row][col];
//	}
//}
//
//for(int row = 0;row < size;row++){
//	for(int col = 0; col < size;col++){
//cout << arr[row][col] << " " ;
//		}
//cout<<endl;
//	}
//
//system("pause");
//
//auto versh = new int[size];
//for (int i = 0; i < size; i++)
//	versh[i] = 0;
//cout << "  ������� ����� �������? � ������� ������ ������ ����� " << endl;
//int num;
//cin >> num;
//
//deep(arr, num, versh, size);
//cout << endl;
//for (int i = 0; i < size; i++)
//	delete (arr[i]);
//delete (arr);
//delete (versh);
//system("pause");
//
//cout << endl << " ����� � ������� ������� ���������" << endl;
//
//cout << "������� ����������� �������" << " ";
//cin >> size;
//cout << endl;
//
// arr = new int* [size];
//
//for (int count = 0; count < size; ++count)
//	arr[count] = new int[size];
//
//for (int row = 0; row < size; row++) {
//	arr[row][row] = 0;
//	for (int col = row + 1; col < size; col++) {
//		arr[row][col] = rand() % 2;
//		arr[col][row] = arr[row][col];
//	}
//}
//
//for (int row = 0; row < size; row++) {
//	for (int col = 0; col < size; col++) {
//		cout << arr[row][col] << " ";
//	}
//	cout << endl;
//}
//
//
//graf* grafon = sozdat(size);
//int j = 1;
//for (int i = 0; i < size; i++) {
//	for (j; j < size; j++) {
//		if (arr[i][j] == 1) {
//			addgran(grafon, i, j);
//		}
//	}
//	j = j - size + i + 1;
//}
//for (int i = 0; i < size; i++) {
//	node* temp = grafon->nodes[i];
//	cout << i << " ";
//
//	while (temp) {
//		cout << "->" << temp->numb;
//		temp = temp->next;
//	}
//	cout << endl;
//}
//system("pause");
//
//
//for (int i = 0; i < size; i++)
//	versh[i] = 0;
//cout << "  ������� ����� �������? � ������� ������ ������ ����� " << endl;
// num = 0;
//cin >> num;
//
//deepDarkAss(grafon, num, versh);
//for (int i = 0; i < size; i++)
//	delete (arr[i]);
//delete (arr);
//system("pause");
//

cout << endl << "����� � ������� �� ����������� �������";
cout <<  "������� ����������� �������"<< " ";
cin >> size;
cout << endl;

auto arr = new int* [size];

for (int count = 0; count < size; ++count)
	arr[count] = new int[size];

for (int row = 0; row < size; row++) {
	arr[row][row] = 0;
	for (int col = row + 1; col < size; col++) {
		arr[row][col] = rand() % 2;
		arr[col][row] = arr[row][col];
	}
}

for (int row = 0; row < size; row++) {
	for (int col = 0; col < size; col++) {
		cout << arr[row][col] << " ";
	}
	cout << endl;
}

graf* grafon = sozdat(size);
int j = 1;
for (int i = 0; i < size; i++) {
	for (j; j < size; j++) {
		if (arr[i][j] == 1) {
			addgran(grafon, i, j);
		}
	}
	j = j - size + i + 1;
}
for (int i = 0; i < size; i++) {
	node* temp = grafon->nodes[i];
	cout << i << " ";

	while (temp) {
		cout << "->" << temp->numb;
		temp = temp->next;
	}
	cout << endl;
}
system("pause");

auto versh = new int[size];
for (int i = 0; i < size; i++)
	versh[i] = 0;
cout << "  ������� ����� �������? � ������� ������ ������ ����� " << endl;
int num = 0;
cin >> num;

auto stack = new int(size);

norec(grafon, num, versh, size);
//versh[num] = 1;
//node* buf = grafon->nodes[num];
//cout << num << " -> ";
//stack[0] = buf->numb;


}