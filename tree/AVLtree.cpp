
template <typename T, typename U>
class AVLTree{
    public:
        class AVLNode {
            public:
                T key;
                U value;
                AVLNode *left;
                AVLNode *right;
                int height;
                int balanceFactor;

                AVLNode(T key, U value) {
                    this->key = key;
                    left = right = NULL;
                    height = 1;
                    balanceFactor = 0;
                    this->value = value;
                }

                AVLNode() {
                    left = right = NULL;
                    height = 1;
                    balanceFactor = 0;
                }

                int getHeight(AVLNode *root) {
                    if (root == NULL) {
                        return 0;
                    }
                    return root->height;
                }

        };

        AVLNode *root;

        AVLTree(){
            root = NULL;
        }

        void insert(T key, U value) {
            insert(root, key, value);
        }

        void deleteNode(T key) {
            deleteNode(root, key);
        }

        void inorder() {
            inorder(root);
        }

        void preorder() {
            preorder(root);
        }

        U search(T key) {
            AVLNode *temp = root;
            while (temp != NULL) {
                if (temp->key == key) {
                    return temp->value;
                } else if (key < temp->key) {
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }
            if(temp == NULL) return NULL;
            return temp->value;
        }

    private:
        void preorder(AVLNode *root) {
            if (root == NULL) {
                return;
            }
            cout << root->key << " ";
            preorder(root->left);
            preorder(root->right);
        }

        void inorder(AVLNode *root) {
            if (root == NULL) {
                return;
            }
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }

        void deleteNode(AVLNode *&root, T key) {
            if (root == NULL) {
                return;
            }
            if (key < root->key) {
                deleteNode(root->left, key);
            } else if (key > root->key) {
                deleteNode(root->right, key);
            } else {
                if (root->left == NULL && root->right == NULL) {
                    delete root;
                    root = NULL;
                } else if (root->left == NULL) {
                    AVLNode *temp = root;
                    root = root->right;
                    delete temp;
                } else if (root->right == NULL) {
                    AVLNode *temp = root;
                    root = root->left;
                    delete temp;
                } else {
                    AVLNode *temp = root->right;
                    while (temp->left != NULL) {
                        temp = temp->left;
                    }
                    root->key = temp->key;
                    deleteNode(root->right, temp->key);
                }
            }

            // Update height and balance factor
            if (root == NULL) {
                return;
            }
            root->height = 1 + max(root->getHeight(root->left), root->getHeight(root->right));
            root->balanceFactor = root->getHeight(root->left) - root->getHeight(root->right);

            balance(root);
        }

        void insert(AVLNode *&root, T key, U value) {
            if (root == NULL) {
                root = new AVLNode(key, value);
                return;
            }

            if (key < root->key) {
                insert(root->left, key, value);
            } else {
                insert(root->right, key, value);
            }

            root->height = 1 + max(root->getHeight(root->left), root->getHeight(root->right));

            root->balanceFactor = root->getHeight(root->left) - root->getHeight(root->right);

            balance(root);
        }
 
        void leftRotate(AVLNode *&root) {
            AVLNode *newRoot = root->right;
            root->right = newRoot->left;
            newRoot->left = root;
            root->height = 1 + max(root->getHeight(root->left), root->getHeight(root->right));
            newRoot->height = 1 + max(newRoot->getHeight(newRoot->left), newRoot->getHeight(newRoot->right));
            root = newRoot;
        }

        void rightRotate(AVLNode *&root) {
            AVLNode *newRoot = root->left;
            root->left = newRoot->right;
            newRoot->right = root;
            root->height = 1 + max(root->getHeight(root->left), root->getHeight(root->right));
            newRoot->height = 1 + max(newRoot->getHeight(newRoot->left), newRoot->getHeight(newRoot->right));
            root = newRoot;
        }

        void balance(AVLNode *&root) {
            if (root->balanceFactor > 1) {
                if (root->left->balanceFactor >= 0) {
                    rightRotate(root);
                } else {
                    leftRotate(root->left);
                    rightRotate(root);
                }
            } else if (root->balanceFactor < -1) {
                if (root->right->balanceFactor <= 0) {
                    leftRotate(root);
                } else {
                    rightRotate(root->right);
                    leftRotate(root);
                }
            }
        }  
};
