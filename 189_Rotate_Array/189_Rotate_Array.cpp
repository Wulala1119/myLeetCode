#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef unsigned long uint32_t;
class Solution {
public:
    void rotate(int nums[], int n, int k) 
	{
		if(n == 0 || k == 0)
	       return;
	    if(k == n)
	    {
	        this->reverse(nums, 0, n - 1);
	        return;
	    }
		this->reverse(nums, 0, n - k - 1);
		this->reverse(nums, n - k, n - 1);
		this->reverse(nums, 0, n - 1);
    }
	void reverse(int arr[], int start, int end)
	{
		int temp = 0;
		for(int i = start; i < (end + start + 1) / 2; i ++)
		{
			temp = arr[i];
			arr[i] = arr[start + end  - i];
			arr[start + end  - i] = temp;
		}
	}
};
void Test()
{
	uint32_t input = 43261596;
	//uint32_t input = 0x80000000;
	int a[7] = {1,2,3,4,5,6,7};
	Solution solution0;
	solution0.rotate(a, 7 , 0);
	for(int i = 0; i < 7; i ++)
		cout << a[i] << '\t';
}
int main()
{
	Test();
	system("pause");
	return 0;
}