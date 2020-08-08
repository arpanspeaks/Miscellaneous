#include<iostream>
#include<queue>
using namespace std;

struct BstNode {
	int data;
	BstNode *left, *right;
};

BstNode* createNode(int data) {
	BstNode* node = new BstNode();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BstNode* insert(BstNode* root, int data) {
	if(root == NULL) root = createNode(data);
	else if(data <= root->data) root->left = insert(root->left, data);
	else root->right = insert(root->right, data);
	return root;
}

bool search(BstNode* root, int data) {
	if(root == NULL) return false;
	else if(root->data == data) return true;
	else if(data <= root->data) return search(root->left, data);
	else return search(root->right, data);
}

int findMin(BstNode* root) {
	if(root == NULL) return -1;
	/*
	// iterative approach
	while(root->left != NULL) root = root->left;
	return root->data;
	*/
	// recursive approach
	if(root->left == NULL) return root->data;
	return findMin(root->left);
}

int findMax(BstNode* root) {
	if(root == NULL) return -1;
	/*
	// iterative approach
	while(root->right != NULL) root = root->right;
	return root->data;
	*/
	// recursive approach
	if(root->right == NULL) return root->data;
	return findMax(root->right);
}

int findHeight(BstNode* root) {
	if(root == NULL) return -1;
	return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void levelOrderTraversal(BstNode* root) {
	queue<BstNode*> q;
	q.push(root);
	cout << "The result of the level order traversal is: ";
	while(!q.empty()) {
		BstNode* current = q.front();
		cout << current->data << " ";
		if(current->left != NULL) q.push(current->left);
		if(current->right != NULL) q.push(current->right);
		q.pop();
	}
	cout << endl;
	return;
}

void preOrderTraversal(BstNode* root) {
	if(root == NULL) return;
	cout << root->data << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void inOrderTraversal(BstNode* root) {
	if(root == NULL) return;
	inOrderTraversal(root->left);
	cout << root->data << " ";
	inOrderTraversal(root->right);
}

void postOrderTraversal(BstNode* root) {
	if(root == NULL) return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << " ";
}

int main() {
	BstNode *root = NULL; // creating an empty tree
	int n;
	do {
		cout << "----\nMENU\n----" <<endl;
		cout << "Press 1 to insert" << endl;
		cout << "Press 2 to search" << endl;
		cout << "Press 3 to find the minimum" << endl;
		cout << "Press 4 to find the maximum" << endl;
		cout << "Press 5 to find the height" << endl;
		cout << "Press 6 for level-order traversal" << endl;
		cout << "Press 7 for pre-order traversal" << endl;
		cout << "Press 8 for in-order traversal" << endl;
		cout << "Press 9 for post-order traversal" << endl;
		cout << "Press 10 to exit\n----" << endl;
		cout << "Your choice: ";
		cin >> n;
		switch(n) {
			case 1: {
				cout << "Enter the element to insert: ";
				int i;
				cin >> i;
				root = insert(root, i); 
				cout << "One element inserted in the BST." <<endl;
				break;
			}
			case 2: {
				cout << "Enter the element to search: ";
				int i;
				cin >> i;
				if (search(root, i)) cout << "Found" << endl;
				else cout << "Not found" << endl;
			}
			case 3: {
				int x = findMin(root);
				if (x == -1) cout << "Empty tree!" << endl;
				else cout << "The minimum element in the tree is: " << x << endl;
				break;
			}	
			case 4: {
				int x = findMax(root);
				if (x == -1) cout << "Empty tree!" << endl;
				else cout << "The maximum element in the tree is: " << x << endl;
				break;
			}
			case 5: {
				int x = findHeight(root);
				if (x == -1) cout << "Empty tree!" << endl;
				else cout << "The height of the tree is: " << x << endl;
				break;
			}
			case 6: {
				if (root == NULL) cout << "Empty tree!" << endl;
				else levelOrderTraversal(root);
				break;
			}
			case 7: {
				if (root == NULL) cout << "Empty tree!" << endl;
				else {
					cout << "The result of the pre-order traversal is: ";
					preOrderTraversal(root);
				}
				cout << endl;
				break;
			}
			case 8: {
				if (root == NULL) cout << "Empty tree!" << endl;
				else {
					cout << "The result of the in-order traversal is: ";
					inOrderTraversal(root);
				}
				cout << endl;
				break;
			}
			case 9: {
				if (root == NULL) cout << "Empty tree!" << endl;
				else {
					cout << "The result of the post-order traversal is: ";
					postOrderTraversal(root);
				}
				cout << endl;
				break;
			}	
		}
	} while (n != 10);
	cout << "Thank you!" << endl;
	return 0;
}
