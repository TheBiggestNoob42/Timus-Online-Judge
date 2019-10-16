#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
	int N, K;
	string B;

	cin >> N >> B;
	K = B.size();

	int total = 1;
	while (N > 0) {
		total *= N;
		N -= K;
	}

	cout << total << endl;
}
