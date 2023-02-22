#include <iostream>
#include <vector>
using namespace std;


unsigned int fib(int n, unsigned int* mem){
    if (n<=2) return 1;
    if (mem[n]!=-1) return mem[n];

    mem[n] = fib(n-1,mem) + fib(n-2,mem);
    return mem[n];
}

int main ()
{
    int n; cin>>n;
    // unsigned int memo [n+1] ;
    // for (int i=0; i<n+1; i++){
    //     memo[i]=-1;
    // }
    unsigned long long int temp1=0,temp2=1, temp3;
    // unsigned int res = fib(n, memo);
    for (int i=0; i<=n; i++){
        if (i>1) {
            temp3 = temp1 +temp2;
            temp1 = temp2; 
            temp2 = temp3;
        }
    }

    // int res = fib(n, memo)%1000000000;
    // res = res% (1000000007);
    if (n<2){cout<<n;return 0;}
    unsigned long long int res = temp3 % (1000000007);
    cout<<res;

    return 0;
}


