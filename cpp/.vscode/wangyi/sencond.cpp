#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;
void swap(int a,int b,map<int,int> &maping,map<int,int> &r_maping)
{
    int temp_a;
    int temp_b;
    temp_a=maping[a];
    temp_b=maping[b];
    r_maping[temp_a] = maping[b];
    r_maping[temp_b] = maping[a];
    maping[a]=temp_b;
    maping[b]=temp_a;
}

int main(){

            int m;
            cin>>m ;
            map<int, int> maping;
            map<int, int> r_maping;
            vector<int> list(m);
            for (int j = 0; j < m;j++)
                cin >> list[j]; 
            for (int j = 0; j < m;j++)
                { maping[list[j]] = j;
                    r_maping[j] =list[j] ;}

            sort(list.begin(), list.end());
            stack<int> sin;
            stack<int> ou;
            for (int p = 0; p < m;p++)
            {
                if(list[m-1-p]%2!=0)
                sin.push(list[m-1-p]);
                else
                ou.push(list[m - 1 - p]);
            }

            int element=0;
            for (int k = 0; k < m; k++)
            {
                if(r_maping[k]%2!=0)
                {
                    if(!ou.empty())
                    {
                    element = ou.top();
                    ou.pop(); 
                    }
                    else
                        continue;
                }
                else
                {
                    if(!sin.empty())
                    {
                    element = sin.top();
                    sin.pop(); 
                    }
                    else
                        continue;
                }
                swap(element, r_maping[k], maping, r_maping);
            }            
                for (int k = 0; k < m; k++)
                cout << r_maping[k] << " ";
                cout << endl;

                cin >> m;
                return 0;
}