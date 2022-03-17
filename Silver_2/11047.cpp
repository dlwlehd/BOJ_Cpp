#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
#define X first
#define Y second

int n, k;
int coin[10];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	int count = 0;

	while (k != 0) {
		int i = n - 1;
		for (i = n - 1; i >= 0; i--) {
			if (k >= coin[i]) break;
		}

		while (k >= coin[i]) {
			k -= coin[i];
			count++;
		}
	}

	cout << count;

}