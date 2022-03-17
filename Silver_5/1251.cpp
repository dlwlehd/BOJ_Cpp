#include <bits/stdc++.h>
using namespace std;

string s;

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
}

int main(void) {

	input();
    cin >> s;

    string sub_a = s.substr(0,1);
    string sub_b = s.substr(1,1);
    string sub_c = s.substr(2);
    reverse(sub_a.begin(),sub_a.end());
    reverse(sub_b.begin(),sub_b.end());
    reverse(sub_c.begin(),sub_c.end());

    string x = sub_a + sub_b + sub_c;

    for (int a = 1; a <= s.length() - 2; a++) {
        for (int b = 1; b <= s.length() - 1 - a; b++) {

            string sub_a = s.substr(0,a);
            string sub_b = s.substr(a,b);
            string sub_c = s.substr(a+b);
            
            reverse(sub_a.begin(),sub_a.end());
            reverse(sub_b.begin(),sub_b.end());
            reverse(sub_c.begin(),sub_c.end());

            string t = sub_a + sub_b + sub_c;
            if (t < x) {
                x = t;
            }
        }
    }
    
    cout << x;
}