#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=6;
    int arr[n]={1,2,3,7,8,10};
    int capacity=11;

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
                mat[i][j]=1;

            }
            else
            {
                if (arr[i]<=j)
                {
                    mat[i][j] = mat[i][j-arr[i]] + mat[i-1][j];
                }
                else
                {
                    mat[i][j] = mat[i-1][j];
                }
            }

        }
    }
    cout<<"Elements present are: ";
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Sum Required: "<<capacity<<endl;

    cout<<"Number of Possible subsets: ";
    cout<<mat[n][capacity]<<endl;
    cout<< "Top-down matrix: "<<endl;
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=capacity;j++)
        {
            cout<<setw(8)<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
