#include<iostream>

using namespace std;

class node
{
   public:
   int data;
   node *left;
   node *right;
   node(int d,node *l,node *r){data=d;left=l;right=r;}
};

int find_max_sum(node *root);

int main()
{
  node* root;
  node a(-5,NULL,NULL);                  /*      e(1)        */
  node b(4,NULL,NULL);                  /*     /   \      */
  node c(-3,NULL,NULL);                  /*  d(2)    c(3)   */
  node d(-2,&b,&a);                   /*    /   \              */
  node e(-1,&d,&c);                  /*   b(4)  a(5)           */
  root=&e;
  int max_sum=find_max_sum(root);
  cout<<max_sum<<endl;
}

int find_max_sum_util(node *root,int &res)
{
  if(root==NULL) return 0;
  int v=root->data;
  int l=find_max_sum_util(root->left,res);
  int r=find_max_sum_util(root->right,res);
  int maxi=max(v,max(v+l,v+r));
  int final_maxi=max(maxi,v+l+r);
  res=max(final_maxi,res);
  return maxi;
}

int find_max_sum(node *root)
{
    int res=0;
    find_max_sum_util(root,res);
    return res;
}
