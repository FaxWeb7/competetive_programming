//FIXME: решение через КМП (chatGPT)
// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> getP(string &t){
//     int n = t.size();

//     vector<int> p(n);
//     p[0] = 0;
//     int j = 0, i = 1;
//     while (i < n){
//         if (t[i] == t[j]){
//             p[i] = j+1;
//             i++, j++;
//         } else {
//             if (j != 0){
//                 j = p[j-1];
//             } else {
//                 p[i] = 0;
//                 i++;
//             }
//         }
//     }
    
//     return p;
// }

// void sol(string &s, string& t){
//     int n = s.size(), m = t.size();
//     vector<int> p = getP(t);
//     int i = 0, j = 0;
//     while (i < n){
//         if (s[i] == t[j]){
//             i++, j++;
//             if (j == m){
//                 cout << i - j << ' ';
//                 j = p[j-1];
//             }
//         } else {
//             if (j != 0) {
//                 j = p[j-1];
//             } else {
//                 i++;
//             }
//         }
//     }
// }

// int main(){
//     string s, t;
//     cin >> s >> t;

//     sol(s, t);

//     return 0;
// }


//FIXME: решение через Z-функцию
// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// vector<int> z_function(string s) {
//     int n = s.size();
//     vector<int> z(n);
//     z[0] = n;
//     int l = 0, r = 0;

//     for (int i = 1; i < n; i++) {
//         if (i <= r)
//             z[i] = min(r - i + 1, z[i - l]);
//         while (i + z[i] < n && s[z[i]] == s[i + z[i]])
//             z[i]++;
//         if (i + z[i] - 1 > r) {
//             r = i + z[i] - 1;
//             l = i;
//         }
//     }

//     return z;
// }

// int main(){
//     string text, pattern;
//     cin >> text >> pattern;

//     string merged = pattern + '&' + text;
//     vector<int> zAll = z_function(merged);

//     for (int i = 0; i <= merged.size(); ++i){
//         if (zAll[i] == pattern.size()) cout << i-pattern.size()-1 << ' ';
//     }

//     return 0;
// }

//FIXME: решение через префикс-функцию 
#include <iostream>
#include <vector>

using namespace std;

vector<int> getP(const string& s) {
    int n = s.size();
    vector<int> p(n);

    for (int i = 1; i < n; ++i){
        int cur = p[i - 1];
        while (s[i] != s[cur] && cur > 0){
            cur = p[cur - 1];
        }

        if (s[i] == s[cur]){
            p[i] = cur + 1;
        }
    }
}

int main(){
    string text, pattern;
    cin >> text >> pattern;

    string merged = pattern + '&' + text;
    vector<int> p = getP(merged);

    for (int i = 0; i < merged.size(); ++i){
        if (p[i] == pattern.size()){
            cout << i - pattern.size()*2 << ' ';
        }
    }

    return 0;
}