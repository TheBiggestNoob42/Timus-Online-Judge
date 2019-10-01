#include <bits/stdc++.h>
using namespace std;

#define MAXN 100 + 1

int branch[MAXN][MAXN];
int N, Q;

void create_table() {
	for (int i = N; i >= 0; i--) {
		for (int j = N; j >= 0; j--) {
			
		}
	}
}

int main() {
	cin >> N;
	cin >> Q;

	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			branch[i][j] = 0;
		}
	}

	int B, E, A, temp;
	for (int i = 0; i < N - 1; i++) {
		cin >> B >> E >> A;
		if (E > B) {
			temp = E;
			E = B;
			B = temp;
		}
		branch[B][E] = A;
	}

	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			cout << branch[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}