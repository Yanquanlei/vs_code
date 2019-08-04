#include "iostream"
#include "string"
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        bool step_flag = false;
        string res;
        if(a.size()>b.size())
            b.insert(b.begin(), a.size()-b.size(), '0');
            else if (b.size()>a.size()) {
             a.insert(a.begin(), b.size()-a.size(), '0');
            }
        
        for(int )
            return res;
    }
};

int main()
{
    string a,b,c;
    cin>>a;
    cin>>b;
    Solution S;
    c = S.addBinary(a, b);
    cout << c;
    return 0;
}