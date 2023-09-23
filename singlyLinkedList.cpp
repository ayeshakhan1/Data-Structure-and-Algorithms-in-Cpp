#include<iostream>

using namespace std;

class Node {
  private: int object;
  Node * next;
  public: void setobj(int obj) {
    object = obj;
  }
  void setnext(Node * next) {
    this -> next = next;
  }

  int getobj() {
    return object;
  }
  Node * getnext() {
    return next;
  }
};

class list {
  private: int size;
  Node * head,
  * current,
  * lastcurrent,
  * tail;
  public: list() {
    size = 0;
    head = new Node();
    head -> setnext(NULL);
    current = head;
    current -> setnext(NULL);
  }

  void add(int obj) {
    Node * newNode = new Node();
    if (current -> getnext() == 0) {
      newNode -> setnext(NULL);
      newNode -> setobj(obj);
      current -> setnext(newNode);
      lastcurrent = current;
      current = newNode;
      size++;
    } else {
      newNode -> setnext(current -> getnext());
      current -> setnext(newNode);
      newNode -> setobj(obj);
      lastcurrent = current;
      current = newNode;
      size++;
    }
  }

  int getvalue() {
    return current -> getobj();
  }

  void pos(int val) {
    current = head;
    lastcurrent = head;
    for (int i = 1; i <= val; i++) {
      lastcurrent = current;
      current = current -> getnext();
    }
  }

  void print() {
    current = head;
    lastcurrent = head;
    while (current -> getnext() != 0) {
      current = current -> getnext();
      cout << current -> getobj() << endl;
    }
  }

  void remove(int position) {
    current = head;
    lastcurrent = head;
    for (int i = 1; i <= position; i++) {
      lastcurrent = current;
      current = current -> getnext();
    }

    if (current != NULL && current != head) {
      lastcurrent -> setnext(current -> getnext());
      delete current;
      current = lastcurrent -> getnext();
      size--;
    }
  }
};

int main() {
  list l1;

  l1.add(20);
  l1.add(30);
  l1.add(40);
  l1.add(50);
  l1.add(60);

  l1.pos(3);
  l1.add(100);
  cout << "before removing: \n";

  l1.print();

  l1.remove(3);
  cout << "\nafter removing: \n";
  l1.print();

  return 0;
}
