#include <bits/stdc++.h>
using namespace std;

int n;

void hanoi(int a, int b, int n) { // a에서 b로 이동
	
	if (n == 1) {
		cout << a << " " << b << "\n";
		return;
	}
	hanoi(a, 6 - a - b, n - 1); // 1번 기둥에서 2번 기둥으로 n - 1개 옮김
	cout << a << " " << b << "\n"; // 1번 기둥에서 3번 기둥으로 n번째 원판 옮김
	hanoi(6 - a - b, b, n - 1); // 2번 기둥에서 3번 기둥으로 n - 1개 옮김

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cout << (1 << n) - 1 << "\n";
	hanoi(1, 3, n);
}