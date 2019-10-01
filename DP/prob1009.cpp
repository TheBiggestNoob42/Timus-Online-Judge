#include <bits/stdc++.h>
using namespace std;

#define MAXN 1800 - 2 + 1

typedef long long ll;

ll dp[MAXN];
ll K;

void create_table(int N) {
	if (N < 2) {
		return;
	}
	if (N == 2) {
		dp[N] = K * dp[N - 1];
		return;
	}
	create_table(N - 1);
	dp[N] = (K - 1) * dp[N - 1] + (K - 1) * dp[N - 2];
}

int main() {
	ll N;
	cin >> N;
	cin >> K;

	for (int i = 0; i < MAXN; i++) {
		dp[i] = 0L;
	}
	dp[1] = K - 1;

	create_table(N);

	cout << dp[N] << endl;

	return 0;
}