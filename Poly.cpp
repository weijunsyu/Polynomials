

#include "Poly.h"

//comparison functor:
struct Compare {
    int operator()(int x, int y) const {
        if (x > y) {
            return 0;
        }
        else if (x < y) {
            return 1;
        }
        else {
            return 2;
        }
    }
};

//mergeSort
void Poly::mergeSort() {
    mergeSort(head);
}

//overloaded mergesort (recursive helper)
void Poly::mergeSort(Term* &poly) {
    //if polynomial is empty or only has one term then it is already sorted
    if (poly == nullptr || poly->getNext() == nullptr) {
        return;
    }
    Term* fast = poly;
    Term* middle = poly;
    int counter = 1;
    while (fast->getNext() != nullptr) {
        fast = fast->getNext();
        if (counter % 2 == 0) {
            middle = middle->getNext();
        }
        counter++;
    } // middle points to the middle term

    //split up polynomial into left and right
    Term* right = middle->getNext();

    middle->setNext(nullptr);
    Term* left = poly;

    mergeSort(left);
    mergeSort(right);
    poly = merge(left, right);
}

//merge 2 polyomials left and right (recursive)
Term* Poly::merge(Term* left, Term* right) {
    if (left == nullptr) {
        return right;
    }
    else if (right == nullptr) {
        return left;
    }
    else {
        Compare comp;
        int compare = comp(left->getX(), right->getX());
        if (compare == 0) {
            left->setNext(merge(left->getNext(), right));
            return left;
        }
        else if (compare == 1) {
            right->setNext(merge(right->getNext(), left));
            return right;
        }
        else {
            Compare comp2;
            int secondComp = comp2(left->getY(), right->getY());
            if (secondComp == 0) {
                left->setNext(merge(left->getNext(), right));
                return left;
            }
            else if (secondComp == 1) {
                right->setNext(merge(right->getNext(), left));
                return right;
            }
        }
    }
}

//constructor
Poly::Poly() {
    head = nullptr;
}

//copy constructor
Poly::Poly(const Poly& other) {
    head = copy(other.head);
}

//destructor
Poly::~Poly() {
    deletePoly(head);
    head = nullptr;
}

//assignment operator
Poly& Poly::operator = (const Poly& rtSide) {
    if (this != &rtSide) {
        deletePoly(head);
        head = copy(rtSide.head);
    }
    return *this;
}

//plus operator
Poly& Poly::operator + (const Poly& rtSide) const {
    Poly* sum = new Poly();
    sum->head = add(head, rtSide.head);
    return *sum;
}

//adds two polynomials (helper for plus operator)
Term* Poly::add(Term* a, Term* b) {
    if (a == nullptr) {
        return b;
    }
    else if (b == nullptr) {
        return a;
    }
    else {
        Compare comp;
        int compare = comp(a->getX(), b->getX());
        if (compare == 0) {
            return cons(a->getCoeff(), a->getX(), a->getY(), add(a->getNext(), b));
        }
        else if (compare == 1) {
            return cons(b->getCoeff(), b->getX(), b->getY(), add(b->getNext(), a));
        }
        else {
            Compare comp2;
            int secondComp = comp2(a->getY(), b->getY());
            if (secondComp == 0) {
                return cons(a->getCoeff(), a->getX(), a->getY(), add(a->getNext(), b));
            }
            else if (secondComp == 1) {
                return cons(b->getCoeff(), b->getX(), b->getY(), add(b->getNext(), a));
            }
            else {
                int sum = a->getCoeff() + b->getCoeff();
                if (sum == 0) {
                    return add(a->getNext(), b->getNext());
                }
                else {
                    return cons(sum, a->getX(), a->getY(), add(a->getNext(), b->getNext()));
                }
            }
        }
    }
}

//print each term in the poly chain
void Poly::print(Term* poly) {
    Term* current = poly;
    while (current != nullptr) {
        current->print();
        current = current->getNext();
    }
    std::cout << "\n";
}

//print the polynomial
void Poly::print() const {
    if (isZero()) {
        std::cout << "0\n"; //print 0 for the zero polynomial
    }
    else {
        Term* current = head;
        while (current != nullptr) {
            current->print();
            current = current->getNext();
        }
        std::cout << "\n";
    }
}

//check if the polynomial is the zero polynomial
bool Poly::isZero() const {
    if (head == nullptr) {
        return true;
    }
    Term* current = head;
    while (current != nullptr) {
        if (current->getCoeff() != 0) {
            return false;
        }
        current = current->getNext();
    }
    return true;
}

//add a term to the front of the polynomial
void Poly::addTerm(int coeff, int deg_x, int deg_y) {
    Term* next = head;
    head = cons(coeff, deg_x, deg_y, next);
}

//reset the polynomial to 0
void Poly::clear() {
    if (head != nullptr) {
        deletePoly(head);
        head = nullptr;
    }
}

//construct new Term
Term* Poly::cons(int c, int x, int y, Term* next) {
    Term* term = new Term(c,x,y);
    term->setNext(next);
    return term;
}

//perform a deep copy of polynomial p recursively
Term* Poly::copy(Term* p) {
    if (p == nullptr) {
		return nullptr;
	}
	Term* other = cons(p->getCoeff(), p->getX(), p->getY(), copy(p->getNext()));
	return other;
}

//delete the polynomial p
void Poly::deletePoly(Term* &p) {
    Term* current = p;
    while (current != nullptr) {
        Term* next = current->getNext();
        delete current;
        current = next;
    }
}

//perform differentiation with respect to x
void Poly::ddx() {
    Term* current = head;
    while (current != nullptr) {
        int x = current->getX();
        if (x != 0) {
            current->setCoeff(x * current->getCoeff());
            current->setX(x-1);
        }
        else {
            current->setCoeff(0);
        }
        current = current->getNext();
    }
}

//perform differentiation with respect to y
void Poly::ddy() {
    Term* current = head;
    while (current != nullptr) {
        int y = current->getY();
        if (y != 0) {
            current->setCoeff(y * current->getCoeff());
            current->setY(y-1);
        }
        else {
            current->setCoeff(0);
        }
        current = current->getNext();
    }
}
