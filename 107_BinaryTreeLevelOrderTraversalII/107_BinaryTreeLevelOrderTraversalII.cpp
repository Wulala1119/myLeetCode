// ��������������дӸ���㵽Ҷ�ӽ���·��.cpp : �������̨Ӧ�ó������ڵ㡣
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
};
struct DeNode
{
	TreeNode *node;
	int depth;
};

//���򴴽�������
void CreatBTree(TreeNode *&root)
{	
	int nValue = 0;
	cin >> nValue;
	if (0 == nValue)
	{
		return;
	}
	else
	{
		root = new TreeNode();
		root->val = nValue;
		CreatBTree(root->left);
		CreatBTree(root->right);
	}	
}

//��������������дӸ���㵽Ҷ�ӽ���·��(�ݹ�)
void FindAllPath(TreeNode *pRoot, vector<int> path)
{
	if (pRoot != NULL)
	{
		path.push_back(pRoot->val);
		if (pRoot->left == NULL && pRoot->right == NULL)
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
			FindAllPath(pRoot->left, path);
			FindAllPath(pRoot->right, path);
		}
	}
}

vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        vector<vector<int> > res;
    	if(root == NULL)
		    return res;
    	stack<DeNode> s;
        TreeNode *p = root;
        int tempDepth = 0;
        while(p != NULL || !s.empty())
        {
            while(p != NULL)
            {
                DeNode denode;
                denode.node = p;
                denode.depth = ++ tempDepth;
                s.push(denode);
    			p = p->left;
            }
            if(!s.empty())
            {
                DeNode ptr = s.top();
                if(res.size() < ptr.depth)
                {
                    vector<int> layer;
                    layer.push_back(ptr.node->val);
                    res.push_back(layer);
                }
                else
                {
                    res[ptr.depth - 1].push_back(ptr.node->val);
                }
                p = ptr.node;
                tempDepth = ptr.depth;
                s.pop();
    			p = p->right;
            }
        }
    	return res;
    }
int main()
{
	TreeNode *pRoot = NULL;
	vector<int> path;
	int input[19] = {5, 4, 11, 7 , 0, 0, 2, 0, 0, 0, 8, 13, 0, 0, 4, 0, 1, 0, 0};
	CreatBTree(pRoot);
	cout << "�������дӸ���Ҷ�ӽ�������·�����£�" << endl;
    FindAllPath(pRoot, path);
	vector<vector<int> > res = levelOrderBottom(pRoot);
	for(int i = 0; i < res.size(); i ++)
	{
		for(int j = 0; j < res[i].size(); j ++)
			cout << res[i][j] << '\t';
		cout << endl;
	}
	system("pause");
	return 0;
}