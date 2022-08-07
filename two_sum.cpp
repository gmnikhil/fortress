 #include<iostream>
 #include<vector>
 #include<unordered_map>
 using namespace std;

 vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int>m;
    vector<int>res;
    for(int i=0; i<nums.size(); i++) {
        int t = target - nums[i];
        
        if(m.find(t) != m.end() ) {
            res.push_back(m[t]);
            res.push_back(i);
            return res;
        }
        m[nums[i]] = i;
        
    }
    return res;
}

void inputVector(vector<int> &nums, int s) {
    int t;
    for(int i=0; i<s; i++) {
        cin>>t;
        nums.push_back(t);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    vector<int>v;
    
    inputVector(v, n);
    
    int target;
    cin>>target;
    vector<int> ans = twoSum(v, target);
    for(auto x:ans){
        cout<<x<<" ";
    }
    
    return 0;
}