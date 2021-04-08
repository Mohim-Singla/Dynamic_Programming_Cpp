#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=7;
    int val[n]={10,4,5,7,8,9,10};
    int wt[n]= {1 ,3,4,1,3,2, 5};
    int capacity=10;

    cout<<"Given weights and values are: ";
    for (int i=0;i<7;i++)
    {
        cout<<"("<<wt[i]<<","<<val[i]<< ") ";
    }
    cout<<endl<<"Capacity: "<<capacity<<endl;


    cout<<"Maximum Value that can be generated putting chunk of weight into the bag in range of it's capacity: ";
    int mat[n+1][capacity+1];

    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=capacity;j++)
        {
            if (i==0||j==0)
            {
                mat[i][j]=0;
                continue;
            }
            else if (wt[i-1]<=j)
            {
                mat[i][j]=max((val[i-1]+mat[i-1][j-wt[i-1]]), mat[i-1][j]);
            }
            else
            {
                mat[i][j]=mat[i-1][j];
            }
        }
    }
    cout<<mat[n][capacity]<<endl;
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=capacity;j++)
        {
            cout<<setw(8)<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}
