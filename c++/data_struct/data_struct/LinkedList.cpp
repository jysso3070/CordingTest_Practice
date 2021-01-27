#include <iostream>

struct Node {
	int node_data;
	Node* next;
	Node* prev;
};


// ���Ḯ��Ʈ
class LinkedList {

public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	~LinkedList() {
	}

	void addDataFront(const int& data);
	void addDataBack(const int& data);
	void insertData(const int& index, const int& data);
	void deleteData(const int& index);
	Node* getNode(const int& index) const;
	void displayAll() const;
	void displayAllReverse() const;

private:
	Node* head;
	Node* tail;
};

int main() {
	LinkedList list_ex;
	list_ex.addDataFront(3);
	list_ex.addDataFront(4);
	list_ex.addDataBack(1);

	list_ex.displayAll();
	std::cout << "----------\n";
	list_ex.insertData(0, 2);
	list_ex.displayAll();
	std::cout << "----------\n";
	list_ex.deleteData(3);
	list_ex.displayAll();
	std::cout << "----------\n";
	list_ex.insertData(100, 1);
	list_ex.deleteData(-100);

	//list_ex.displayAllReverse();

	//node* t = list_ex.getNode(2);
	//std::cout << "find: " << t->node_data << std::endl;

}

void LinkedList::addDataFront(const int& data)
{
	Node* newNode = new Node;
	newNode->node_data = data;
	newNode->next = nullptr;
	newNode->prev = nullptr;

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		head->prev = newNode;
		newNode->next = head; // ���� head�� �� ����� �ؽ�Ʈ��
		head = newNode;
	}
}

void LinkedList::addDataBack(const int & data)
{
	Node* newNode = new Node;
	newNode->node_data = data;
	newNode->next = nullptr;

	if (tail == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		Node* tempTail = tail;
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

void LinkedList::insertData(const int & index, const int& data)
{
	Node* newNode = new Node;
	newNode->node_data = data;

	Node* indexNode = this->getNode(index);
	if (indexNode == nullptr) {
		std::cout << "�߸��� �ε���\n";
		return;
	}
	// ������ ��带 �ڷ� �а� ���ο� ��带 ����
	if (index == 0) {
		this->addDataFront(data);
	}
	else {
		newNode->prev = indexNode->prev;
		newNode->prev->next = newNode;
		newNode->next = indexNode;
		indexNode->prev = newNode;
	}
}

void LinkedList::deleteData(const int & index)
{
	Node* indexNode = this->getNode(index);
	if (indexNode == nullptr) {
		std::cout << "�߸��� �ε���\n";
		return;
	}
	if (index == 0) {
		head = indexNode->next;
		head->prev = nullptr;
	}
	else if (indexNode->next == nullptr) {
		tail = indexNode->prev;
		tail->next = nullptr;
	}
	else {
		indexNode->prev->next = indexNode->next;
		indexNode->next->prev = indexNode->prev;
	}
	delete indexNode;
	indexNode = nullptr;
}

Node * LinkedList::getNode(const int & index) const
{
	if (index < 0) {
		std::cout << "�߸��� �ε���(���̳ʽ���) \n";
		return nullptr;
	}

	int cnt = 0;
	Node* temp = head;
	while (true) {
		if (cnt == index) {
			return temp;
		}
		if (temp->next == nullptr) {
			std::cout << "������ ��� �ε��� \n";
			return nullptr;
		}
		temp = temp->next;
		++cnt;
	}
	return nullptr;
}

void LinkedList::displayAll() const
{
	if (head == nullptr) {
		std::cout << "data not exist \n";
		return;
	}
	else {
		Node* temp = new Node;
		temp = head;
		while (true) {
			std::cout << "data: " << temp->node_data << "\n";
			if (temp->next == nullptr) {
				return;
			}
			temp = temp->next;
		}
	}
}

void LinkedList::displayAllReverse() const
{
	if (head == nullptr) {
		std::cout << "data not exist \n";
		return;
	}
	else {
		Node* temp = new Node;
		temp = tail;
		while (true) {
			std::cout << "data: " << temp->node_data << "\n";
			if (temp->prev == nullptr) {
				return;
			}
			temp = temp->prev;
		}
	}
}
