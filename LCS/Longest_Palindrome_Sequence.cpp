#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x="fdabcdgaahcbadf";
    string y=x;
    reverse(y.begin(),y.end());
    cout<<"String : "<<x<<endl;

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
    cout<<"\n\nLength of longest Palindrome: "<<mat[x.size()][y.size()]<<endl;
    int i=x.size();
    int j=i;
    string p;
    while(i!=0 || j!=0)
    {
        if (x[i-1]==y[j-1])
        {
            p.push_back(x[i-1]);
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

    cout<<"Longest palindrome in abobe string : "<<p<<endl<<endl;
}
