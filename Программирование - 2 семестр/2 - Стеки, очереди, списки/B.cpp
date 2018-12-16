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
	string s;
	stack<char> a;
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (a.empty()) a.push(s[i]);
			else if (a.top() == '(' && s[i] == ')') a.pop();
			else if (a.top() == '[' && s[i] == ']') a.pop();
			else a.push(s[i]);
		}
		if (a.empty()) cout << "Yes" << endl;
		else cout << "No" << endl;
		while (!a.empty()) a.pop();
	}
	//system("pause");
	return 0;
}