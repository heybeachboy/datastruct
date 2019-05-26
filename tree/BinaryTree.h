//
// Created by DELL on 2019/4/18.
//

#ifndef DATASTRUCT_BINARYTREE_H
#define DATASTRUCT_BINARYTREE_H
template <class T>
struct BTNode{
public:
        T val;
        BTNode * left;
        BTNode * right;
        BTNode * parent;
        BTNode(T ele, BTNode *l, BTNode *r, BTNode *p){
            this->val = ele;
            this->left = l;
            this->right = r;
            this->parent = p;
        }

};
template<class T>
class BinaryTree {
private:
    T root;
public:
    BinaryTree();
    ~BinaryTree();
    void PrevOrder();
    void PrevOrderTraverse();
    void InOrder();
    void InOrderTraverse();
    void PostOrder();
    void PostOrderTraverse();
    BTNode<T> * Search(T key);
    BTNode<T> * IterativeSearch(T key);
    bool Insert(BTNode<T>* tree, BTNode<T>* x);
    bool Delete(BTNode<T>* tree, BTNode<T>* x);
    bool Destroy(BTNode<T>* tree);
    void Display();
};

#endif //DATASTRUCT_BINARYTREE_H
