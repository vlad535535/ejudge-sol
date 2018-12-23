#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

string sol() {
	int n, a[50], p[50000] = {};
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++)
		if (a[i] <= a[i - 1]) return "No";
	for (int i = 0; i < n; i++) {
		if (p[a[i]] == 1) return "No";
		for (int j = 49999; j >= 0; j--)
			if (p[j] == 1) p[j + a[i]] = 1;
		p[a[i]] = 1;
	}
	return "Yes";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << sol() << "\n";
	}
	//system("pause");
	return 0;
}

/*
Сумма всех элементов не превышает 50000.
Создаем массив a на 50000.
Обозначаем в нем 1 частичные суммы.

То есть:
Берем по очереди элементы последовательности сначала.
Пусть элемент - k
Если a[k] == 1 - то возвращаем "No"
Иначе проходим циклом по массиву справа налево и отмечаем новые суммы
for(int i = 49999; i >= 0; i--) {
	if (a[i] == 1) a[i+k] = 1;
}
Отмечаем сам этот элемент
a[k] = 1;
Берем следующий элемент и делаем то же самое.
Если всё отработало - то вовращаем "Yes"
*/
