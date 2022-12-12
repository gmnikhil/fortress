#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

void inputVector(vector<int>& nums, int s) {
    int t;
    for (int i = 0; i < s; i++) {
        cin >> t;
        nums.push_back(t);
    }
}

string longestCommonSubsequence(string a, string b) {
    string r;

    int start_idx = -1;
    int end_idx = -1;

    unordered_map<int, string>count;

    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < b.length(); j++) {

            if (a[i] == b[j]) {
                if (start_idx == -1) start_idx = i;
                end_idx = i;
                i++;
            }
            else {
                if (start_idx >= 0) {
                    i = start_idx;
                    int len = end_idx - start_idx;
                    count[len] = a.substr(start_idx, len);
                    j = end_idx;
                    start_idx = -1;
                    end_idx = -1;
                }

            }
        }
    }
    cout << '1' << "\n";
    int s = 0;
    for (auto m : count) {
        cout << m.first << "\n";
        if (m.first > s);
        s = m.first;
    }

    r = count[s];

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;
    //cout << a << b;
    string r = longestCommonSubsequence(a, b);
    cout << r;

    return 0;
}