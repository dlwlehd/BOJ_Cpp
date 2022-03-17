#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, atk;

struct Dungeon {
	ll mode, attack, hp;
};

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

bool travel(ll maxHP, vector<Dungeon> room) {
	
	ll curHP = maxHP;
	ll curAtk = atk;
	for (int i = 0; i < n; i++) {
		if (room[i].mode == 1) {
			ll monHP = room[i].hp;
			ll monAtk = room[i].attack;
			ll x = monHP / curAtk;
			if (monHP % curAtk == 0) curHP -= (x - 1) * monAtk;
			else curHP -= x * monAtk;
			if (curHP <= 0) return false;
		} else {
			curAtk += room[i].attack;
			curHP += room[i].hp;
			if (curHP > maxHP) curHP = maxHP;
		}
	}
	
	return true;
}

int main() {
	input();
	cin >> n >> atk;
	vector<Dungeon> room(n);
	ll lo = 0, hi = 1e18;
	for (int i = 0; i < n; i++) {
		cin >> room[i].mode >> room[i].attack >> room[i].hp;
	}
	
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (travel(mid, room)) hi = mid;
		else lo = mid;
	}
	
	cout << hi;
}