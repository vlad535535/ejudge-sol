#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

void multMatrix(int A[2][2], int B[2][2]) {
	int T[2][2];
	T[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
	T[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
	T[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
	T[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			A[i][j] = T[i][j];
}

void power(int mat[2][2], int n) {
	if (n < 2) return;
	int t[2][2] = { {1, 1}, {1, 0} };
	power(mat, n / 2);
	multMatrix(mat, mat);
	if (n % 2 != 0) multMatrix(mat, t);
}

int getNthFib(int N) {
	int fib[2][2] = { {1, 1}, {1, 0} };
	if (N == 0) return 0;
	power(fib, N - 1);
	return fib[0][0];
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cout << getNthFib(i) << "\n";
	//system("pause");
	return 0;
}