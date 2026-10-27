/*
Luna: Listify
Keira: Bullet Points 1, 2, 3
Lynn: Bullet Points 4, 5, 6
Kaitlyn: Bullet Points 7, 8, 9
Vienna: Listify
*/

#undef debug

#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;


template<typename T>
class BSTNode {

public:
	// Constructors, etc.
	BSTNode() : _data(0), _left(nullptr), _right(nullptr) {} // default constructor
  BSTNode(T data) : _left(nullptr), _right(nullptr) { _data = data; } // value constructor
	BSTNode(BSTNode&); // copy constructor
  ~BSTNode(); // destructor
	BSTNode& operator= (BSTNode&); // copy assignment operator
	
	// ***** Your group will define/implement the insert function
	// ***** at about line 89 below...
	void insert(const T& data);
	
	// Accessor and mutator functions
  BSTNode<T>* getLeft() const { return _left; }
	BSTNode<T>* getRight() const { return _right; }
	T& getData() const { return _data; }
	void setData(const T& data) { _data = data; }

	// Display functions used by operator<<.
	// ***** Your group will define/implement the pre & post display functions
	// ***** at about lines 114 & 127 below...
	void inOrderDisplay(ostream&) const;
	void preOrderDisplay(ostream&) const;
	void postOrderDisplay(ostream&) const;

  // listify
  void listify(list<T>& li) const;

	
	// The insertion operator below uses in-order display.
	// ***** Change the implementation of this insertion operator
	// ***** in order to switch to pre- or post-order display
	friend ostream& operator<< (ostream& out, const BSTNode<T>& b)
		{ b.inOrderDisplay(out); return out; }
	
private:
	T _data;
    BSTNode<T>* _left;
    BSTNode<T>* _right;
	
	// private "helper" functions
    void addLeft(const T& data) { _left = new BSTNode(data); }
	void addRight(const T& data) { _right = new BSTNode(data); }
};


template<typename T>
BSTNode<T>::BSTNode(BSTNode& b) {
#ifdef debug
	cout << "BSTNode copy constructor called, _data == " << _data << endl;
#endif
	_data = b._data;
	_left = _right = nullptr;
	if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
	if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
}


template<typename T>
BSTNode<T>::~BSTNode() {
#ifdef debug
	cout << "BSTNode destructor called, _data == " << _data << endl;
#endif
    delete _left;
	delete _right;
}


template<typename T>
BSTNode<T>& BSTNode<T>::operator= (BSTNode& b) {
#ifdef debug
	cout << "BSTNode copy assignment operator: ";
#endif
	_data = b._data;
	_left = _right = nullptr;
	if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
    if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
	return *this;
}


template<typename T>
void BSTNode<T>::insert(const T& data) {
	// comment out the next line when you've completed this function!
	// cout << "BSTNode<T>::insert called with data == " << data << endl;
	
	if (data == _data) {
		return;
	}
	// going to left
	else if (data < _data) {
		if (_left == nullptr) {
			_left = new BSTNode<T>(data);
			return;
		}
		else {
			_left->insert(data);
			return;
		}
	}
	// data > _data (going to right)
	else {
		if (_right == nullptr) {
			_right = new BSTNode<T>(data);
			return;
		}
		else {
			_right->insert(data);
			return;
		}
	}
}


template<typename T>
void BSTNode<T>::inOrderDisplay(ostream& out) const {
	if (_left != nullptr) {
	    _left->inOrderDisplay(out);
	    out << ", ";
	}
	out << _data;
	if (_right != nullptr) {
	    out << ", ";
	    _right->inOrderDisplay(out);
	}
}


/**
 *  ***** Complete preOrderDisplay and postOrderDisplay below *****
 */
template<typename T>
void BSTNode<T>::preOrderDisplay(ostream& out) const {
	// comment out the next line when you've completed this function!
	//cout << "BSTNode<T>::preOrderDisplay called\n";
	
	// self
	out << _data;
	// left
	if (_left != nullptr) {
	    out << ", ";
		_left->preOrderDisplay(out);
	}
	// right
	if (_right != nullptr) {
	    out << ", ";
	    _right->preOrderDisplay(out);
	}
}

template<typename T>
void BSTNode<T>::postOrderDisplay(ostream& out) const {
	// comment out the next line when you've completed this function!
	//cout << "BSTNode<T>::postOrderDisplay called\n";
	
	// left
	if (_left != nullptr) {
	    _left->postOrderDisplay(out);
	    out << ", ";
	}
	// right
	if (_right != nullptr) {
	    _right->postOrderDisplay(out);
	    out << ", ";
	}
	// self
	out << _data;
}

template<typename T>
void BSTNode<T>::listify(list<T>& li) const {
	if (_left != nullptr) {
	    _left->listify(li);
	}
	li.push_back(_data);
	if (_right != nullptr) {
	    _right->listify(li);
	}
}



int main(void) {
	BSTNode<int> iroot(100);
	iroot.insert(10);
	iroot.insert(20);
	iroot.insert(200);
	iroot.insert(300);
	cout << "iroot == " << iroot << endl;
	
	BSTNode<string> sroot("Sunday");
	sroot.insert("Monday");
	sroot.insert("Tuesday");
	sroot.insert("Wednesday");
	sroot.insert("Thursday");
	sroot.insert("Friday");
	sroot.insert("Saturday");
	cout << "sroot == " << sroot << endl;

	list<int> irootList;
	iroot.listify(irootList);

	cout << "\nCreating irootList via iroot.listify\n";
	cout << "\nirootList (forward iterator) == ";
	for (list<int>::iterator it = irootList.begin(); it != irootList.end(); ++it) {
		cout << *it << " ";
	}

	cout << "\nirootList (reverse iterator) == ";
	for (list<int>::reverse_iterator it = irootList.rbegin(); it != irootList.rend(); ++it) {
		cout << *it << " ";
	}

	cout << "\nirootList (ranged for loop) == ";
	for(auto& iroot: irootList) {
		cout << iroot << " ";
	}
	cout << "\n";

	list<string> srootList;
	sroot.listify(srootList);

	cout << "\nCreating srootList via sroot.listify\n";
	cout << "\nsrootList (forward iterator) == ";
	for (list<string>::iterator it = srootList.begin(); it != srootList.end(); ++it) {
		cout << *it << " ";
	}

	cout << "\nsrootList (reverse iterator) == ";
	for (list<string>::reverse_iterator it = srootList.rbegin(); it != srootList.rend(); ++it) {
		cout << *it << " ";
	}

	cout << "\nsrootList (ranged for loop) == ";
	for(auto& sroot: srootList) {
		cout << sroot << " ";
	}
	cout << "\n";

	BSTNode<int> iroot4(1000);
	iroot4.insert(2000);
	iroot4.insert(3000);
	iroot4.insert(4000);
	iroot4.insert(5000);
	list<int> iroot4List;
	iroot4.listify(iroot4List);

	map<string, list<int>> mi;
	mi["iroot4List"] = iroot4List;
	mi["irootList"] = irootList;

	cout << "\niroot4 = " << iroot4 << "\n" << endl;

	cout << "Creating iroot4List via iroot4.listify\n" << endl;
	cout << "Contents of map<string, list<int>> mi (using ranged for loops):" << endl;
	for(auto &iter: mi){
		cout << iter.first << ": ";
        for(auto &li: iter.second){
            cout << li << " ";
        }
		cout << endl;
	}

	cout << endl << "Using map index operator:" << endl;
	/*
		Do the map index operator print here.
	*/

#ifdef debug	
	BSTNode<int> iroot2(iroot); // use copy constructor
	cout << "\nAfter copy constructor:\n";
	cout << "iroot2 == " << iroot2 << endl;
	
	BSTNode<int> iroot3;
	iroot3 = iroot2; // use copy assignment operator
	cout << "\nAfter copy assignment operator:\n";
	cout << "iroot3 == " << iroot3 << endl << endl;
#endif
	
	return 0;
}
