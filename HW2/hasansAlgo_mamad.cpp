#include <iostream>
using namespace std;


long n, k;
long dp[100][100];
long nums[100];

long calsum(int, int);
void filldp(int, int);

int main(){
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> nums[i];
    }


    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j+i < k; j++)
        {
            filldp(j, i+j);
        }
    }

    cout<<dp[0][k-1];

    return 0;
}

void filldp(int i, int j){
    if( i == j){
        dp[i][j] = 0;
        return;
    }
    
    long min = INT64_MAX;
    for (int l = i; l < j; l++)
    {
        min =(dp[i][l] + dp[l+1][j] + calsum(i, j)) < min? (dp[i][l] + dp[l+1][j] + calsum(i, j)): min;
    }
    dp[i][j] = min;
}

// void getcost(int i, int j){
//     if( i == j){
//         cost += 0;
//         return;
//     }

//     int min = 2E9;
//     int L = -1;
//     for (int l = i; l < j; l++)
//     {
//         if((dp[i][l] + dp[l+1][j]) < min)
//         min = (dp[i][l] + dp[l+1][j]);
//         L = l;
//     }
//     cost += min;
//     getcost(i, L);
//     getcost(L+1, j);
// }

long calsum(int i, int j){
    long sum = 0;
    for (int l = i; l <= j; l++)
    {
        sum += nums[l];
    }
    return sum;
}

