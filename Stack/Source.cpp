#include <iostream>

using namespace std;


class Elem {
public:
	int x;
	Elem* next;
};


class Stack {
public:
	Elem* head;

	Stack() {
		head = NULL;
	}

	void display() {
		Elem* el = head;
		cout << "Stack: ";
		while (el) {
			cout << el->x << " ";
			el = el->next;
		}
		cout << endl;
	}

	void add(int x) {
		Elem* el = new(Elem);
		el->x = x;
		el->next = head;
		head = el;
	}

	bool isEmpty() {
		return (head == NULL);
	}

	Elem* pop_front() {
		if (!isEmpty()) {
			Elem* el = head;
			head = el->next;
			while (el->next) {
				el->x = el->next->x;
				el->next = el->next->next;
				el = el->next;
			}
			return head;
		}
	}

	Elem* readHead() {
		return head;
	}
};

class Dek : public Stack {
public:
	void add_dek(int x) {
		Elem* el = new Elem;
		el->x = x;
		el->next = head;
		head = el;
	}

	void display() {
		Elem* el = head;
		cout << "Dek: ";
		while (el) {
			cout << el->x << " ";
			el = el->next;
		}
		cout << endl;
	}

	Elem* pop_front() {
		if (!isEmpty()) {
			Elem* el = head;
			head = el->next;
			while (el->next) {
				el->x = el->next->x;
				el->next = el->next->next;
				el = el->next;
			}
			return head;
		}
	}

	Elem* pop_back() {
		if (!isEmpty()) {
			Elem* el = head;
			while (el->next != NULL) {
				if (el->next->next == NULL) {
					el->next = NULL;
					break;
				}
				el = el->next;
			}
			return head;
		}
	}
};


int main() {
	Stack st;
	Dek dek;
	Elem* el;

	cout << "If stack is empty - print 1, if not - print 0.\nAnwser: " << st.isEmpty() << endl;
	cout << "If dek is empty - print 1, if not - print 0.\nAnwser: " << dek.isEmpty() << endl;

	cout << "adding an element '17' to the stack" << endl;
	st.add(17);
	st.display();

	cout << "adding an element '34' to the stack" << endl;
	st.add(34);
	st.display();

	cout << "adding an element '29' to the stack" << endl;
	st.add(29);
	st.display();

	cout << "removing the head element of the stack" << endl;
	st.pop_front();
	st.display();

	cout << "adding an element '13' to the stack" << endl;
	st.add(13);
	st.display();

	cout << "If stack is empty - print 1, if not - print 0.\nAnwser: " << st.isEmpty() << endl;

	cout << "adding an element '15' to the dek" << endl;
	dek.add_dek(15);
	dek.display();

	cout << "adding an element '65' to the dek" << endl;
	dek.add_dek(65);
	dek.display();

	cout << "adding an element '84' to the dek" << endl;
	dek.add_dek(84);
	dek.display();

	cout << "removing the head element of the dek" << endl;
	dek.pop_front();
	dek.display();

	cout << "adding an element '21' to the dek" << endl;
	dek.add_dek(21);
	dek.display();

	cout << "removing the last element of the dek" << endl;
	dek.pop_back();
	dek.display();

	cout << "If dek is empty - print 1, if not - print 0.\nAnwser: " << dek.isEmpty() << endl;
}