#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int r;
    cin >> r;
    int cnt = 1, ans = 0;
    for (int i = 1; i <= r - 1; i++, cnt++) {
        if (sqrt(2) * cnt <= r) ans += cnt;
    }cout << 4 *  ans << endl;
}