#include <iostream>
#include <vector>
#include <math.h>
#include <set>
using namespace std;
/*
	Input: an integer n > 1
 
	Let A be an array of Boolean values, indexed by integers 2 to n,
	initially all set to true.
 
	 for i = 2, 3, 4, ..., not exceeding √n:
	  if A[i] is true:
		for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n :
		  A[j] := false
 
	Output: all i such that A[i] is true.
*/
class Solution {
public:
    int countPrimes(int n) 
	{
		bool *arr = new bool[n + 1];
		int count = 0;
		memset(arr, true, n);
		for(int i = 2; i <= (int)sqrt(n); i ++)
		{
			if(arr[i] == true)
			{
				for(int j = 2; i * j <= n; j ++)
				{
					arr[i * j] = false;
				}
			}
		}
		for(int i = 2; i <= n - 1; i ++)
		{
			if(arr[i] == true)
			{
				count ++;
			}
		}
		return count;
    }
};
void Test()
{
	Solution solution0;
	int n;
	while(cin >> n)
	{
		cout << solution0.countPrimes(n);
		cout << endl;
	}
}
int main()
{
	Test();
	system("pause");
	return 0;
}