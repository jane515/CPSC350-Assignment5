//Jane Yang
//2317614
//huayang@chapman.edu
//CPSC350-01
//Assignment 5

#include "TreeNode.h"
#include <iostream>
template<class t>
class BST
{
  public:
    BST();
    ~BST();
    TreeNode<t> *root;

    bool searchNode(t value);
    void insertNode(t value);
    bool deleteNode(t value);
    bool isEmpty();
    t find(t value);
    void recPrint(TreeNode<t> *node);
    void printTree();
    t getMax();
    TreeNode<t>* getRoot();
    t* values;

    int size;
    unsigned int getSize();
    TreeNode<t>* getSuccessor(TreeNode<t> *d);
    //void recWrite();
};

template<class t>
BST<t>::BST()
{
  size = 0;
  root = NULL;
}

template<class t>
BST<t>::~BST()
{

}
/*
template<class t>
void BST<t>::recWrite(TreeNode<t>* node,ofstream& file)
{
  if(node==NULL)
  {
    return;
  }
  file<<node->key<<endl;
  recWrite(node->left,file);
  recWrite(node->right,file);
}
template<class t>
void BST<t>::writeTo(ofstream& file)
{
  recWrite(root,file);
}*/
template<class t>
void BST<t>::recPrint(TreeNode<t> *node)
{
  if(node!=NULL)
  {
    recPrint(node->left);
    cout<< node->key <<endl;
    recPrint(node->right);
  }
}

template<class t>
void BST<t>::printTree()
{
  recPrint(root);
}

template<class t>
bool BST<t>::isEmpty()
{
  return (size==0);
}

//find the value
template<class t>
t BST<t>::find(t value)
{
  TreeNode<t> *current = root;
  while(current->key !=value)
  {
    if(value<current->key)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }
  return current->key;
}
template<class t>
t BST<t>::getMax()
{
  TreeNode<t> *current = root;
  if(root==NULL)
  {
    return NULL;
  }
  while(current->right !=NULL)
  {
    current = current->right;
  }
  return current->key;
}

template<class t>
void BST<t>::insertNode(t value)
{
  TreeNode<t> *node = new TreeNode<t>(value);
  if(root==NULL)
  {
    root = node;
  }
  else
  {
    TreeNode<t> *current = root;
    TreeNode<t> *parent = NULL;
    while(true)
    {
      parent = current;
      if(value < current->key)
      {
        //go to the left
        current = current->left;
        if(current==NULL)
        {
          parent->left = node;
          break;
        }
      }
      else
      {
        //go to the right
        current = current->right;
        if(current==NULL)
        {
          parent->right = node;
          break;
        }
      }
    }
  }
}

template<class t>
bool BST<t>::searchNode(t value)
{
  if(root==NULL)
  {
    return false;
  }
  else
  {
    TreeNode<t> *current = root;
    while(current->key != value)
    {
      if(value<current->key)
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
      if(current=NULL)
      {
        return false;
      }
    }
  }
  return true;
}

template<class t>
bool BST<t>::deleteNode(t value)
{
  if(root==NULL)
  {
    return false;
  }
  TreeNode<t> *current = root;
  TreeNode<t> *parent = root;
  bool isLeftChild = true;
  while(current->key !=value)
  {
    parent = current;
    if(value<current->key)
    {
      isLeftChild = true;
      current = current->left;
    }
    else
    {
      isLeftChild = false;
      current = current->right;
    }
    if(current==NULL)
    {
      return false;
    }
  }
  //start to delete the curNode
  //case: node to deleted is a leaf curNode
  if(current->left==NULL && current->right==NULL)
  {
    if(current==root)
    {
      root = NULL;
    }
    else if(isLeftChild)
    {
      parent->left = NULL;
    }
    else
    {
      parent->right = NULL;
    }
  }
  //case: node have one child
  else if(current->right==NULL)
  {
    if(current=root)
    {
      root = current->left;
    }
    else if(isLeftChild)
    {
      parent->left = current->left;
    }
    else
    {
      parent->right = current->left;
    }
  }
  else if(current->left ==NULL)
  {
    if(current==root)
    {
      root = current->right;
    }
    else if(isLeftChild)
    {
      parent->left = current->right;
    }
    else
    {
      parent->right = current->right;
    }
  }
  //node have two children
  else
  {
    TreeNode<t> *successor = getSuccessor(current);
    if(current==root)
    {
      root = successor;
    }
    else if(isLeftChild)
    {
      parent->left = successor;
    }
    else
    {
      parent->right = successor;
    }
    successor->left = current->left;
  }
  //delete current;
  return true;
}

//d is the node to be delete
template<class t>
TreeNode<t>* BST<t>::getSuccessor(TreeNode<t> *d)
{
  TreeNode<t> *sp = d;
  TreeNode<t> *successor = d;
  TreeNode<t> *current = d->right;

  while(current!=NULL)
  {
    sp = successor;
    successor = current;
    current = current->left;
  }
  if(successor!=d->right)
  {
    sp->left=successor->right;
    successor->right = d->right;
  }
  return successor;
}
template<class t>
TreeNode<t>* BST<t>::getRoot()
{
  return root;
}
