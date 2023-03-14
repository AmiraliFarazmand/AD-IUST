#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define NUM 35
using namespace std;
int coins[] = {25, 5, 10}, sum = 30;

int numberofCoins = 3;
// Function to initialize 1st column of dynamicprogTable with 1

void initdynamicprogTable(vector<vector<int>> dynamicprogTable)

{

    int i;

    // First row to 0

    for (i = 1; i <= sum + 1; i++)
    {

        dynamicprogTable[0][i] = 0;
    }

    // First column to 1

    for (i = 1; i <= numberofCoins; i++)
    {

        dynamicprogTable[i][0] = 1;
    }
}

int solution(vector<vector<int>> dynamicprogTable)
{

    int coinindex, dynamicprogSum;

    for (coinindex = 1; coinindex < numberofCoins + 1; coinindex++)
    {

        for (dynamicprogSum = 1; dynamicprogSum <= sum ; dynamicprogSum++)
        {

            // value of coin should be less than or equal to sum value to consider it

            if (coins[coinindex - 1] > dynamicprogSum)
{
                dynamicprogTable[coinindex][dynamicprogSum] = dynamicprogTable[coinindex - 1][dynamicprogSum];
                cout<<"\nFilled dynamicprogTable["<<coinindex<<"]["<<dynamicprogSum<<"] = "<<dynamicprogTable[coinindex - 1][dynamicprogSum]; 
            
}
            else{


                dynamicprogTable[coinindex][dynamicprogSum] = dynamicprogTable[coinindex - 1][dynamicprogSum] + dynamicprogTable[coinindex][dynamicprogSum - coins[coinindex - 1]];
            cout<<"\nFilled dynamicprogTable["<<coinindex<<"]["<<dynamicprogSum<<"] = "<<dynamicprogTable[coinindex - 1][dynamicprogSum] 
                <<" + "<< dynamicprogTable[coinindex][dynamicprogSum - coins[coinindex - 1]]; 
            }
        }
    }
    cout << endl;
    for (int i = 0; i <= sum; i++)
        cout << setfill('0') << setw(2) << i << " I ";
    cout << endl;
    // cout<<"\n"<<"--------------------------------------------------------------------------------------------------------------------------------------------------" <<endl;
    for (int i = 1; i <= numberofCoins; i++)
    {
        for (int j = 0; j <= sum; j++)
            cout << setfill('0') << setw(2) << dynamicprogTable[i][j] << " | ";
        cout << endl;
    }
    // return final row and column value

    return dynamicprogTable[numberofCoins][sum];
}

int main()

{
    vector<vector<int>> dynamicprogTable(numberofCoins + 1, vector<int>(NUM));
    //  int dynamicprogTable[numberofCoins + 1][NUM];
    for (int i = 1; i <= sum + 1; i++)
    {

        dynamicprogTable[0][i] = 0;
    }

    // First column to 1

    for (int i = 1; i <= numberofCoins; i++)
    {

        dynamicprogTable[i][0] = 1;
    }
    // initdynamicprogTable(dynamicprogTable);

    printf("Total Solutions: %d", solution(dynamicprogTable));

    return 0;
}

/*
   for (int i = 1; i <= numberofCoins; i++)
    {
        for (int j = 0; j <= NUM; j++)
            cout << setfill('0') << setw(2) << dynamicprogTable[i][j] << " | ";
        cout << endl;
    }

*/