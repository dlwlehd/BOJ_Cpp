#include <iostream>
#include <list>

using namespace std;


int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {

        list<char> L = {};
        string s;
        cin >> s;
        auto cursor = L.end();

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '<') {
                if (cursor != L.begin()) cursor--;
            }
            else if (s[i] == '>') {
                if (cursor != L.end()) cursor++;
            }
            else if (s[i] == '-') {
                if (cursor != L.begin()) {
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else {
                L.insert(cursor, s[i]);
            }
        }
        for (auto c : L) cout << c;
        cout << "\n";
    }
}