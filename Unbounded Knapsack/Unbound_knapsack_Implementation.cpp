#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=6;
    int val [n] = {2, 4, 5, 8, 9, 10};
    int weight[n]={1, 3, 4, 3, 2, 5};
    int capacity=10;

    cout<<"Given weights and values are: ";
    for (int i=0;i<n;i++)
    {
        cout<<"("<<weight[i]<<","<<val[i]<< ") ";
    }
    cout<<endl<<"Capacity: "<<capacity<<endl;

    int mat[n+1][capacity+1];

    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=capacity;j++)
        {
            if (i==0)
            {
                mat[i][j]=0;
            }
            else if (j==0)
            {
                mat[i][j]=0;
            }
            else{
            if (weight[i-1]<=j)
            {
                mat[i][j]=max(val[i-1]+mat[i][j-weight[i-1]], mat[i-1][j]);
            }
            else
            {
                mat[i][j]=mat[i-1][j];
            }
            }
        }
    }
    cout<<"Max value: "<<mat[n][capacity]<<endl<<"Matrix Formed: "<<endl;
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=capacity;j++)
        {
            cout<<setw(8)<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
