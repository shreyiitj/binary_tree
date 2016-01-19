//min_depth_binary  by level order traversal

#include<iostream>
#include<queue>
using namespace std;

class node
{
   public:
   int data;
   node *left;
   node *right;
   node(int d,node *l,node *r){data=d;left=l;right=r;}
};

class q_item
{
  public:
  node *n;
  int depth;
  q_item(node *node,int d){n=node; depth=d;}
};

int min_depth(node* root);

int main()
{
 node* root;
  node a(5,NULL,NULL);                  /*      e(1)        */
  node b(4,NULL,NULL);                  /*     /   \      */
  node c(3,NULL,NULL);                  /*  d(2)    c(3)   */
  node d(2,&b,&a);                   /*    /   \              */
  node e(1,&d,&c);                  /*   b(4)  a(5)           */
  root=&e;
  int min_d=min_depth(root);
  cout<<min_d<<endl;
}

int min_depth(node* root)
{
  if(root==NULL) return 0;
  queue<q_item> q;
  q_item qi(root,1);
  q.push(qi);
  while(!q.empty())
  {
    qi=q.front();
    q.pop();
    node *n=qi.n;
    int depth=qi.depth;
    if(n->left==NULL && n->right==NULL)
    {
      return depth;
    }
    if(n->left!=NULL)
    {
      qi.n=n->left;
      qi.depth=depth+1;
      q.push(qi);
    }
    if(n->right!=NULL)
    {
      qi.n=n->right;
      qi.depth=depth+1;
      q.push(qi);
    }
  }

  return 0;
}
