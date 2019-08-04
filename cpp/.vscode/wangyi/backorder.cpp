#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> input(n);
    for(int i = 0; i < n; i++){
           cin >> input[i];
        }
        vector<int> sort_list = input;
        sort(sort_list.begin(),sort_list.end());
        map<int, int> maping;
        for (int i = 0; i < n;i++)
            maping[sort_list[i]] = sort_list[n - i - 1];
    vector<int> output(n);    
        for (int i = 0; i < n;i++)
            {
                output[i] = maping[input[i]];
                cout << output[i] << " ";
            }
            cout << endl;
            system("pasuse");
            return 0;
}