// ��������������дӸ���㵽Ҷ�ӽ���·��.cpp : �������̨Ӧ�ó������ڵ㡣
#include <iostream>
#include <vector>
using namespace std;

struct BTNode
{
	int m_value;
	BTNode *m_left;
	BTNode *m_right;
};

//���򴴽�������
void CreatBTree(BTNode *&root)
{	
	int nValue = 0;
	cin >> nValue;
	if (0 == nValue)
	{
		return;
	}
	else
	{
		root = new BTNode();
		root->m_value = nValue;
		CreatBTree(root->m_left);
		CreatBTree(root->m_right);
	}	
}

//��������������дӸ���㵽Ҷ�ӽ���·��(�ݹ�)
void FindAllPath(BTNode *pRoot, vector<int> path)
{
	if (pRoot != NULL)
	{
		path.push_back(pRoot->m_value);
		if (pRoot->m_left == NULL && pRoot->m_right == NULL)
		{
			for (vector<int>::iterator iter=path.begin(); iter!=path.end(); iter++)
			{
				cout << *iter << " ";
			}
			cout << endl;
			return;
		}
		else
		{
			FindAllPath(pRoot->m_left, path);
			FindAllPath(pRoot->m_right, path);
		}
	}
}

bool hasPathSum(BTNode *root, int sum) 
{
	if (root != NULL)
	{
		sum -= root->m_value;

		if (root->m_left == NULL && root->m_right == NULL)
		{
			if(sum == 0)
				return true;
			else
				return false;
		}
		else
		{
			if(hasPathSum(root->m_left, sum))
				return true;
			if(hasPathSum(root->m_right, sum))
				return true;
		}
	}
	return false;
}

int main()
{
	BTNode *pRoot = NULL;
	vector<int> path;
	int input[19] = {5, 4, 11, 7 , 0, 0, 2, 0, 0, 0, 8, 13, 0, 0, 4, 0, 1, 0, 0};
	CreatBTree(pRoot);
	cout << "�������дӸ���Ҷ�ӽ�������·�����£�" << endl;
    FindAllPath(pRoot, path);
	int sum = 22;
	if(hasPathSum(pRoot, sum))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	system("pause");
	return 0;
}