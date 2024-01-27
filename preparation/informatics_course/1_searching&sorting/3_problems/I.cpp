#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n, id, score;
    cin >> n;
    map<int, pair<int, int>> idScores{};
    for (int i = 0; i < n; i++){
        cin >> id >> score;
        idScores.insert({i, pair<int,int>{id, score}});
    }

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (idScores[j].second > idScores[j+1].second || (idScores[j].second == idScores[j+1].second && idScores[j].first <= idScores[j+1].first)){
                pair<int, int> temp = idScores[j];
                idScores[j] = idScores[j+1];
                idScores[j+1] = temp;
            }
        }
    }

    for (int i = n-1; i >= 0; i--) 
        cout << idScores[i].first << " " << idScores[i].second << endl;

    return 0;
}