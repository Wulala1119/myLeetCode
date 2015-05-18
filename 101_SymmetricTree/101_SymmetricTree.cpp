// 输出二叉树中所有从根结点到叶子结点的路径.cpp : 定义控制台应用程序的入口点。
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <deque>
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
	int derction;
	int leafNum;
};

//先序创建二叉树
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

//输出二叉树中所有从根结点到叶子结点的路径(递归)
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

bool isSymmetric(TreeNode *root) 
    {
        if(root == NULL)
            return true;
        deque<DeNode> que;  
        DeNode dnode;  
        int tempDepth = 1;
    	dnode.depth = 1;  
        dnode.node = root;  
        que.push_back(dnode); 
        while(!que.empty())  
        {		
            DeNode ptr = que.front();
            if(tempDepth < ptr.depth)
            {
                // 判断现在的队列是不是对称的
                if(que.size() % 2 == 1)
                    return false;
                else
                {
					for(int i = 0; i < que.size() / 2; i ++)
					{
						if(que[i].leafNum != que[que.size() - 1 - i].leafNum)
							return false;
						if(que[i].node->val != que[que.size() - 1 - i].node->val)
							return false;
						if(que[i].node->val == que[que.size() - 1 - i].node->val && que[i].derction == que[que.size() - 1 - i].derction)
							return false;
					}
                }
                tempDepth = ptr.depth;
            }
            que.pop_front();
            if(ptr.node->left != NULL)  
            {  
                DeNode p;  
                p.node = ptr.node->left;  
                p.depth = ptr.depth + 1; 
				p.derction = -1;
				p.leafNum = 0;
				if(p.node->left != NULL)
					p.leafNum ++;
				if(p.node->right != NULL)
					p.leafNum ++;
                que.push_back(p);  
            }    
            if(ptr.node->right != NULL) 
            {  
                DeNode p;  
                p.node = ptr.node->right;  
                p.depth = ptr.depth + 1;  
				p.derction = 1;
				p.leafNum = 0;
				if(p.node->left != NULL)
					p.leafNum ++;
				if(p.node->right != NULL)
					p.leafNum ++;
                que.push_back(p);  
            }  
        }  
        return true;
    }
int main()
{
	TreeNode *pRoot = NULL;
	vector<int> path;
	int input[19] = {5, 4, 11, 7 , 0, 0, 2, 0, 0, 0, 8, 13, 0, 0, 4, 0, 1, 0, 0};
	CreatBTree(pRoot);
	cout << "二叉树中从根到叶子结点的所有路径如下：" << endl;
    FindAllPath(pRoot, path);
	cout << endl;
	cout << isSymmetric(pRoot) << endl;
	system("pause");
	return 0;
}