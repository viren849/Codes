#include <bits/stdc++.h>
using namespace std;

//vertical traversal ........
// follow the concept of numberline(ver) and level(lev)

map<int,map<int,multiset<int>>>mp;

void helper(TreeNode* root,int ver,int lev)
{
        if(!root)return;

        mp[ver][lev].insert(root->val);

        helper(root->left,ver-1,lev+1);
        helper(root->right,ver+1,lev+1);
}