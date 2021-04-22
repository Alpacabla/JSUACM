#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long int ll;
const int max_n=2e6+5;
bool vis1[max_n],vis2[max_n];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("adjustment.in", "r", stdin);
    freopen("adjustment.out", "w", stdout);
    ll n,q;
    cin>>n>>q;
    ll cnt1=n,cnt2=n;
    ll sum=(1ll+n)*n/2;
    ll del1=0,del2=0;
    while(q--){
        string s;
        ll a;
        cin>>s>>a;
        if(s=="R"){
            if(vis1[a]){
                cout<<0<<'\n';
            }else{
                vis1[a]=true;
                cnt1--;
                del1+=a;
                cout<<sum+cnt2*a-del2<<'\n';
            }
        }else{
            if(vis2[a]){
                cout<<0<<'\n';
            }else{
                vis2[a]=true;
                cnt2--;
                del2+=a;
                cout<<sum+cnt1*a-del1<<'\n';
            }
        }
    }
 	cout<<endl;
    return 0;
}