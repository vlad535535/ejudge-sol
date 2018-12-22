#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

int t, n, sum, s[100], p[500000];

string solution() {
	for (int i = 0; i < 500000; i++) p[i] = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	if (n == 1) return "Yes";
	for (int i = 1; i < n; i++) if (s[i - 1] >= s[i]) return "No";
	p[s[0] + s[1]] = 1; sum = s[n - 1] * n;
	for (int i = 2; i < n; i++) {
		if(p[s[i]]) return "No";
		for (int j = 0; j < i; j++) p[s[i] + s[j]] = 1;
		for (int j = sum; j >= s[i]; j--) if (p[j - s[i]]) p[j] = 1;
	}
	return "Yes";
}

int main() { 
	cin >> t;
	while (t--) cout << solution() << endl;
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