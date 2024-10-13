/*------------------------------------------------------------------
Tema: Árvore Binária de Busca
Nome: Milena Bueno Maciel
referências: https://www.geeksforgeeks.org/introduction-to-binary-search-tree/
             https://www.geeksforgeeks.org/deletion-in-binary-search-tree/
             https://www.geeksforgeeks.org/binary-search-tree-traversal-inorder-preorder-post-order/
--------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

struct Node {
    int key;
    Node* left;
    Node* right;    
    Node(int item) {
        key = item;
        left = NULL;
        right = NULL;
    }
};
Node* insert(Node* node, int key) {
    if (node == NULL)
        return new Node(key);
    if (node->key <= key) 
        node->right = insert(node->right, key);
    else 
        node->left = insert(node->left, key);
    return node;
}
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

Node* getSuccessor(Node* node)
{
    node = node->right;
    while (node != NULL && node->left != NULL)
        node = node->left;
    return node;
}
 
Node* delNode(Node* root, int x)
{
    if (root == NULL)
        return root;
    
    if (root->key > x)
        root->left = delNode(root->left, x);
    else if (root->key < x)
        root->right = delNode(root->right, x);

    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* succ = getSuccessor(root);
        root->key = succ->key;
        root->right = delNode(root->right, succ->key);
    }
    return root;
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    cout << node->key << " ";

    printInorder(node->right);
}
void printPreOrder(Node* node)
{
    if (node == NULL)
        return;
    cout << node->key << " ";

    printPreOrder(node->left);
    printPreOrder(node->right);
}
void printPostOrder(Node* node)
{
    if (node == NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);

    cout << node->key << " ";
}
int main() { _
    Node* root = new Node(100);
    insert(root, 20);
    insert(root, 200);

    delNode(root, 100);
    
    printInorder(root);
    
    return 0;
}