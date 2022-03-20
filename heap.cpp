#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

class Heap {
public:
	int size;
	int max_size;
	int arr[];

	void insert(int i);
	void shift_up(int i);
	void shift_down(int i);
	int parent(int i) {return (i-1)/2;}
	int left_child(int i) {return 2*i + 1;}
	int right_child(int i) {return 2*i + 2;}
};

void Heap::shift_up(int i) {
	while(i > 0 && arr[parent(i)] < arr[i]) {
		swap(arr[i], arr[parent(i)]);
		i = parent(i);
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {1, 3, 2, 5, 4};
	int size = 5;
	cout << "Here";
	Heap h;
	return 0;
}