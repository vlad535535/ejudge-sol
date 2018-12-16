#include<iostream> 
#include<math.h> 
#include <queue>
#include <set>
#include <string>
#include <map>

using namespace std;

int main() {
	freopen("kare.dat", "r", stdin);
	freopen("kare.sol","w", stdout);
	int n, m;
	map<int, int> cnt;
	set<int> nums;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int cur = -1, t;
		for (int j = 0; j < m; j++) {
			cin >> t;
			nums.insert(t);
			if (t != cur) {
				cur = t;
				cnt[t]++;
			}
		}
	}

	for (set<int>::iterator i = nums.begin(); i != nums.end(); i++) {
		cout << *i << " " << cnt[*i] << endl;
	}

	//system("pause");
	return 0;
}