#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x="abcdgh";
    string y="abedfhr";
    cout<<"String a: "<<x<<endl<<"String b: "<<y<<endl;

    int mat[x.size()+1][y.size()+1];
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
                }
                else
                {
                    mat[i][j]=max(mat[i-1][j], mat[i][j-1]);
                }
            }
        }
    }

    string subseq;
    int i=x.size(), j=y.size();
    while(i!=0 && j!=0)
    {
        if (x[i-1]==y[j-1])
        {
            subseq.push_back(x[i-1]);
            //cout<<x[i-1];
            i--;
            j--;
        }
        else
        {
            if (mat[i-1][j]>mat[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(subseq.begin(), subseq.end());
    cout<<"Longest common subseq: "<<subseq;

}
    
