#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1]) return false;

    }
    return true;
}

// Not Optimal
string longestPalindromicSubstring(string s) {
    string ans = s.substr(0, 1);
    for (int i = 0; i < s.length(); i++) {
        for (int j = ans.length() + 1; j <= s.length() - i; j++) {
            string t = s.substr(i, j);
            if (isPalindrome(t)) {
                ans = t;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;

    getline(cin, s);

    cout << longestPalindromicSubstring(s);

    return 0;
}