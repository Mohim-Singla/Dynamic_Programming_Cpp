#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=8;
    int price[n] = {1,5,8,9,10,7,7,2};
    int length[n]={1,2,3,4,5,6,7,8};
    int capacity=8;

    cout<<"Given length and price are: ";
    for (int i=0;i<n;i++)
    {
        cout<<"("<<length[i]<<","<<price[i]<< ") ";
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
            if (length[i-1]>j || mat[i][j-length[i-1]]==0 && j-length[i-1]!=0)
            {
                mat[i][j]=mat[i-1][j];
            }
            else
            {
                mat[i][j]=max(price[i-1]+mat[i][j-length[i-1]], mat[i-1][j]);

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
