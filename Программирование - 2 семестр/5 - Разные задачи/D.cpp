#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

const int base = 10000;

int fact(int n) {
	if (n == 0) return 1;
	int ans = n;
	while (--n) ans *= n;
	return ans;
}

int comb(int n, int k) {
	return fact(n) / (fact(n - k)*fact(k));
}

void ShortMultiple(vector<int> &a, int n) {
	int carry = 0;
	for (int i = 0; i < a.size(); i++) {
		int cur = a[i] * n + carry;
		a[i] = cur % base;
		carry = cur / base;
	}
	if (carry) a.push_back(carry);
}

void printLong(vector<int> &a) {
	cout << a[a.size() - 1];
	for (int i = a.size() - 2; i >= 0; i--) cout << setw(4) << setfill('0') << a[i];
	cout << "\n";
}

int main() {
	freopen("paint.dat", "r", stdin);
	freopen("paint.sol", "w", stdout);
	int n, k;
	cin >> k >> n;
	int t = comb(k, 4) * 24;
	vector<int> res(1);
	res[0] = t;
	while (--n) ShortMultiple(res, t - 1);
	printLong(res);
	//system("pause");
	return 0;
}