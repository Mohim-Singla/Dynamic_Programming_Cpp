#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x="abcdghfrgthr";
    string y="abedfhfrg";
    cout<<"String a: "<<x<<endl<<"String b: "<<y<<endl;

    int mat[x.size()+1][y.size()+1];
    int ans=0;
    for (int i=0;i<=x.size();i++)
    {
        for (int j=0;j<=y.size();j++)
        {
            if (i==0 || j==0)
            {
                mat[i][j]=0;
                continue;
            }
            else
            {
                if (x[i-1]==y[j-1])
                {
                    mat[i][j]=1+mat[i-1][j-1];
                    ans=max(ans, mat[i][j]);
                }
                else
                {
                    mat[i][j]=0;
                }
            }

        }
    }
    cout<<"Length of longest common substring: "<<ans<<endl;
    cout<<"Tabular matrix: "<<endl;
    for (int i=0;i<=x.size();i++)
    {
        for (int j=0;j<=y.size();j++)
        {
            cout<<setw(6)<<mat[i][j]<<" ";

        }
        cout<<endl;
    }


}

