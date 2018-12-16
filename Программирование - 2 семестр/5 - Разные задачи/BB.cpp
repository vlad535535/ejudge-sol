#include <cstdio>
#define ll long long
int st[1000100][2];
int ptr = -1;

ll f(ll a, ll b, ll c, ll x) {
	return (a * x * x + b * x + c) / 100 % 1000000;
}

void push_st(ll v) {
	ptr++;
	if (ptr > 0) {
		st[ptr][0] = v;
		st[ptr][1] = (v < st[ptr - 1][1] ? v : st[ptr - 1][1]);
	}
	else {
		st[ptr][0] = v;
		st[ptr][1] = v;
	}
}

void pop_st() {
	if (ptr == -1) return;
	ptr--;
}

int main() {
	ll n, a, b, c, x0, sum = 0;
	scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &x0);
	int xi = f(a, b, c, x0);
	if (xi % 5 >= 2) {
		push_st(xi);
		sum += st[ptr][1];
	}
	for (int i = 0; i < n - 1; i++) {
		int prev_xi = xi;
		xi = f(a, b, c, prev_xi);
		if (xi % 5 < 2) pop_st();
		else push_st(xi);
		if (ptr > -1) sum += st[ptr][1];
	}
	printf("%lld\n", sum);
	return 0;
}