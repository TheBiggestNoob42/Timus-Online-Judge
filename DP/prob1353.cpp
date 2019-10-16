#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXS 81 + 1
ll dp[MAXS];

int main() {
	ll N;
	cin >> N;

	dp[1] = 10;
	dp[2] = 81;

	dp[81] = 1;
	dp[80] = 9;
}