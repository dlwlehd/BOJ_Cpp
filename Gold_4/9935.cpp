#include <bits/stdc++.h>
using namespace std;

string text, bomb;
vector <char> result;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main() {
	input();
	cin >> text >> bomb;

	for (int i = 0; i < text.size(); i++) {
		result.push_back(text[i]);

		if (result.size() < bomb.size()) continue;
		if (result[result.size() - 1] == bomb[bomb.size() - 1]) {
			bool check = true;
			for (int j = 2; j <= bomb.size(); j++)
				if (result[result.size() - j] != bomb[bomb.size() - j])
					check = false;
			if (check)
				result.erase(result.end() - bomb.size(), result.end());
		}
	}

	if (result.size() == 0) cout << "FRULA";
	else
		for (int i = 0; i < result.size(); i++)
			cout << result[i];
	return 0;
}