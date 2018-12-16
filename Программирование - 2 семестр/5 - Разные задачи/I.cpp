#include<iostream> 
#include<math.h> 
#include <queue>

using namespace std;

int main() {
	char q; int val;
	priority_queue<int> mas;
	while (cin >> q) {
		if (q == 'I') {
			cin >> val;
			mas.push(val);
		}
		else {
			cout << mas.top() << endl;
			mas.pop();
		}
	}
	//system("pause");
	return 0;
}