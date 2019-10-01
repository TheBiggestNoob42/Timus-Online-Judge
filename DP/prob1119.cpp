#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define pii pair<int, int>
#define MAX_K 100 + 1

vector<pii> grids;
double dp[MAX_K];

void create_table(int K) {
	if (K <= 1) {
		dp[1] += (-100 + 70.7106781187);
		return;
	}
	create_table(K - 1);
}

int main() {
	int N, M, K;
	cin >> N >> M;
	cin >> K;

	for (int i = 0; i < MAX_K; i++) {
		dp[i] = 0;
	}

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		grids.push_back(pii(x, y));
	}
	sort(grids.begin(), grids.end());

	cout << endl;
	for (int i = 0; i < K; i++) {
		cout << grids[i].first << " " << grids[i].second << endl;
	}

	// remove the ones connected to the x coord
	for (int i = 0; i < grids.size(); i++) {
		for (int j = i + 1; j < grids.size(); j++) {
			if (grids[i].first == grids[j].first) {
				grids.erase(grids.begin() + j);
				j--;
				K--;
			}
		}
	}

	cout << endl;
	for (int i = 0; i < K; i++) {
		cout << grids[i].first << " " << grids[i].second << endl;
	}

	dp[0] = N + M;
	create_table(K);
	return 0;
}
