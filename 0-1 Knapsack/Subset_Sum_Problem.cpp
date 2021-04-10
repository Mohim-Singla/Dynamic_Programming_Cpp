#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=5;
    int arr[n]={2,3,7,8,10};
    int capacity=11;

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
    cout<<"Elements present are: ";
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Sum Required: "<<capacity<<endl;



    if (mat[n][capacity])
    {
        cout<<"Yes, Subset is present that sums up to the capacity."<<endl;
    }
    else
    {
        cout<<"No such Subset present."<<endl;
    }
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
