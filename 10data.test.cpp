#include<iostream>
#include<limits>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(unsigned int rollno) {
        data = rollno;
        next = nullptr;
    }
};

void inputRollno(unsigned int* Rollno) {
    bool valid = false;
    while (!valid) {
        cout << "\nEnter the rollno: ";
        cin >> *Rollno;

        if (*Rollno <= 100) {
            valid = true;
        } else {
            cout << "Invalid roll number. Enter number between 0 to 100.\n";
        }
    }
}

bool isDuplicate(Node* head, unsigned int Rollno) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == Rollno)
            return true;
        temp = temp->next;
    }
    return false;
}

int main() {
    unsigned int Rollno;
    int count = 0, size = 3;

    cout << "Enter unique roll numbers (0-100)\n";

    inputRollno(&Rollno);
    Node* head = new Node(Rollno);
    Node* tail = head;
    count++;

    while (count < size) {
        inputRollno(&Rollno);

        if (isDuplicate(head, Rollno)) {
            cout << "Duplicate roll number. Try again.\n";
            continue;
        }

        Node* newNode = new Node(Rollno);
        tail->next = newNode;
        tail = newNode;
        count++;
    }
    Node* temp = head;
    cout << "[\n";
    while (temp) {
        cout << "\t{\n";
        cout << "\t\tRollno: " << temp->data << "\n";
        cout << "\t},\n";
        temp = temp->next;
    }
    cout << "]\n";

    temp = head;
    while (temp) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }

    return 0;
}