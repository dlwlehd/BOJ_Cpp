#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
bool compare(string a, string b) {

	if (a.length() == b.length()) {
		return a < b;
	}

	else return a.length() < b.length();
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> a;

	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		a.push_back(x);
	}

	sort(a.begin(), a.end(), compare);
	a.erase(unique(a.begin(), a.end()), a.end());


	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << "\n";
	}
}