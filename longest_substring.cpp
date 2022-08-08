#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;

//traverse the string
//if map[char] 
    //while q.front() not char q.pop()
    //q.pop() 
//set map[char] as 1
//add char to q
//return q.length

int lengthOfLongestSubstringWithoutRepeatingCharacters(string s) {
    queue<int>q;
    unordered_map<int, bool>m;
    int length = 0;

    for (char c : s) {
        if (m[c]) {
            length = q.size() > length ? q.size() : length;
            while (q.front() != c) {
                m[q.front()] = false;
                q.pop();
            }
            q.pop();
        }
        else m[c] = true;

        q.push(c);
    }

    length = q.size() > length ? q.size() : length;

    return length;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    int l = lengthOfLongestSubstringWithoutRepeatingCharacters(s);
    cout << "Length is: " << l;

    return 0;
}