#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int> output;     
		int M = matrix.size(), N;
		if (M > 0)
		{
			N = matrix[0].size();
			int r = 0, c = 0;	
			do
			{
				output.push_back((matrix[r][c]));
			}while (nextmove(r, c, M, N));
		}
		return output;
	}

   private:
	bool nextmove(int& r, int& c, int M, int N) {
	    if (r == M - 1 && c == N - 1)
				return false;
		else if ((r + c) % 2 == 0)   //横纵坐标为偶数时向上
		{
			if (r == 0 || c==N-1 )                  //往上时，到达上右条边说明到达顶点了
			{
				if (c == N - 1)					//不能往右，只能往下
					r++;
				else
					c++;                         //否则往右
			}
			else {
				r--; c++;
				}
		}
		else if ((r + c) % 2 != 0)
		{
			if (r == M-1 ||c==0)                  //往下时，到达左下条边说明到达底部点了
			{
				if (r==M-1)					//不能往下，只能往右
					c++;
				else
					r++;                         //否则往下
			}
			else {
				r++; c--;
			}
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
		vector<int> result=S.findDiagonalOrder(p);
		vector<vector<int>>().swap(p);

		for (int j = 0; j < result.size(); j++)
			cout << result[j] << " ";
			cout << endl;
				

	return 0;
}