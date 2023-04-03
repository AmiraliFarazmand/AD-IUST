#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int W, n;
    cin >> W >> n;

    int valary[n], weiary[n];
    for(int i = 0; i < n; i++)
    {
        cin >> valary[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> weiary[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if((double)valary[j]/(double)weiary[j] < (double)valary[j+1]/(double)weiary[j+1])
            {
                double temp_val = valary[j];
                valary[j] = valary[j+1];
                valary[j+1] = temp_val;

                double temp_wei = weiary[j];
                weiary[j] = weiary[j+1];
                weiary[j+1] = temp_wei;
            }
        }
    }

    double maxval = 0.0;
    for(int i = 0; i < n; i++)
    {
        if(weiary[i] <= W)
        {
            W -= weiary[i];
            maxval += valary[i];
        }
        else
        {
            maxval += valary[i] * ((double)W / (double)weiary[i]);
            break;
        }
    }

    cout << fixed << setprecision(2) << maxval << endl;

    return 0;
}
