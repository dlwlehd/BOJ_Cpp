#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {

	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> a;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x;
		cin >> y;
		a.push_back(make_pair(x, y));
	}

	sort(a.begin(), a.end(), compare);

	for (int i = 0; i < a.size(); i++) {
		cout << a[i].first << " ";
		cout << a[i].second << "\n";
	}
}