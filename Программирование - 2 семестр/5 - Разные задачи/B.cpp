#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

int main() {
	freopen("merge.dat", "r", stdin);
	freopen("merge.sol", "w", stdout);
	int n, m, t;
	priority_queue<int> sol;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		sol.push(t);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> t;
		sol.push(t);
	}
	for (int i = 0; i < n + m; i++) {
		cout << sol.top() << endl;
		sol.pop();
	}
	//system("pause");
	return 0;
}