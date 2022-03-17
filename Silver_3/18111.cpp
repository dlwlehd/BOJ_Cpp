#include <bits/stdc++.h>
using namespace std;

int n, m, b;
int world[502][502];

int makeFlat(int height)
{
	int higherCount = 0;
	int lowerCount = 0;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (world[y][x] > height) higherCount += world[y][x] - height;
			else if (world[y][x] < height) lowerCount += height - world[y][x];
		}
	}

	if (higherCount == 0 && lowerCount == 0) {
		return 0;
	}

	if (lowerCount > higherCount + b) {
		return -1;
	}

	return higherCount * 2 + lowerCount;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> b;

	int maxHeight = 0, minHeight = INT_MAX;
	int answerTime = INT_MAX, answerHeight = 0;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> world[y][x];

			maxHeight = max(maxHeight, world[y][x]);
			minHeight = min(minHeight, world[y][x]);
		}
	}

	for (int i = minHeight; i <= maxHeight; i++) {
		int elapsedTime = makeFlat(i);

		if (elapsedTime >= 0 && answerTime >= elapsedTime) {
			answerTime = elapsedTime;
			answerHeight = i;
		}
	}

	cout << answerTime << " " << answerHeight << "\n";
	return 0;
}