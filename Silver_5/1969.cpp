#include <bits/stdc++.h>
using namespace std;

int n, m;
int result_sum;
string result = "";
string word[1002];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> word[i];

	for (int i = 0; i < m; i++) {
		int arr[26] = { 0 }, maxed = 0, max_index = 0;
		for (int j = 0; j < n; j++) {
			arr[word[j][i] - 'A']++;
		}
		for (int j = 0; j < 26; j++) {
			if (maxed < arr[j]) maxed = arr[j], max_index = j;
		}
		result_sum += n - maxed;
		result += max_index + 'A';
	}

	cout << result << endl;
	cout << result_sum << endl;
}