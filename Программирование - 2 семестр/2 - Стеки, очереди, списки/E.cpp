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
	int n, t, maxx = 0;
	cin >> n;
	stack<int> a;
	while (n--) {
		cin >> t;
		if (t > maxx) {
			while (maxx < t) {
				a.push(maxx + 1);
				maxx++;
			}
		}
		if (a.top() == t) {
			a.pop();
		}
		else {
			cout << "Cheater" << endl;
			return 0;
		}
	}
	cout << "Not a proof" << endl;
	//system("pause");
	return 0;
}