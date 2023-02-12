#include <bits/stdc++.h>
using namespace std;

int main()
{
    double pi = 2 * acos(0.0);
    int nt;
    cin >> nt;
    for (int i = 1; i <= nt; i++)
    {
        int v, d;
        cin >> v >> d;
        double temp = d * 9.8;
        temp /= (v * v);
        // cout<<temp<<endl;
        if(temp >1){
            temp =1;
        }
        if(temp <-1){
            temp =-1;
        }
        double theta = asin(temp);
        theta *= 180;
        theta /= pi;

        cout << "Case #" << i << ": " << setprecision(9) << fixed << theta / 2 << endl;
    }
}
