#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int n, a[100100], b[1001];

int main() {
    freopen("numb.dat", "r", stdin);
    freopen("numb.sol", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    int maxn = -1, ind = -1;
    for (int i = 0; i < 1001; i++) {
        if (b[i] > maxn) {
            maxn = b[i];
            ind = i;
        }
    }
    cout << ind << endl;
    return 0;
}