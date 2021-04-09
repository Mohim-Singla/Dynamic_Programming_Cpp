#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=4;
    int arr[n]={1,1,2,3};
    int difference=4;
    cout<<"Elements present are: ";
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"\nDifference Required: "<<difference<<endl;

    int sum_array=0;
    sum_array=accumulate(arr, arr+n, sum_array);
    if ((sum_array+difference)%2!=0)
    {
        cout<<"Number of ways of attaining this difference: 0"<<endl;
        exit(0);
    }
    if ((difference+sum_array)/2==0)
    {
        cout<<"Number of possible ways: 0."<<endl;
        exit(0);
    }
    int capacity=(difference+sum_array)/2;
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

    cout<<endl<<"Difference Required: "<<difference<<endl;

    cout<<"Number of ways: "<<mat[n][capacity]<<endl;
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
