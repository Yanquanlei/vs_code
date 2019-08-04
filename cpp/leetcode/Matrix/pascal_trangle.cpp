#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> trangle(numRows, vector<int>());
        for(int i=1;i<=numRows;i++)
           { 
               trangle[i-1].resize(i);
               *trangle[i-1].begin()=1;
               trangle[i-1].back()=1;
           }
        
        if(numRows>2)
           {
               for (int i = 2; i < numRows;i++)
                   for (int j = 1; j < trangle[i].size()-1;j++)
                       trangle[i][j] = trangle[i - 1][j - 1] + trangle[i - 1][j];
           }

               return trangle;
    }
};

int main()
{
    int num;
    cin >> num;
    Solution S;
    vector<vector<int>> res = S.generate(num);
    for (int i = 0; i < res.size();i++)
        {for (int j = 0; j < res[i].size();j++)
            cout<<res[i][j]<<" ";
            cout << endl;
        }
        system("pause");
        return 0;
}


