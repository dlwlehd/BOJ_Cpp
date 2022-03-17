#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int n;
	cin >> n;
	int a[10];
	fill(a, a + 10, 0);

	if (n == 0) {
		cout << 1;
		return 0;
	}

	while (n > 0) {
		a[n % 10]++;
		n /= 10;
	}

	int max = 0;
	if ((a[9] + a[6]) % 2 == 1) max = (a[9] + a[6]) / 2 + 1;
	else max = (a[9] + a[6]) / 2;


	for (int i = 0; i < 9; i++) {
		if (i == 6) continue;

		if (max < a[i]) max = a[i];
	}
	cout << max;
}
