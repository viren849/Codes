#include <bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back


int dp[100001][101];
vector<vector<int>>ans;

bool func(int t,vector<int>&arr,int n)
{
 if(t < 0)return 0;
  if(n < 0)
  {
    if(t == 0)return 1;
    return 0;
  }

  if(dp[t][n]!=-1)
    return dp[t][n];

  bool nt=func(t,arr,n-1);
  bool tk=func(t-arr[n],arr,n-1);

  return dp[t][n]=nt|tk;
}

void printans(int t,vector<int>&arr,int n,vector<int>&tmp)
{
  if(n < 0)
  {
    reverse(tmp.begin(),tmp.end());
    ans.pb(tmp);
    return ;
  }
 
      if(func(t,arr,n-1)) // not take
        printans(t,arr,n-1,tmp);
      else if(func(t-arr[n],arr,n-1))
      {
        tmp.pb(n);
        printans(t-arr[n],arr,n-1,tmp);
      }
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    
    memset(dp,-1,sizeof(dp));
    
    int n=arr.size();

    for(auto q : queries)
    {
        vector<int>tmp;
          if(func(q,arr,n-1))
            printans(q,arr,n-1,tmp);
          else 
             ans.pb({-1});
    }
   
   return ans;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}