#include <iostream> 
#include <math.h> 
#include <queue>
#include <set>
#include <string>
#include <map>

using namespace std;

int main() {
	int money[16] = { 0, 0, 1, 0, 2, 1, 3, 2, 4, 3, 2, 4, 3, 5, 4, 3 };
	int n, t = 0;
	cin >> n;
	if (n > 15) {
		t = (n - 15) / 5 + 1;
		n -= t * 5;
	}
	cout << t + money[n] << endl;
	//system("pause");
	return 0;
}