#include <iostream> 
#include <math.h> 
#include <queue>
#include <set>
#include <string>

using namespace std;

int main() {
	int s[31] = { 1, 1 };
	int n; cin >> n;
	if (n < 3) {
		for (int i = 0; i < n; i++) cout << s[i] << endl;
	}
	else {
		for (int i = 2; i < n; i++) s[i] = s[i - 1] + s[i - 2];
		for (int i = 0; i < n; i++) cout << s[i] << endl;
	}
	//system("pause");
	return 0;
}