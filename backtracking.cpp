#include<iostream>
#include<deque>
#include<unordered_map>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

void inputVector(vector<char>& v, int s) {
    char t;
    for (int i = 0; i < s; i++) {
        cin >> t;
        v.push_back(t);
    }
}

void inputString(vector<string>& v, int s) {
    string t;
    for (int i = 0; i < s; i++) {
        cin >> t;
        v.push_back(t);
    }
}

void recurse(deque<char>dq, unordered_map<char, int>visited) {
    deque<char>t = dq;
    if (t.empty()) cout << "\n";
    while (!t.empty()) {
        char x;
        do {
            x = t.front();
            t.pop_front();
        } while (visited[x] == 1 && !t.empty());

        if (visited[x] == 1 && t.empty()) continue;
        cout << x << " ";
        visited[x] = 1;
        recurse(dq, visited);
    }
}

void recurse(vector<char>v, vector<int>visited, string s) {
    if (s.length() == v.size()) cout << s << "\n";
    for (auto c : v) {
        int n = c;
        n -= 95;
        if (visited[n] == 1) continue;
        visited[n] = 1;
        recurse(v, visited, s + c);
        visited[n] = 0;
    }
}

void recurse(vector<string>v, vector<int>visited, string s, int l, unordered_set<string>& result) {
    if (s.length() == l) result.insert(s);
    int i = 0;
    for (string str : v) {
        if (visited[i++] == 1) continue;
        i--;
        visited[i] = 1;
        recurse(v, visited, s + str, l, result);
        visited[i] = 0;
        i++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string sx;
    cin >> sx;
    int n;
    cin >> n;
    //vector<char>v;
    //inputVector(v, n);

    vector<string>v;
    inputString(v, n);
    vector<int>visited(n + 1, 0);
    int sz = 0;
    for (string s : v) sz += s.length();

    unordered_set<string>result;
    vector<int>indices;
    recurse(v, visited, "", sz, result);

    for (string x : result) {
        int i, p = 0;
        while (1) {
            i = sx.find(x, p);
            if (i != std::string::npos) {
                indices.push_back(i);
                p = i + 1;
            }
            else break;
        }
    }

    for (auto x : indices) { cout << x << " "; }
    //recurse(v, visited, "");

    return 0;
}