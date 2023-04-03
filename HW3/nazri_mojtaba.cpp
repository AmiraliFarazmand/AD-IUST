
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int m = 0;
    cin >> m;

    int n = 0;
    cin >> n;
    if(n==0)
    {
        cout << 0;
        return 0;
    }
    int ary[n];
    for(int i=0; i<n ;i++)
    {
        cin >> ary[i];
    }

    int counter = 0;
    int finish = 0;

    int max=*max_element(ary , ary + n);
    if(n>m+1)
    {
        finish = n-1;
    }
    else
    {
        finish=m;
    }
    counter = ((max-1)*(finish+1));
    int constvalue = 0;
    for(int i=0; i<n ;i++)
    {
        if(max == ary[i])
        {
            counter++;
        }
        if(i >= m+1)
        {
            constvalue = (((max-1)-ary[i-1])+constvalue);
        }
    }
    cout << counter-constvalue << endl;

    return 0;
}