#include <iostream>

struct Node {
    std::string name;
    int age;
    double salary;
    Node* next;
};

void add_to_beginning(Node*& head, Node* new_node) {
    new_node->next = head;
    head = new_node;
}

void add_to_end(Node*& head, Node* new_node) {
    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = new_node;
}

void add_after_node(Node*& head, Node* after_node, Node* new_node) {
    if (after_node == nullptr) {
        std::cout << "The specified node does not exist." << std::endl;
        return;
    }

    new_node->next = after_node->next;
    after_node->next = new_node;
}

void add_before_node(Node*& head, Node* before_node, Node* new_node) {
    if (before_node == nullptr) {
        std::cout << "The specified node does not exist." << std::endl;
        return;
    }

    if (head == before_node) {
        add_to_beginning(head, new_node);
        return;
    }

    Node* current = head;
    while (current->next != before_node) {
        current = current->next;
    }

    new_node->next = before_node;
    current->next = new_node;
}

void remove_node(Node*& head, const std::string& name) {
    if (head == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    if (head->name == name) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->name == name) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }

        current = current->next;
    }

    std::cout << "No node with the specified name was found." << std::endl;
}

void print_list(Node* head) {
    while (head != nullptr) {
        std::cout << "Name: " << head->name << ", Age: " << head->age << ", Salary: " << head->salary << std::endl;
        head = head->next;
    }
}

int main() {
    Node* head = nullptr;

    Node* node1 = new Node{ "John", 30, 50000.0 };
    Node* node2 = new Node{ "Jane", 25, 40000.0 };
    Node* node3 = new Node{ "Bob", 40, 60000.0 };

    add_to_beginning(head, node1);
    add_to_end(head, node2);
    add_after_node(head, node1, node3);
    add_before_node(head, node3, new Node{ "Alice", 28, 45000.0 });

    print_list(head);

    std::cout << std::endl;

    remove_node(head, "Bob");
    print_list(head);

    return 0;
}
