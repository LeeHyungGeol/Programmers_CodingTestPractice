#include <iostream>
using namespace std;

int N, K;
int choice[8];
int arr[8];

void comb(int n, int idx) {
	if (idx > K) {
		for (int i = 1; i <= K; ++i)
			cout << choice[i] << ' ';
		cout << '\n';
		return;
	}
	if (n > N) return;
	choice[idx] = arr[n];
	comb(n + 1, idx + 1);
	comb(n + 1, idx);
}

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; ++i) cin >> arr[i];
	comb(1, 1);

	return 0;
}