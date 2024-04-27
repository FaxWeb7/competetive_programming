#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

const int INF = 1E9;

void printPath(vector<pair<int, int>> &from, int finish){
    vi path;
    for (int v = finish; v != -1; v = from[v].first){
        path.push_back(from[v].second);
    }
    reverse(path.begin(), path.end());
    for (auto i : path) cout << i;
}

int bfs(vi &nums, int x, int k) {
    vi dist(k, INF);
    vector<pair<int, int>> from(k, {-1, -1});
    queue<int> q;

    for (ll &num : nums){
        ll v = (10 * x + num) % k;
        if (dist[v] > 0){
            dist[v] = 0;
            from[v] = {-1, (10 * x + num)};
            q.push(v);
        }
    }

    while (!q.empty()){
        ll v = q.front();
        q.pop();

        if (v == 0) {
            printPath(from, v);
            return 1;
        }

        for (ll &num : nums){
            int to = (10 * v + num) % k;
            if (dist[to] > dist[v] + 1){
                dist[to] = dist[v] + 1;
                from[to] = {v, num};
                q.push(to);
            }
        }
    }

    return 0;
}

int main(){
    ll x, k, n;
    cin >> x >> k >> n;
    vi nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    if (x % k == 0) {
        cout << x;
        return 0;
    }

    if (!bfs(nums, x, k)) cout << -1;

    return 0;
}
