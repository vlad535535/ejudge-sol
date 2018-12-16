#include <iostream>
#include <math.h>

using namespace std;

int a[1000010], len;
long long sqrt_sums[1001];

void q(int ind, int v) {
	int d = v - a[ind];
	a[ind] += d;
	sqrt_sums[ind / len] += d;
}

long long get_sum(int l, int r) {
	long long ans = 0;
	int outl = l / len, outr = r / len;
	if (outl == outr)
		for (int i = l; i <= r; i++) ans += a[i];
	else {
		for (int i = l; i <= (outl + 1)*len - 1; i++) ans += a[i];
		for (int i = outl + 1; i <= outr - 1; i++) ans += sqrt_sums[i];
		for (int i = outr * len; i <= r; i++) ans += a[i];
	}
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	len = (int)sqrt(n) + 1;
	while (k--) {
		int q1, q2, q3;
		cin >> q1 >> q2 >> q3;
		if (q1 == 1) q(--q2, q3);
		else cout << get_sum(--q2, --q3) << endl;
	}
	//system("pause");
	return 0;
}