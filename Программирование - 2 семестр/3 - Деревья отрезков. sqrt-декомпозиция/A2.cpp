﻿#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

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
	for (int i = l; i <= r; i++) {
		if (i % len == 0 && i + len - 1 <= r) {
			ans += sqrt_sums[i / len];
			i += len - 1;
		}
		else ans += a[i];
	}
	return ans;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	len = (int)sqrt(n) + 1;
	while (k--) {
		int q1, q2, q3;
		scanf("%d %d %d", &q1, &q2, &q3);
		if (q1 == 1) q(--q2, q3);
		else printf("%lld\n", get_sum(--q2, --q3));
	}
	//system("pause");
	return 0;
}