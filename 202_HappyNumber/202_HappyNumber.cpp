#include <iostream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
class Solution {
public:
    bool isHappy(int n) 
    {
        int squaresSum = n;
        int tempSum = 0;
        map<int, int> sumMap;
        sumMap[n] = 1;
        while(1)
        {
            tempSum = squaresSum;
            squaresSum = 0;
            while(tempSum != 0)
            {
                squaresSum += pow(tempSum % 10, 2);
                tempSum /= 10;
            }
            if(squaresSum == 1)
            {
                return true;
            }
            else
            {
                if(sumMap.count(squaresSum) == 0)
                {
                    sumMap[squaresSum] = 1;
                }
                else
                {
                    return false;
                }
            }
        }
    }
};
void Test()
{
	Solution solution0;
	cout << solution0.isHappy(2) << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}