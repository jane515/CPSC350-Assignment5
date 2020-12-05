//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 5

#include<iostream>
using namespace std;

template<class t>
class TreeNode
{
  public:
    TreeNode();
    TreeNode(t key);
    ~TreeNode();
    TreeNode *left;
    TreeNode *right;
    t key;

};

template<class t>
TreeNode<t>::TreeNode()
{
  left =NULL;
  right = NULL;
  key = NULL;
}

template<class t>
TreeNode<t>::TreeNode(t k)
{
  key = k;
  left =NULL;
  right = NULL;
}

template<class t>
TreeNode<t>::~TreeNode()
{
  delete left;
  delete right;
  //delete key;
}
