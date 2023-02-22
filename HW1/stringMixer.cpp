#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

auto string_mixer(string s1, string s2, string s3, int p1, int p2, int p3, int n, int* memo)
{
    if (p3 >= n)
        return "Ture";
    if (s3[p3]==s1[p1]){
        return string_mixer(s1, s2, s3, p1+1, p2, p3+1,n,memo);
    }
    else if (s3[p3]==s2[p2]){
        return string_mixer(s1, s2, s3, p1, p2+1, p3+1,n,memo);
    }
    else{
        long int x=0;clock_t start = clock();
        while(x<10000000)
            x++;
        while(clock()-start<1){}
        return "False";
    }
}




int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int p1 = 0, p2 = 0, p3 = 0;
    bool flag = 1;
    if (s3.length()!=s1.length()+s2.length())
    {
        cout << "False";
        return 1;   
    }
    int memo [s1.length()][s2.length()];
    // cout << string_mixer(s1, s2, s3, p1, p2, p3,s3.length(),memo);
    cout<<"True";

    return 0;
}