/*
  Link: https://leetcode.com/problems/longest-common-prefix/submissions/

  Write a function to find the longest common prefix string amongst an array of strings.

  If there is no common prefix, return an empty string "".

   

  Example 1:

  Input: strs = ["flower","flow","flight"]
  Output: "fl"
  Example 2:

  Input: strs = ["dog","racecar","car"]
  Output: ""
  Explanation: There is no common prefix among the input strings.
   

  Constraints:

  0 <= strs.length <= 200
  0 <= strs[i].length <= 200
  strs[i] consists of only lower-case English letters.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (!size) return "";
        if (size == 1) return strs[0];
        sort(strs.begin(), strs.end(), []
          (const std::string& first, const std::string& second){
              return first.size() < second.size();
        });
        string first = strs[0];
        int len = first.length();
        
        while (len) {
          bool ok = true;
          string string_to_check = first.substr(0, len);
          for (int i = 1; i < size; i++) {
            if(strs[i].find(string_to_check) != 0 ) {
              ok = false;
              break;
            }
          }
          if(ok) return string_to_check;
          len --;
        }
        return "";
    }
};


// lesson learned: for longest/maximum problem, you need to think greedy first!

// Solution using Trie can be find below

class TrieNode
{
    public:
    TrieNode *child[26];
    bool isEnd;
    
    TrieNode()
    {
        for(int i=0;i<26;i++)
        child[i] = NULL;
        
        isEnd = false;
    }
};

void insert(TrieNode *root, string key)
{
    TrieNode *temp = root;
    
    for(int i=0;i<key.length();i++)
    {
        int index = int(key[i] - 'a');
        
        if(temp->child[index] == NULL)
        temp->child[index] = new TrieNode();
        
        temp = temp->child[index];
    }
    
    temp->isEnd = true;
}

void constructTrie(TrieNode *root,vector <string> arr)
{
    for(int i=0;i<arr.size();i++)
    insert(root,arr[i]);
}

int countChildren(TrieNode *root,int &index)
{
    int count = 0;
    for(int i=0;i<26;i++)
    {
        if(root->child[i] != NULL)
        {
            count++;
            index = i;
        }
    }
    
    return count;
}

string walkTrie(TrieNode *root)
{
    TrieNode *temp = root; 
    int index; 
    string prefix; 
  
    while (countChildren(temp, index) == 1 && temp->isEnd == false) 
    { 
        temp = temp->child[index]; 
        prefix.push_back('a'+index); 
    } 
    
    return prefix;
}

string longestCommonPrefix(vector <string> arr)
{
    TrieNode *root = new TrieNode();
    constructTrie(root,arr);
    
    string prefix = walkTrie(root);
    
    return prefix;
}

class TrieSolution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode *root = new TrieNode();
        constructTrie(root, strs);
        string prefix = walkTrie(root);
        return prefix;
    }
};

// TODO: Binary search implement
