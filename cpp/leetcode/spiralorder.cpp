#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int direction = 1;
        
        if(!matrix.empty())
        {       
                vector<vector<int>> matrix_fake(matrix.size(),vector<int>(matrix[0].size(),0));
                int r = 0, c = 0;
                res.push_back(matrix[r][c]);
                matrix_fake[r][c] = -1;
                while(nextmove(r,c,matrix_fake,direction))
                {
                    res.push_back(matrix[r][c]);
                    matrix_fake[r][c] = -1;
		        }
                
            }
            return res;
    }

    private:
        bool nextmove(int &r,int &c,vector<vector<int>> matrix,int &direction)
        {
            int r0 = r, c0 = c;
            int M = matrix.size();
            int N = matrix[0].size();
           switch (direction)
            {
            case 1:
                c0++;
                break;
            case 2:
                r0++;
                break;
            case 3:
                c0--;
                break;
            case 0:
                r0--;
                break;
                }
            if(r0<0||c0<0||r0>M-1||c0>N-1)
                {   
                    direction = (direction + 1) % 4;
                    }  
             else if (matrix[r0][c0] != 0)
             {
                    direction = (direction + 1) % 4;
             }

             switch (direction)
            {
            case 1:
                c++;
                break;
            case 2:
                r++;
                break;
            case 3:
                c--;
                break;
            case 0:
                r--;
                break;
                }

            if(r<0||c<0||r>M-1||c>N-1)
                {   
                    return false;
                    }  
             else if (matrix[r][c] != 0)
             {
                    return false;
             }
                    return true;
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
		vector<int> result=S.spiralOrder(p);
		vector<vector<int>>().swap(p);

		for (int j = 0; j < result.size(); j++)
			cout << result[j] << " ";
			cout << endl;
            system("pause");

            return 0;
}
