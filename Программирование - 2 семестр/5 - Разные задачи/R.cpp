﻿#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

vector<int> prefix_function(string s) {
	int len = s.length();
	vector<int> pi(len);
	for (int i = 1; i < len; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

bool KMP(string s, string t, vector<int> pi) {
	int ptr_s = 0, ptr_t = 0;
	while (true) {
		if (s[ptr_s] == t[ptr_t]) {
			ptr_s++; ptr_t++;
			if (ptr_t == t.length()) return true;
		}
		else {
			if (ptr_t == 0) {
				ptr_s++;
				if (ptr_s >= s.length()) return false;
			}
			else ptr_t = pi[ptr_t - 1];
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a, b;
	cin >> a >> b;
	vector<int> pi = prefix_function(b);
	if (KMP(a, b, pi)) cout << "YES\n";
	else cout << "NO\n";
	//system("pause");
	return 0;
}