#include"iostream"
#include"vector"
#include"map"
using namespace std;
 class Solution {
 public:

    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> datamap;

        for (int i = 0; i < numbers.size(); ++i) { 
            map<int,int>::iterator iter = datamap.find(target - numbers[i]);
            if(iter!=datamap.end()&&datamap[target-numbers[i]]!=i)
                return {++iter->second,++i};
            else {
                datamap[numbers[i]] = i;
            }
        }
        return {0, 0};
    }

};

int main()
{
    vector<int> input={0,4,3,0};
    int target=0;
    Solution s;
    cout<<s.twoSum(input,target)[0]<<" "<<s.twoSum(input,target)[1]<<endl;
    getchar();
    getchar();
    return 0; 
}