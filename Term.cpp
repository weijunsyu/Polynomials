

#include "Term.h"


Term::Term() {
    coeff = 0;
    deg_x = 0;
    deg_y = 0;
    next = nullptr;
}

Term::Term(int coeff, int deg_x, int deg_y) {
    this->coeff = coeff;
    this->deg_x = deg_x;
    this->deg_y = deg_y;
    next = nullptr;
}

Term::Term(const Term& other) {
    this->coeff = other.coeff;
    this->deg_x = other.deg_x;
    this->deg_y = other.deg_y;
    this->next = other.next;
}

Term& Term::operator = (const Term& rtSide) {
    if (this != &rtSide) {
        this->coeff = rtSide.coeff;
        this->deg_x = rtSide.deg_x;
        this->deg_y = rtSide.deg_y;
        this->next = rtSide.next;
    }
    return *this;
}

//get the coeffcient value for the term
int Term::getCoeff() const{
    return coeff;
}
//get the degree of the x variable
int Term::getX() const {
    return deg_x;
}
//get the degree of the y variable
int Term::getY() const {
    return deg_y;
}
//get next term or nullptr if none
Term* Term::getNext() const {
    return next;
}

//set the value of the coeffcient
void Term::setCoeff(int coeff) {
    this->coeff = coeff;
}
//set the degree of the x variable
void Term::setX(int degree) {
    deg_x = degree;
}
//set the degree of the y variable
void Term::setY(int degree) {
    deg_y = degree;
}
//set the next term
void Term::setNext(Term* next) {
    this->next = next;
}

//print the term (do not print if the term is 0)
void Term::print() const {
    if (coeff != 0) {
        if (coeff > 0) {
            std::cout << "+" << coeff << "x^" << deg_x << "y^" << deg_y << " ";
        }
        else {
            std::cout << coeff << "x^" << deg_x << "y^" << deg_y << " ";
        }
    }
}
