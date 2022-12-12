#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

// https://leetcode.com/problems/longest-increasing-subsequence/

int lengthOfLongestIncreasingSubsequence(vector<int> nums) {
    int length = 0;
    vector<int>sorted = nums;

    sort(sorted.begin(), sorted.end());

    queue<int>q, t;

    for (int x : sorted) {
        if (q.front() != x)
            q.push(x);
    }
    t = q;

    int p = 0;
    while (!q.empty()) {

        for (int i = p; i < nums.size(); i++) {
            if (q.front() == nums[i]) {
                cout << q.front() << "#\n";
                length++;
                p = i + 1;
                q.pop();
            }
        }
        if (!q.empty()) q.pop();
    }
    return length;
}



// for (int s : sorted) {
//     //if (nums.size() - p1 < length) break;
//     int l = 0;
//     int p2 = 0;
//     for (int num : nums) {
//         p2++;
//         //if (nums.size() - p2 + l < length) break;
//         if (s == num)  l++;
//     }
//     length = l > length ? l : length;
//     cout << length << "\n";
// }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    vector<int>v;
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        v.push_back(t);
    }
    // for (int x : v) {
    //     cout << x;
    // }
    int l = lengthOfLongestIncreasingSubsequence(v);
    cout << "Length is: " << l;

    return 0;
}