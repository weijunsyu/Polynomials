
#include <iostream>

class Term {
    public:
        Term(); //default constructor set everything to 0 (term == 0)
        Term(int coeff, int deg_x, int deg_y);
        Term(const Term& other);
        Term& operator = (const Term& rtSide);

        //get the coeffcient value for the term
        int getCoeff() const;
        //get the degree of the x variable
        int getX() const;
        //get the degree of the y variable
        int getY() const;
        //get next term or nullptr if none
        Term* getNext() const;

        //set the value of the coeffcient
        void setCoeff(int coeff);
        //set the degree of the x variable
        void setX(int degree);
        //set the degree of the y variable
        void setY(int degree);
        //set the next term
        void setNext(Term* next);
        //print the term (do not print if the term is 0)
        void print() const;

    private:
        int coeff;
        int deg_x;
        int deg_y;
        //pointer to the next term
        Term* next;


};
