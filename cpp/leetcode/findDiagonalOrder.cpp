#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int> output;
        bool direction=false;   //false means count from down to up       
		int M = matrix.size(),N;
        if(M>0)
            N = matrix[0].size();

        if(M==1)
            {               
                for(int i=0;i<2&&i<N;i++)
                    output.push_back((matrix[0][i]));
        } else if (N==1) {
                for(int i=0;i<2&&i<M;i++)
                    output.push_back((matrix[i][0]));
        }
                else if (M > 1)
		{   
            int r,c;
            int size=(M<N)?M:N;
            for(int i=0;i<size;i++)
            {
                int r0,c0;
              if (direction) {
                    r0=0;
                    c0=i;
              }
              else{
                  r0=i;
                  c0=0;
              }
              r=r0;c=c0;    //initialize the position for every round;

              if (r0==c0) {
                  output.push_back((matrix[r0][c0])); 
              } else {
                while (max(r,c)<=max(r0,c0)) {
                    output.push_back((matrix[r][c]));                   
                    nextmove(r, c, direction);                  
                }
              }

              direction=!direction;
            }


            for(int i=1;i<size;i++)
            {
                int r0,c0;
              if (direction) {
                    r0=i;
                    c0=size-1;
              }
              else{
                  r0=size-1;
                  c0=i;
              }
              r=r0;c=c0;    //initialize the position for every round;

              if (r0==c0) {
                  output.push_back((matrix[r0][c0])); 
              } else {
                while (max(r,c)<=max(r0,c0)) {
                    output.push_back((matrix[r][c]));                   
                    nextmove(r, c, direction);                  
                }
              }

              direction=!direction;
            }
            
                                                                 
					
		}

		return output;
	}

    private:
      void nextmove(int &r, int &c, bool direction) {
        if (direction) {
          r++;
          c--;
        }
         else {
            r--;
            c++;
        }
      }
};

int main() {
	int row, column, k = 0;
	cin >> row >> column;
	

	vector<vector<int>> p;
		p.resize(row);
		for (int i = 0; i < row; i++)
			p[i].resize(column);

		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				p[i][j] = k++;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++)
				cout << p[i][j] << " ";
			cout << endl;
		}

		Solution S;
		vector<int> result=S.findDiagonalOrder(p);
		vector<vector<int>>().swap(p);

		for (int j = 0; j < result.size(); j++)
			cout << result[j] << " ";
			cout << endl;
				

	return 0;
}