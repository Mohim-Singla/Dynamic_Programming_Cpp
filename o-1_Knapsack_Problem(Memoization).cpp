// Memoization Technique
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mat[100][100];

void memset()
{
    for (int i=0;i<100;i++)
    {
        for (int j=0;j<100;j++)
        {
            mat[i][j]=-1;
        }

    }
}
int knapsack(int val[], int wt[], int capacity, int n)
{
    if (n==0 || capacity==0)
    {
        return 0;
    }

    if (mat[n-1][capacity-1]!=-1)
    {
        return mat[n-1][capacity-1];
    }

    if (wt[n-1]<=capacity)
    {
        return mat[n-1][capacity-1]=max(val[n-1]+knapsack(val, wt, capacity-wt[n-1], n-1), knapsack(val, wt, capacity, n-1));
    }
    else
    {
        return mat[n-1][capacity-1]=knapsack(val, wt, capacity, n-1);
    }

}

int main()
{
    int val[7]={10,4,5,7,8,9,10};
    int wt[7]={1,3,4,1,3,2,5};
    int capacity=10;
    memset();

    cout<<"Given weights and values are: ";
    for (int i=0;i<7;i++)
    {
        cout<<"("<<wt[i]<<","<<val[i]<< ") ";
    }
    cout<<endl<<"Capacity: "<<capacity<<endl;


    cout<<"Maximum Value that can be generated putting chunk of weight into the bag in range of it's capacity: ";
    int ans=knapsack(val, wt, capacity, 7);
    cout<<ans<<endl;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            cout<<setw(10)<<mat[i][j]<<" ";
        }
        cout<<endl;

    }


}
