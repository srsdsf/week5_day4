//value ar poriman ta jehetu maximiaze korte hoba sehetu boro theke choto chrome sajate hoba
//q ber k create korte hola koita index porjonto highest jaite hoba
#include<bits/stdc++.h>
using namespace std;
//#define ll long long int
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        int a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        sort(a,a+n,greater<int>());
        vector<int>pref(n);
        pref[0]=a[0];

        for(int i=1; i<n; i++)
        {
            pref[i]=pref[i-1]+a[i];
        }


        while(q--)
        {
            int k;
            cin>>k;
            if(k>pref[n-1])
            {
                cout<<"-1"<<endl;
                continue;
            }
            int l = 0, r = n - 1, mid, idx = -1;
            while (l <= r) {
                mid = (l+r) / 2; 
                if ( pref[mid] >=k) {
                    idx = mid;
                    r=mid-1;
                }
                else {
                    l = mid + 1;
                }
            }
            cout<<idx+1;
        }
    }
}