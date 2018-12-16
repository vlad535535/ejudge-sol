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
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (a.empty()) a.push(s[i]);
		else if (a.top() == '(' && s[i] == ')') a.pop();
		else a.push(s[i]);
	}
	cout << a.size() << endl;
	//system("pause");
	return 0;
}