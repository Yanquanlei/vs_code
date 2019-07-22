#include"iostream"
#include"vector"
#include"map"
#include"stack"
#include"algorithm"
using namespace std;

class Solution {
public:
void twoSum(vector<int> &numbers, int target,int begin_pos,int end_pos,vector<vector<int> > &res) 
    {
         map<int,int> datamap;
        vector<int> numbers_temp = numbers;
            numbers_temp.erase(numbers_temp.begin(), numbers_temp.begin() + begin_pos );
        numbers_temp.erase(numbers_temp.end()-numbers.size()+end_pos+1, numbers_temp.end());
        
        for (int i = 0; i < numbers_temp.size(); ++i) { 
            map<int,int>::iterator iter = datamap.find(target - numbers_temp[i]);
            if(iter!=datamap.end())
              {  res.push_back({-target,iter->first,numbers_temp[i]});
               break;
              }
              else 
              {
                datamap[numbers_temp[i]] = i;
              }
        }     
               // res.push_back({3, 2, 1});
    }

    vector<vector<int> > threeSum(vector<int> &num) 
    {
        vector<vector<int>> res;
         sort(num.begin(),num.end());
         int left = 0, right = num.size() - 1,target; //从两端往中间移动；

        for (int i = 0; i < num.size() - 1;i++)
        {
            target = -num[i];
            left = i + 1;
            right = num.size()-1;
            twoSum(num,target,left,right,res);                        
        }
         sort(res.begin(), res.end());
         res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
    

    
};



int main()
{
    vector<int> input={-1,0,1,2,-1,-2};
    Solution s;
    vector <vector<int>> result_vec = s.threeSum(input);
      for (int i = 0; i < result_vec.size(); i++)
    {
        for (int j = 0; j < result_vec[i].size(); j++)
          cout << result_vec[i][j] <<' ';
        cout << endl;
    }
    system("pause");
    return 0; 
}