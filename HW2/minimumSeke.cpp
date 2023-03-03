#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
// lolint memo[1001][1001];
typedef vector<vector<lolint>> Matrix;

vector <int> coins(12, 0);
vector <int> nums(100000, 0);
int find_min(int num){
    if(nums[num]!=0){
        return 0;
    }
}



int main(){
int n,v, len=0;
cin >> n >> v;
for (int i = 0; i <n;cin>>coins[i])
    len++;
sort(coins.begin(),coins.end());

find_min(v);

}