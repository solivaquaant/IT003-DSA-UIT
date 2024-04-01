
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void preOrder(Node *root)
    {

        if (root == NULL)
            return;

        std::cout << root->data << " ";

        preOrder(root->left);
        preOrder(root->right);
    }

    /* you only have to complete the function given below.
    Node is defined as

    class Node {
        public:
            int data;
            Node *left;
            Node *right;
            Node(int d) {
                data = d;
                left = NULL;
                right = NULL;
            }
    };

    */

    Node *insert(Node *root, int data)
    {
        Node *p = new Node(data);
        if (root == NULL)
        {
            root = p;
            return root;
        }

        Node *q = root;
        Node *parent = NULL;
        while (q != NULL)
        {
            parent = q;
            if (data < q->data)
                q = q->left;
            else
                q = q->right;
        }

        if (data < parent->data)
            parent->left = p;
        else
            parent->right = p;
        return root;
    }
};

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.preOrder(root);

    return 0;
}