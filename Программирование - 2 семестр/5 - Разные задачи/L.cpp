#include <iostream> 
#include <math.h> 
#include <queue>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	set<int> mas;
	set<int>::iterator it;
	while (n--) {
		int t;
		cin >> t;
		mas.insert(t);
	}
	it = mas.begin();
	if (mas.size() == 1) cout << "NO\n";
	else cout << *(++it);
	//system("pause");
	return 0;
}