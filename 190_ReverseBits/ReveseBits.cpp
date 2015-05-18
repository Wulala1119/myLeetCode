#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef unsigned long uint32_t;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
	{
		if(n == 0)
			return 0;
        uint32_t output = 0;
		for(int i = 0; i < 32; i ++)
		{
			output = output << 1;
			output = output | (n & 0x1);
			n = n >> 1;			
		}
		return output;
    }
};
void Test()
{
	uint32_t input = 43261596;
	//uint32_t input = 0x80000000;
	Solution solution0;
	cout << solution0.reverseBits(input)<<endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}