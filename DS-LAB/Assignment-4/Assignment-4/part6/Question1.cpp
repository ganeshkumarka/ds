#include <iostream>
using namespace std;
class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int element) {
    if (root == nullptr) {
        return new TreeNode(element);
    }
    if (element < root->data) {
        root->left = insert(root->left, element);
    } else if (element > root->data) {
        root->right = insert(root->right, element);
    }
    return root;
}

bool search(TreeNode* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (key == root->data) {
        return true;
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int element) {
    if (root == nullptr) {
        return root;
    }
    if (element < root->data) {
        root->left = deleteNode(root->left, element);
    } else if (element > root->data) {
        root->right = deleteNode(root->right, element);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode* root = nullptr;
    int choice, element;

    do {
        cout << "Binary Search Tree Menu:";
        cout << "/n1. Insert" ;
        cout << "/n2. Search" ;
        cout << "/n3. Delete" ;
        cout << "/n4. Inorder Traversal" ;
        cout << "/n5. Preorder Traversal" ;
        cout << "/n6. Postorder Traversal" ;
        cout << "/n7. Exit" ;
        cout << "/nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> element;
                root = insert(root, element);
                break;
            case 2:
                cout << "Enter the element to be search: ";
                cin >> element;
                if (search(root, element)) {
                    cout << "Element found in the BST.";
                } else {
                    cout << "Element not found in the BST.";
                }
                break;
            case 3:
                cout << "Enter the element to delete: ";
                cin >> element;
                root = deleteNode(root, element);
                break;
            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                break;
            case 5:
                cout << "Preorder Traversal: ";
                preorder(root);
                break;
            case 6:
                cout << "Postorder Traversal: ";
                postorder(root);
                break;
            case 7:
                cout << "/nExiting program.";
                break;
            default:
                cout << "/nInvalid choice";
        }
    } while (choice != 7);

    return 0;
}
