#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f;
void func(ll i,vector<ll>adj[], ll color[], bool v[]){
    v[i]=true;
    ll j,l=adj[i].size();
    for(j=0;j<l;j++){
        if(v[adj[i][j]]==false){
            color[adj[i][j]]=1-color[i];
            func(adj[i][j],adj,color,v);
        }else{
            if(color[adj[i][j]]==color[i]){
                f=1;
                break;
            }
        }
    }
}
int main(){
    ll nt,i,k;
    cin>>nt;
    for(int j=1;j<=nt;j++){
        f=0;
        ll n;
        cin>>n;
        k=1;  //k is used to map string to int
        vector<ll>adj[2*n+1];
        unordered_map<string, ll>mp;
        string a[n],b[n];
        for(i=0;i<n;i++){
            cin>>a[i]>>b[i];
            if(mp.find(a[i])==mp.end()){
                mp[a[i]]=k;
                k++;
            }
            if(mp.find(b[i])==mp.end()){
                mp[b[i]]=k;
                k++;
            }
            adj[mp[a[i]]].push_back(mp[b[i]]);
            adj[mp[b[i]]].push_back(mp[a[i]]);
        }
        ll color[k];
        bool v[k];
        for(i=0;i<k;i++){
            v[i]=false;
            color[i]=-1;
        }
        for(i=1;i<k;i++){
            if(v[i]==false){
                color[i]=0;
                func(i,adj,color,v);
            }
            if(f>0)break;
        }
        cout<<"Case #"<<j<<": ";
        if(f==0){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
}
