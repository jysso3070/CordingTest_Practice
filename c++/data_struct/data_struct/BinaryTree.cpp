#include <iostream>

struct Node {
	int node_data;
	Node* parent;
	Node* left;
	Node* right;
};


// 이진트리
class BinaryTree {
public:
	BinaryTree() {
		root = nullptr;
	}
	~BinaryTree() {
	}
	void insert(const int& data);
	bool search(const int& data);
	void deleteData(const int& data);
	void display();
	
	

public:
	Node* root;
	Node* searchMaxNode(Node* node);
	Node* processRemove(Node* node, const int& data);
	void inorderDisplay(Node* node);
};

int main() {
	BinaryTree* ms = new BinaryTree;
	ms->insert(1);
	ms->insert(2);
	ms->display();
	ms->deleteData(2);
	ms->display();
	ms->insert(2);
	ms->display();
}

void BinaryTree::insert(const int & data)
{
	/*if (this->search(data)) {
		std::cout << "중복 데이터 \n";
		return;
	}*/

	Node* newNode = new Node;
	newNode->node_data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->parent = nullptr;

	if (root == nullptr) {
		root = newNode;
	}
	else {
		Node* cur = root;
		Node* tempPar = nullptr;
		while (cur != nullptr) {
			tempPar = cur;
			if (newNode->node_data < cur->node_data) {
				cur = cur->left;
			}
			else {
				cur = cur->right;
			}
		}
		if (newNode->node_data < tempPar->node_data) {
			tempPar->left = newNode;
		}
		else {
			tempPar->right = newNode;
		}
	}
}

bool BinaryTree::search(const int & data)
{
	Node* cur = root;
	while (cur != nullptr) {
		if (cur->node_data == data) {
			std::cout << "find data: " << cur->node_data << "\n";
			return true;
		}
		else if (cur->node_data < data) {
			cur = cur->right;
		}
		else {
			cur = cur->left;
		}
	}
	std::cout << "data: " << data << " not exist \n";
	return false;
}

void BinaryTree::deleteData(const int & data)
{
	if (this->search(data) == false) {
		std::cout << "삭제할 데이터가 존재하지 않음 \n";
		return;
	}
	Node* cur = this->root;
	processRemove(cur, data);
}

void BinaryTree::display()
{
	inorderDisplay(this->root);
	std::cout << "\n";
}

Node * BinaryTree::searchMaxNode(Node * node)
{
	if (node == nullptr) {
		return nullptr;
	}
	while (node->right != nullptr) {
		node = node->right;
	}
	return node;
}

Node * BinaryTree::processRemove(Node * node, const int & data)
{
	if (node == nullptr) {
		return node;
	}
	else if (node->node_data < data) {
		node->right = processRemove(node->right, data);
	}
	else if (node->node_data > data) {
		node->left = processRemove(node->left, data);
	}
	else {
		Node* temp = node;
		if (node->left && nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
		}
		else if (node->left == nullptr) {	// 자식이 오른쪽만 있을때
			node = node->right;
			delete temp;
		}
		else if (node->right == nullptr) {	// 자식이 왼쪽만 있을때
			node = node->left;
			delete temp;
		}
		else{								// 자식이 양쪽다 있을때
			temp = this->searchMaxNode(node->left);
			node->node_data = temp->node_data;
			node->left = this->processRemove(node->left, temp->node_data);
		}
	}

	return nullptr;
}

void BinaryTree::inorderDisplay(Node * node)
{
	if (node != nullptr) {
		inorderDisplay(node->left);
		std::cout << node->node_data << " ";
		inorderDisplay(node->right);
	}
}
