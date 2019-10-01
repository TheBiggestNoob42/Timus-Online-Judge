#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100
#define NEG_INF -2147483648
int dp[MAX_N][MAX_N];
int N;

int main() {
	// literally kadane algorithm
	cin >> N;

	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			dp[i][j] = NEG_INF;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dp[i][j];
		}
	}

	for (int row = 0; row < N; row++) {
		for (int col = 1; col < N; col++) {
			dp[row][col] += dp[row][col - 1];
		}
	}

	int global_max = NEG_INF;

	for (int col = 0; col < N; col++) {
		int col_max = NEG_INF;
		for (int row = 0; row < N; row++) {
			col_max = ((col_max > 0) ? col_max: 0) + dp[row][col];
		}
		global_max = (col_max > global_max) ? col_max : global_max;
	}

	cout << global_max << endl;
}