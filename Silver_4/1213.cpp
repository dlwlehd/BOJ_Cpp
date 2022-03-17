#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main() {
    input();
    string a;
    cin >> a;
    int al[26] = {0};
    for (char i: a) {
        al[i - 'A']++;
    }
    int x = 0;
    int idx = -1;
    for (int i = 0; i < 26; i++) {
        if (al[i] % 2 == 1) {
            x++;
            idx = i;
        }
    }
    if (x > 1) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    string odd = "";
    if (x == 1) {
        odd += (char) idx + 'A';
    }
    al[idx]--;
    string temp = "";
    for (int i = 0; i < 26; i++) {
        if (!al[i]) continue;
        int t = al[i] / 2;
        for (int j = 0; j < t; j++) {
            temp += (char) i + 'A';
        }
    }

    string res = "";
    res += temp;
    res += odd;
    reverse(temp.begin(), temp.end());
    res += temp;
    cout << res;
}