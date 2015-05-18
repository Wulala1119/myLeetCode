#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
typedef unsigned long uint32_t;
class Solution {
public:
    string convert(string s, int nRows) 
	{
		if(nRows == 0 || nRows == 1)
			return s;
		//初始化string[nRows]存放每行的字母，最后再连接起来
		vector<string> tempS(nRows,"");
		//
		int colNum = nRows * 2 - 2;
		int cols = s.size() / colNum;
		int remained = s.size() % colNum;
		//先填完整的
		for(int i = 0; i < cols; i ++)
		{
			tempS[0] += s[i * colNum];
			tempS[nRows - 1] += s[i * colNum + nRows - 1];
			for(int j = 1; j < nRows - 1; j ++)
			{
				tempS[j] = tempS[j] + s[i * colNum + j] + s[i * colNum + colNum - j];
			}
		}
		//再填剩下的
		if(remained <= nRows)
		{
			for(int i = 0; i < remained; i ++)
				tempS[i] += s[colNum * cols + i];
		}
		else
		{
			for(int i = 0; i < nRows; i ++)
				tempS[i] += s[colNum * cols + i];
			for(int i = nRows - 2; i > nRows - 2 - remained + nRows; i --)
				tempS[i] += s[colNum * cols + colNum - i];
		}
		string output;
		for(int i = 0; i < nRows; i ++)
				output += tempS[i];        
		return output;
    }
};
void Test()
{
	uint32_t input = 43261596;
	//uint32_t input = 0x80000000;
	Solution solution0;
	int nRows = 2;
	cout << solution0.convert("", nRows) << endl;
	cout << INT_MAX << endl;
	int a = -2147483647;
	cout << abs(a) << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}