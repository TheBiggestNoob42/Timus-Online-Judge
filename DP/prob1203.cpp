#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000 + 1
#define MAX_TIME 30000 + 1
#define pii pair<int, int>

int 
int dp[MAX_N];
vector<pii> ray;
int pre;

void create_table(int N) {
	if (N <= 1) {
		return;
	}
	create_table(N - 1);
	if ((ray[N - 1].first - ray[pre].second >= 1)) {
		pre = N - 1;
		dp[N] = dp[N - 1] + 1;
	} else {
		dp[N] = dp[N - 1];
	}
}

int main() {
	int N;
	cin >> N;

	pre = 0;

	for (int i = 0; i < MAX_N; i++) {
		dp[i] = 0;
	}

	int b, e;
	for (int i = 0; i < N; i++) {
		cin >> b >> e;
		ray.push_back(pii(e, b));
	}
	sort(ray.begin(), ray.end());

	dp[1] = 1;
	
	create_table(N);

	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << ray[i].first << " " << ray[i].second << " ==> " << dp[i + 1] << endl;
	}
	return 0;
}