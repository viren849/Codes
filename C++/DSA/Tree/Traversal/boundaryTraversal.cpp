
//Boundary Traversal .....

//Idea is to get leftbound(without leaf)
// then leaf node in preorder ...
//then rightbound (without leaf) in reverse direction..

bool isleaf(Node* root)
 {
     return !root->left and !root->right;
 }

void leftbound(Node* root)
{
    Node* cur=root;

    while(cur)
    {
      if(!isleaf(cur))
        ans.push_back(cur->val);
      if(cur->left)
        cur=cur->left;
      else cur=cur->right;
    }
}
void leavenode(Node* root)
{

  //or if(!root)return ;
  
      if(isleave(root))
        {
          ans.push_back(ans->val);
          return ;
        }

     if(root->left) leavenode(root->left);
     if(root->right) leavenode(root->right);
}

void rightbound(Node* root)
{
      Node* cur=root;
      vector<int>tmp;

      while(cur)
      {
          if(!isleaf(root))
            tmp.push_back(root->val);
          if(cur->right)
            cur=cur->right;
          else cur=cur->left;
      }

      for(int i=tmp.size()-1;i>=0;i--)
        ans.push_back(tmp[i]);
}