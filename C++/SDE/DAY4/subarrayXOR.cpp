int Solution::solve(vector<int> &A, int B) {
    
    unordered_map<int,int>mp;
    
    int sum=0;
    int cnt=0;
    mp[0]=1;
    for(int i : A)
    {
        sum^=i;
        cnt+=mp[sum^B];
        mp[sum]++;    
    }
    return cnt;
}
