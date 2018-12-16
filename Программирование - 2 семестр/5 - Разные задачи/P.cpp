#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[1000010][3];
int ptr = 0;

int main() {
	int n, s[1000];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			a[ptr][0] = i;
			a[ptr][1] = j;
			a[ptr][2] = s[i] + s[j];
			ptr++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < ptr; j++) {
			if (s[i] == a[j][2]) {
				cout << ++i << " " << ++a[j][0] << " " << ++a[j][1] << "\n";
				return 0;
			}
		}
	}
	cout << "-1\n";
	return 0;
}