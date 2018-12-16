#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

int main() {
	freopen("rect.dat", "r", stdin);
	freopen("rect.sol", "w", stdout);

	int n, m;
	bool a[1000][1000];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> a[i][j];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j]) {
				ans++;
				for (int k = i; k < n; k++) {
					if (!a[k][j]) break;
					for (int l = j; l < m && a[k][l]; l++) a[k][l] = 0;
				}
			}
		}
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}