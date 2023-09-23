#include<iostream>

using namespace std;

#define lli long long int

inline lli sum(lli *psums, int l, int r) {
	return psums[r] - psums[l - 1];
} 


int main() {
	int n, k;

	cin >> n >> k;

	lli presum[n + 1];
	presum[0] = 0;

	for (int i = 1; i <= n; i++) {
		int b;
		cin >> b;
		presum[i] = presum[i - 1] + b;
	}

	lli max_a = presum[n - k] - presum[n - 2 * k];
	lli max_b = presum[n] - presum[n - k];

	int mb = n - k + 1;
	lli mans = max_a + max_b;
	lli A = n - 2 * k + 1, B = n - k + 1;
	for (int a = n - 2 * k; a >= 1; a--) {
		lli s_b = sum(presum, a + k, a + 2 * k - 1);
		if (s_b >= max_b) {
			max_b = s_b;
			mb = a + k;
		}

		lli ans = max_b + sum(presum, a, a + k - 1);
		if (ans >= mans) {
			A = a;
			B = mb;
			mans = ans;
		}
	}

	cout << A << ' ' << B;
}
