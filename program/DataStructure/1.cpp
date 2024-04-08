#include <iostream>

using namespace std;


int main(int argc, char *argv[]) {
	int a[10] = {1, 2, 3, 3, 5, 6, 1, 5, 6, 9};
	int k = 0;
	for(int i = 0; i < 10; i++) {
	if(a[i] < 3 || a[i] > 5)
			a[k++] = a[i];
}
	for(int i = 0; i < k; i++)
		cout << a[i] << ' ';
	return 0;
}