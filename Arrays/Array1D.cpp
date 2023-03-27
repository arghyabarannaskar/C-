#include<iostream>
using namespace std;
const int MAX = 5;

class Array {
private:
	int arr[MAX];
public:
	void insert(int pos, int num);
	void del(int pos);
	void reverse();
	void display();
	void search(int num);
};

//inserts an element num at given position pos
void Array::insert(int pos, int num) {
	int i;
	//shift elements to right
	for (i = MAX - 1; i >= pos; i--)
		arr[i] = arr[i - 1];
	arr[i] = num;
}

//deletes an element from the given position pos
void Array::del(int pos) {
	int i;
	//skip to the desired position
	for (i = pos; i < MAX; i++) 
		arr[i - 1] = arr[i];
	arr[i - 1] = 0;
}

void Array::reverse() {
	for (int i = 0; i < MAX / 2; i++) {
		int temp = arr[i];
		arr[i] = arr[MAX - 1 - i];
		arr[MAX - 1 - i] = temp;
	}
}

//searches Array for a given element num
void Array::search(int num) {
	for (int i = 0; i < MAX; i++) {
		if (arr[i] == num) {
			cout << "Element is at " << i + 1 << "th position " << endl;
        }
	}
}

//displays the contents of an array
void Array::display() {
	for (int i = 0; i < MAX; i++)
		cout << arr[i]<<" ";
}

int main() {
	Array a;
	a.insert(1, 11);
	a.insert(2, 12);
    a.insert(3, 13);
    a.insert(4, 14);
    a.insert(5, 15);
    cout << endl
         << "Elements of array: ";
    a.display();
    a.del(5);
    a.del(2);
    cout << endl
         << "After delettion: ";
    a.display();
    a.insert(2, 222);
    a.insert(5, 555);
    a.reverse();
    cout << endl
         << "After reversing: ";
    a.insert(1, 222);
    a.display();
    a.search(222);

    return 0;
}