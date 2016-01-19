//
#include<iostream>
using namespace std;

class node
{
  public:
  int data;
  node *left;
  node *right;
  node(int d,node *l,node *r)
  {
    data=d;
    left=l;
    right=r;
  }
};

bool check_full(node *root);

int main()
{
  node *root;
  node e(22,NULL,NULL);
  node a(10,NULL,NULL);
  node b(15,NULL,NULL);
  node c(20,&a,&e);
  node d(25,&c,&b);
  root=&d;
  cout<<check_full(root);
}

bool check_full(node *root)
{

  if(root==NULL) return false;
  else if(root->left==NULL && root->right==NULL) return true;
  else if(root->left==NULL && root->right!=NULL) return false;
  else if(root->left!=NULL && root->right==NULL) return false;

  if(check_full(root->left)==false) return false;
  if(check_full(root->right)==false) return false;
  return true;
}
