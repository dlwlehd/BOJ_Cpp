#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	sort(a.begin(), a.end());

	vector<int> b;
	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}
	vector<int>::iterator low, up;
	
	for (int i = 0; i < b.size(); i++) {
		up = upper_bound(a.begin(), a.end(), b[i]);
		low = lower_bound(a.begin(), a.end(), b[i]);
		cout << up - low << " ";
	}
}