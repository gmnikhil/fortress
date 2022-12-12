#include<iostream>
#include<unordered_map>

using namespace std;

enum Colors {
    RED, BLUE, GREEN,YELLOW
};

unordered_map<Colors, string>m = {
    {RED, "red"},
    {BLUE, "blue"},
    {GREEN, "green"}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cout<<RED<<" # "<<BLUE<<" # "<<GREEN<<"\n";
    cout<<m[RED]<<" # "<<m[BLUE]<<" # "<<m[GREEN];
    //cout<<"\n"<<m[YELLOW];
    cout<<"\n";
    if(m.find(YELLOW)!=m.end())
    cout<<"*";
    if(m.find(GREEN)!=m.end())
    cout<<"%";

    return 0;
}