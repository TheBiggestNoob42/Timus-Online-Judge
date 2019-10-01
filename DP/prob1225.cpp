#include <bits/stdc++.h>
using namespace std;

#define MAX_STRIPES 45 + 1
typedef long long ll;
ll dp[MAX_STRIPES];

void create_table(ll N) {
	if (N <= 5) {
		return;
	}
	create_table(N - 1);
	dp[N] = dp[N - 1] + dp[N - 2];
}

int main() {
	ll N;
	cin >> N;

	for (ll i = 0; i < MAX_STRIPES; i++) {
		dp[i] = 0;
	}
	dp[0] = 0;
	dp[1] = 2;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 6;
	dp[5] = 10;

	create_table(N);

	cout << dp[N] << endl;
	return 0;
}