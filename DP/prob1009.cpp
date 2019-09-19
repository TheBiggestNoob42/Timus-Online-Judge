#include <bits/stdc++.h>
using namespace std;

long* pow_list;

long pow(long base, long power) {
	if (pow_list[power] != -1)
		return pow_list[power];

	long r = pow(base, power / 2);	
	r = r * r;
	if (power % 2 == 1)
		r = r * base;

	pow_list[power] = r;
	return r;
}

bool is_violation(long numb, long K) {
	// start from the bottom
	int zeros = 0;
	while (numb != 0 && zeros < 2) {
		// get the last digit
		long ld = numb % K;
		zeros = (ld == 0) ? zeros + 1 : 0;
		numb /= K;
	}
	return (zeros == 2);
}

int main() {
	long N, K;
	cin >> N;
	cin >> K;

	pow_list = (long*)malloc(N * sizeof(long));
	pow_list[0] = 1;
	pow_list[1] = K;
	for (int i = 2; i < N; i++) {
		pow_list[i] = -1;
		pow(K, i);
	}

	long start = pow_list[N - 1];
	long end = pow_list[N - 1] * K - 1;

	int count = 0;
	for (long i = start; i <= end; i++) {
		if (!is_violation(i, K)) {
			count++;
		}
	}

	cout << start << "\t" << end << endl;
	cout << count << endl;

	return 0;
}