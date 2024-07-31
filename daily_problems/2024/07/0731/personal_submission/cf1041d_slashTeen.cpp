#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, h;
    cin >> n >> h;
    vector<pair<int, int>> vec(n); // Guarantee: 升序且不相交
    for (auto& [l, r] : vec) {
        cin >> l >> r;
    }

    int start = vec[0].first, end = vec[0].second + h;
    int id = 0; // !
    for (int j = 1; j < n && end > vec[j].first; ++j) {
        id = j;
        end += vec[j].second - vec[j].first;
    }

    int ans = end - start;
    for (int i = 1; i < n; ++i) {
        start = vec[i].first;
        end += vec[i].first - vec[i - 1].second;
        for (int j = id + 1; j < n && end > vec[j].first; ++j) {
            id = j;
            end += vec[j].second - vec[j].first;
        }
        ans = max(ans, end - start);
        if (id == n - 1) {
            break;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
