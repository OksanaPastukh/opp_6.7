#include <iostream>
using namespace std;
#include "Array.h"

int main()
{
	int a[5] = { 1, -2, 0, 4, -5 }; // вхідний контейнер
	cout << " a = ";
	for (int i = 0; i < 5; i++)
		cout << a[i] << ' ';
	cout << endl;
	int b[5], c[5], d[5]; // результуючі контейнери
	// (потрібно виділити достатньо пам'яті)
	replace_copy(&a[0], &a[5], &b[0],4,99); // продублювали всі елементи
	cout << "b = ";
	for (int i = 0; i < 5; i++)
		cout << b[i] << ' '; // вивели результат
	cout << endl;
	Predicate<int>* zero = new Zero<int>(); // функтор: "нульові елементи"
	int n = replace_copy_if(&a[0], &a[5], &c[0], *zero, 99); // продубювали нульові елементи
	cout << "c = ";
	for (int i = 0; i < n; i++)
		cout << c[i] << ' ';
	cout << endl;
	Predicate<int>* pos = new Positive<int>(); // функтор: "додатні елементи"
	int k = replace_copy_if(&a[0], &a[5], &d[0], *pos,99); // продублювали додатні елементи
	cout << "d = ";
	for (int i = 0; i < k; i++)
		cout << d[i] << ' ';
	cout << endl;
	system("pause");
	return 0;
}