// is pre bst                     see
#include<iostream>
#include<stack>
using namespace std;

bool is_pre_bst(int *pre,int n);

int main()
{
  int pre[]={40,30,35,20,80,100};
  int n=sizeof(pre)/sizeof(pre[0]);
  is_pre_bst(pre,n)?cout<<"yes":cout<<"no";
}

bool is_pre_bst(int *pre,int n)
{
 stack<int> s;
 int root=-1;
 int i;
 for(i=0;i<n;i++)
 {
   if(pre[i]<root) return false;
   if(!s.empty() && pre[i]>s.top())
   {
     root=s.top();
     s.pop();
   }
   s.push(pre[i]);
 }
 return true;

}
