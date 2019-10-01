#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500 + 1
#define MAX_WIDTH 250 + 1

typedef long long ll;

// dp[i][j]
// i signifies the number of blocks total
// j signifies the number of blocks in the first slot
ll dp[MAX_N][MAX_WIDTH];

int N;

void create_table(int n) {
	if (n == 5) {
		dp[5][1] = 1L;
		dp[5][2] = 1L;
		return;
	}
	
	create_table(n - 1);
	for (int x = 1; (x < n - x); x++) {
		dp[n][x] = 1;
		for (int h = 1; n - 3 * x - 2 * h > 0; h++) {
			dp[n][x] += dp[n - x][x + h];
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			dp[i][j] = 0L;
		}
	}

	dp[5][1] = 1L;
	dp[5][2] = 1L;

	create_table(N);
	
	ll sum = 0;
	for (int i = 0; i < MAX_WIDTH; i++) {
		sum += dp[N][i];
	}
	cout << sum << endl;
}