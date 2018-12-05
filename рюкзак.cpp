#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <iterator>
using namespace std;
int rukzak(const vector<int>& weight, const vector<int>& cost, int W);
int main(){
    int W,n;
    cin >> W >> n;
    vector<int>cost(n);
    vector<int>weight(n);
        for (int i=0;i<n;i++){
            cin>>cost[i];
            cin>>weight[i];
        }
    int vivod=rukzak(weight,cost,W);
    cout << vivod;
    return 0;
}

int rukzak(const vector<int>& weight, const vector<int>& cost, int W)
{
    int n = weight.size();
    vector< vector<int> >dp(W+1,vector<int>(n+1,0));
    for (int j=1;j<=n;j++)
    {
        for (int w=1;w<=W;w++)
        {
            if (weight[j-1]<=w)
            {
                dp[w][j]=max(dp[w][j-1], dp[w-weight[j-1]][j-1]+cost[j-1]);
            }
            else
            {
                dp[w][j]=dp[w][j-1];
            }
        }
    }
    return dp[W][n];
}
