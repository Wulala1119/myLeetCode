#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        // if(n == 0)
        //     return;
        // if(m == 0)
        // {
        //     for(int i = 0; i < n; i ++)
        //         nums1.push_back(nums2[i]);
        //     return;
        // }
        // vector<int>::iterator iter = nums2.begin();
        // for(int i = 0; i < n; i ++)
        // {
        //     if(iter == nums2.end())
        //         nums1.push_back(nums2[i]);
        //     for(; iter != nums2.end(); iter ++)
        //     {
        //         if(nums2[i] <= *iter)
        //         {
        //             iter = nums1.insert(iter, nums2[i]);
        //         }
        //     }
        // }
        if(n == 0)
            return;
        if(m == 0)
        {
            for(int i = 0; i < n; i ++)
                nums1[i] = nums2[i];
            return;
        }
        int total = m + n;
        while(m != -1 && n != -1)
        {
            if(nums1[m - 1] > nums2[n - 1]) 
                nums1[-- total] = nums1[-- m];
            else 
                nums1[-- total] = nums2[-- n];
        }
        while(n != -1)
            nums1[-- total] = nums2[-- n];
    }
};
void Test()
{
	Solution solution0;
	cout << solution0.merge("aa","bb") << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}