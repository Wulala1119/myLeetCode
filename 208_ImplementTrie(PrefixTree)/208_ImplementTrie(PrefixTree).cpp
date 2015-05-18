#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;


class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(char c) 
    {
        content = c;
        isEnd = false;
        count = 0;
    }
    TrieNode* subNode(char c)
    {
        for(int i = 0; i < childList.size(); i ++)
        {
            if(childList[i]->content == c)
                return childList[i];
        }
        return NULL;
    }
    char content;
    bool isEnd;
    vector<TrieNode*> childList;
    int count;
};

class Trie {
public:
    Trie() 
    {
        root = new TrieNode(' ');
    }

    // Inserts a word into the trie.
    void insert(string s) 
    {
        if(search(s))
            return;
		TrieNode* current = root;
        for(int i = 0; i < s.size(); i ++)
        {            
            TrieNode* child = current->subNode(s[i]);
            if(child == NULL)
            {
                TrieNode* newChild = new TrieNode(s[i]);
				current->childList.push_back(newChild);
                current = newChild;				
            }
			else
			{
				current = child;
			}
			current->count ++;
        }
		current->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) 
    {
        if(key == "")
			return false;
		TrieNode* current = root;
        for(int i = 0; i < key.size(); i ++)
        {            
            TrieNode* child = current->subNode(key[i]);
            if(child == NULL)
            {
                break;			
            }
			else
			{
				current = child;
			}
        }
		if(current->isEnd == true)
			return true;
		else
			return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) 
	{
        if(prefix == "")
			return false;
		TrieNode* current = root;
        for(int i = 0; i < prefix.size(); i ++)
        {            
            TrieNode* child = current->subNode(prefix[i]);
            if(child == NULL)
            {
                return false;			
            }
			else
			{
				current = child;
			}
        }
		return true;
    }

    TrieNode* root;
};


// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

class WordDictionary: public Trie
{
public:

    // Adds a word into the data structure.
    void addWord(string word) 
    {
        insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) 
    {
        if(word == "")
			return false;
		length = word.size();
		return search(root, word, 0);
    }
    bool search(TrieNode* start, string word, int index)
    {
        if(start->isEnd == true && index == length)
        {
            return true;
        }
        else
        {
            if(word[index] == '.')
            {
                for(int i = 0; i < start->childList.size(); i ++)
                {
                    if(search(start->childList[i], word, index + 1))
						return true;
                }
				return false;
            }
            else
            {
                TrieNode* child = start->subNode(word[index]);
                if(child == NULL)
                {
                    return false;				
                }
        		else
        		{
        			if(search(child, word, index + 1))
						return true;
					else
						return false;
        		}
            }  
        }
    }
private:
    int length;
};
void Test()
{
	/*Trie trie;
	trie.insert("abc");
	trie.insert("bcd");
	trie.insert("abe");
	trie.insert("bcv");
	cout << trie.search("abc") << endl;
	cout << trie.search("fff") << endl;
	cout << trie.startsWith("ab") << endl;
	cout << trie.startsWith("abc") << endl;
	cout << trie.startsWith("fff") << endl;*/
	WordDictionary WordDict;
	WordDict.addWord("a");
	WordDict.addWord("a");
	cout << WordDict.search("aa") << endl;
	cout << WordDict.search(".a") << endl;
	cout << WordDict.search("a.") << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}