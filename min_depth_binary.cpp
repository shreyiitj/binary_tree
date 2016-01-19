//
#include<iostream>
using namespace std;

class node
{
  public:

  int data;
  node* left;
  node* right;
  node(int d,node* l,node* r){data=d;left=l;right=r;}
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
   if(root->left==NULL && root->right==NULL) return 1;
   if(root->left==NULL) return min_depth(root->right)+1;
   if(root->right==NULL) return min_depth(root->left)+1;
   return min(min_depth(root->left),min_depth(root->right))+1;
}
