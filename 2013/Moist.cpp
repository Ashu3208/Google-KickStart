#include<bits/stdc++.h>
using namespace std;
void swap(char &a,char &b){
    char c=a;
    a=b;
    b=c;
}
int main(){
    int nt;
    cin>>nt;
    for(int k=1;k<=nt;k++){
        int n;
        cin>>n;
        string a[n];
        cin.ignore();
        for(int i=0;i<n;i++){getline(cin,a[i]);}
        int cnt=0;
        for(int i=1;i<n;i++){
            int l=i;
            if(a[i]<a[i-1]){
                cnt++;
            }
            while(l>0){
                if(a[l]<a[l-1])swap(a[l],a[l-1]);
                else break;
            }
        }
        cout<<"Case #"<<k<<": "<<cnt<<endl;
    }
    return 0;
}
