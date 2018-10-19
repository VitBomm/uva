#include <iostream>
#include <vector>
using namespace std;
int q,n,r;
int caseex = 0;
int main ()
{
    cin>>q;
    while(q--)
    {
        caseex++;
        cin>>n;
        vector<int> v;
        v = vector<int>();
        for(int i = 0 ; i<n;i++)
        {
            cin>>r;
            v.push_back(r);
        }
        int k = 0,temp;
        for(int i = 0; i<n;i++)
        {
            if(v[i]-v[i-1] >k)
            {
                k = v[i]- v[i-1];
            }
        }
        temp = k;
        for(int i = 0; i<n;i++)
        {
            if(v[i]-v[i-1] == k)
            {
                k--;
            }
            else if(v[i]-v[i-1] >k)
            {
                temp++;
                break;
            }
        }
        cout<<"Case "<<caseex<<": "<<temp<<endl;
    }
}
// 2 5 1 6 7 11 13 4 3 9 10 14
// 3 1 1 1 100000 2 1 1000000
