#include"iostream"
#include"vector"
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        for( int  i=0;i<numbers.size();i++)
           for( int  j=i+1;j<numbers.size();j++)
                {
                if(numbers[i]+numbers[j]==target)
                    return {++i,++j};
                }
      return {0,1}; 
    }
};

int main()
{
    vector<int> input={2,7,11,15};
    int target=26;
    Solution s;
    cout<<s.twoSum(input,target)[0]<<" "<<s.twoSum(input,target)[1]<<endl;

}