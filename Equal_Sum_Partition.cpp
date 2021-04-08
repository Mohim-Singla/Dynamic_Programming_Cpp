#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=8;
    int arr[n]={2,3,4,5,6,7,8,9};
    int sum=0;
    sum=accumulate(arr, arr+n, sum);
    cout<<"List given: ";
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    if (sum%2!=0)
    {
        cout<<"Not possible.";
        exit(0);
    }
    int capacity=sum/2;
    bool mat[n+1][capacity+1];
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=capacity;j++)
        {
            if (i==0)
            {
                mat[i][j]=false;

            }
            else if (j==0)
            {
                mat[i][j]=true;

            }
            else
            {
                if (arr[i]<=j)
                {
                    mat[i][j] = mat[i][j-arr[i]] || mat[i-1][j];
                }
                else
                {
                    mat[i][j] = mat[i-1][j];
                }
            }

        }
    }

    if (mat[n][capacity])
    {
        cout<<"Yes, Equal sum partition is possible. sum of each subset= "<<capacity<<endl;
    }
}
