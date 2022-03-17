#include <iostream>
using namespace std;
int n, m;
int board[32][32];
int res = 0;
bool vis[32];

void func (int idx) {
   if (idx == 3) {
      int tot = 0;
      for (int i = 0; i < n; i++) {
         int mx = 0;
         for (int j = 0; j < m; j++) {
            if (vis[j]) mx = max(mx,board[i][j]);
         }
         tot += mx;
      }
      res = max(res,tot);
      return;
   }

   for (int i = 0; i < m; i++) {
      if (vis[i]) continue;
      vis[i] = 1;
      func(idx+1);
      vis[i] = 0;
   }
}

int main(void)
{
   ios::sync_with_stdio(0);
   cin.tie(0);

   freopen("input.txt", "r", stdin);
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> board[i][j];
      }
   }

   func(0);
   cout << res;
}