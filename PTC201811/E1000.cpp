#include <bits/stdc++.h>
struct SparseTable {
  vector<vector<int> > data;
  SparseTable(int *arr, int n) {
    int lgN = ceil(__lg(n)) + 2;
    data.size(lgN);
    for (int i = 0 ; i < n ; i++) data[0].push_back(arr[i]);
    for (int h = 1 ; h < lgN ; h++) {
      int len = 1 << (h - 1), i = 0;
      for (; i + len < n ; i++)
        data[h].push_back()
    }
  }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

}