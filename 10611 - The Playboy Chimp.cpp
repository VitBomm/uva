#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int n,q,e;
int main() {
    cin>>n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        cin>>e;
        v.push_back(e);
    }
    cin>>q;
    int temp;
    for(int i = 0; i < q; i++) {
        cin>>temp;
        vector<int>::iterator low, up;
        low = lower_bound(v.begin(), v.end(),temp);
        up = upper_bound(v.begin(),v.end(), temp);
        int best = (int)(up - v.begin());
        low  = low -1;
        int lowest = (int)(low-v.begin());
        if(lowest == n || lowest < 0)
        {
            cout<<"X "<<v[best]<<endl;
        }
        else if(best == n )
            {
                cout<<v[lowest]<<" X"<<endl;
            }
        else
            {
                cout<<v[lowest]<<" "<<v[best]<<endl;
            }
    }
    
    return 0;
    // 4 1 4 5 7 4 4 6 8 10
}
