

#include "Term.h"
#include <iostream>
#include <fstream>



class Poly {
    public:
        //construct new polynomial equal to 0
        Poly();

        //copy constructor
        Poly(const Poly& other);

        //destructor
        ~Poly();

        //assignment operator
        Poly& operator = (const Poly& rtSide);

        //plus operator
        Poly& operator + (const Poly& rtSide) const;

        //print the polynomial
        void print() const;

        //check if the polynomial is the zero polynomial
        bool isZero() const;

        //add a term to the polynomial from the front
        void addTerm(int coeff, int deg_x, int deg_y);

        //reset polynomial be empty (0 polynomial containing no terms)
        void clear();

        //sort the polynomial in decending order based on first the degree of x
        // then y if the degree of x is the same
        void mergeSort();

        //differentiate the polynomial with respect to x
        void ddx();

        //differentiate the polynomial with respect to y
        void ddy();



    private:
        //pointer to the start of the polynomial (first term)
        Term* head;

        //delete the polynomial
        static void deletePoly(Term* &p);

        //construct a new term
        static Term* cons(int c, int x, int y, Term* next);

        //deep copy of a polynomial
        static Term* copy(Term* p);

        //merge "lists" left and right; combine the 2 polynomials left and right
        //used in mergeSort
        Term* merge(Term* left, Term* right);

        //perform mergesort on the polynomial poly (recursive)
        void mergeSort(Term* &poly);

        //debug tool to print the polynomial poly (instead of from head)
        static void print(Term* poly);

        //return the sum of a and b
        static Term* add(Term* a, Term* b);

};
