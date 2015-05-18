#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
typedef unsigned long uint32_t;
class Solution {
public:
    int myAtoi(string str) 
    {
        if(str.size() == 0)
            return 0;
        long long res = 0;
        int flag = 1;
        int posi = 0;
        int nonNumerical = 0;
		bool isNum = false;
        for(int i = 0; i < str.size(); i ++)
        {
			if(str[i] == ' ')
			{
				if(isNum == true)
					return 0;
			}
            if((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '+' && str[i] != '-')
            {
                break;
            }
            if(str[i] == '+' || str[i] == '-')
            {
				isNum = true;
                nonNumerical ++;
            }
            if(str[i] == '-')
            {
                flag = -1;
            }
            if(str[i] >= '0' && str[i] <= '9')
            {
				isNum = true;
                res = res * 10 + (str[i] - '0');
            }
            if(nonNumerical > 1)
                return 0;
        }
        res *= flag;
		if(flag == 1 && res < 0)
			return INT_MAX; 
		if(flag == -1 && res > 0)
			return INT_MIN; 
		if(res > INT_MAX)
            return INT_MAX;
        if(res < INT_MIN)
            return INT_MIN;
        return res;
    }
};
void Test()
{
	uint32_t input = 43261596;
	//uint32_t input = 0x80000000;
	Solution solution0;
	int nRows = 2;
	cout << solution0.myAtoi("-9223372036854775809") << endl;
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