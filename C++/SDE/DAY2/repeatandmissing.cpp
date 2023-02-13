
vector<int> Solution::repeatedNumber( const vector<int> &A) {
    
    long int n=A.size(); 
    long int sum=0;
    long int a1=((n+1)*n);
    a1/=2;
    for(int i:A)sum+=i;
  //  cout<<n<<" "<<a1<<" "<<sum<<endl;
    
    
    long int a2=(n*(n+1)*(2*n+1))/6;
    long int sum2=0;
    for(long int i :A)sum2+=(i*i);
    
    //equation will be........
    //Sum(Actual) = Sum(1…N) + X - Y; x=missing and y=repeating 
    //X-Y=(a1-sum);
    int X=1,Y=2;
    long int  r1=a1-sum;
    long int  r2=a2-sum2;
    //cout<<r1<<" "<<r2;
    long long ans=r2/r1;
    
    X=(ans+r1)/2;
     Y=ans-X;
    return{Y,X};
}
