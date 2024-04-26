#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;

const int INF = 1E9;

int main(){
    int n;
    cin >> n;
    
    vector<int> dist(n, INF);
    dist[0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int weight = (179*(i+1) + 719*(j+1)) % 1000 - 500;
            if (dist[j] > dist[i] + weight){
                dist[j] = dist[i] + weight;
            }
        }
    }

    cout << dist[n-1];

    return 0;
}