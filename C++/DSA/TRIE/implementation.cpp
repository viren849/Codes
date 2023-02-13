#include<bits/stdc++.h>
using namespace std;

struct Node{
  Node* links[26];
  bool fl;

  Node()
  {
     fl=false;
     for(int i=0;i<26;i++)
      links[i]=NULL;
  }

};


bool containkey(char ch,Node *root)
{
   return root->links[ch-'a'] != NULL;
}

void put(char ch,Node *root)
{
      root->links[ch-'a']=new Node();
}
Node* get(char ch,Node* root)
{
  return root->links[ch-'a'];
}
void insert(string word,Node* root)
{

        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(!containkey(word[i],root))
            {
               put(word[i],root);
            }
            root=get(word[i],root);
        }
        root->fl=true;
}

bool search(string word,Node* root)
{
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(!containkey(word[i],root))
               return false;
             root=root->links[word[i]-'a'];
        }
        return root->fl;
}

int main()
{
     vector<string>ans;
      
      Node* root=new Node();

      int n;
      cin>>n;

      for(int i=0;i<n;i++)
      {
        string s;
        cin>>s;
        ans.push_back(s);  
      }
        
        for(string x : ans)
           insert(x,root);

      string s2;
      cin>>s2;

      cout<<search(s2,root);

}