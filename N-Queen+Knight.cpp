#include<bits/stdc++.h>
using namespace std;
int n;
int ans=0;
vector<int>queen;
vector<pair<int,int>>knight;
vector<vector<pair<int,int>>>cross;

bool check(int row,int col,int kn){
    if(kn==-2)kn=0;
    if(kn==-1)kn=0;
    for(int i=kn;i<row;i++){
        for(auto v:cross[i]){
            if(v==make_pair(row,col))return 0;
        }
    }
    
    for(int prow=0;prow<row;prow++){
        int pcol=queen[prow];
        if(pcol==col || (abs(col-pcol) == abs(row-prow)))return 0;
    }return 1;
}


void rec(int level){
    if(level==n){
        ans++;
        return;
    }
    
    for(int col=0;col<n;col++){
        if(check(level,col,level-2)){
            queen.push_back(col);
            knight.push_back(make_pair(level+1,col+2));
            knight.push_back(make_pair(level+1,col-2));
            knight.push_back(make_pair(level+2,col+1));
            knight.push_back(make_pair(level+2,col-1));
            cross.push_back(knight);
            knight.clear();
            rec(level+1);
            queen.pop_back();
            
            cross.pop_back();
        }
    }
}

void solve(){
    cin>>n;
    rec(0);
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);//FASTIO
    
    //int _t;cin>>_t;while(_t--)  //to run solve() t no. of times where t is no. of testcases
    solve();
}