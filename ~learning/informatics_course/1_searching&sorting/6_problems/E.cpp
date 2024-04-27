#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct Post{
    int count;
    string title;
    int id;
};

int main() {
    int n;
    cin >> n;

    map<int, Post> messageMap;
    int maxCount = 0;
    for (int i = 1; i <= n; ++i) {
        int id;
        cin >> id;
        cin.ignore();
        if (id == 0) {
            string str, mes;
            getline(cin, str);
            getline(cin, mes);
            messageMap[i] = {0, str, 0};
        } else {
            string str;
            getline(cin, str);
            int temp = id;
            while (messageMap[temp].id != 0) {
                temp = messageMap[temp].id;
            }
            messageMap[temp].count += 1;
            maxCount = max(maxCount, messageMap[temp].count);
            messageMap[i] = {0, to_string(i), id};
        }
    }

    for (auto post : messageMap) {
        if (post.second.count == maxCount) {
            cout << post.second.title << endl;
            return 0;
        }
    }

    return 0;
}