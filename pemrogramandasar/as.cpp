#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int main() {
    cin >> s;
    bool is_camel = true;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '_') {
            is_camel = false; break;
        } else if(isupper(s[i])) {
            is_camel = true; break;
        }
    }
    if(is_camel) {
        for(int i = 0; i < s.size(); i++) {
            if(isupper(s[i])) {
                string rep = "_";
                rep.push_back(tolower(s[i]));
                s.replace(i, 1, rep);
                i++;
            }
        }
    } else {
        for(int i = 1; i < s.size(); i++) {
            if(s[i-1] == '_') {
                string rep = "";
                rep.push_back(toupper(s[i]));
                s.replace(i-1, 2, rep);
                i--;
            }
        }
    }
    cout << s;
}
