

    void inOrder(Node *root)
    { // LNR
        inOrder(root->left);
        printf("%d \t", root->data);
        inOrder(root->right);