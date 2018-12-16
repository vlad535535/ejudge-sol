#include <iostream> 
#include <math.h> 
#include <queue>
#include <set>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string s[100];
	for (int i = 0; i < n; i++) cin >> s[i];
	int chk = true;
	for (int i = 0; i < n - 1; i++) {
		if (s[i][0] == s[i + 1][0]) chk = false;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (s[i][j] != s[i][j + 1]) chk = false;
		}
	}
	if (chk) cout << "YES\n";
	else cout << "NO\n";
	//system("pause");
	return 0;
}