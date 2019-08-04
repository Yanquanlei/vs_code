#include "iostream"
#include "string"
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     string addBinary(string a, string b) {
//         bool step_flag = false;
//         if(a.size()>b.size())
//             b.insert(b.begin(), a.size()-b.size(), '0');
//         else if (b.size()>a.size()) {
//             a.insert(a.begin(), b.size()-a.size(), '0');
//             }

//             string res;
//             for (int i = a.size()-1; i>=0; i--)
//                 if (!step_flag)
//                 {
//                     if (a[i] == '1' && b[i] == '1')
//                     {
//                         res += '0';
//                         step_flag = true;
//                     }
//                     else if (a[i] == '0' && b[i] == '0')
//                         res += '0';
//                     else
//                         res += '1';
//                 }
//                 else
//                 {
//                     step_flag = false;
//                     if (a[i] == '1' && b[i] == '1')
//                     {
//                         res += '1';
//                         step_flag = true;
//                     }
//                     else if (a[i] == '0' && b[i] == '0')
//                         res+= '1';
//                     else
//                     {
//                         res += '0';
//                         step_flag = true;
//                     }
//                 }               
//             if (step_flag)
//                 res += '1';
//             reverse(res.begin(), res.end());
//             return res;
//     }
// };

class Solution {
public:
    string addBinary(string a, string b) {
        string s(max(a.size(),b.size())+1,'0');
        int al=a.size();
        int bl=b.size();
        int num=0;
        for(int i=s.size();al||bl||num;num>>=1)
        {
            if(al)
               num+=a[--al]-'0';
            if(bl)
                num+=b[--bl]-'0';
            s[--i]=(num&1)+'0';
        }
        if(s[0]=='0')
            s.erase(0,1);
        return s;               
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