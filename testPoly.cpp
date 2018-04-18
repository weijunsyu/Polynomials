

#include <iostream>

#include "Poly.h"

int main() {
    Poly a; //create "empty" polynomial a
    Poly b; //create "empty" polynomial b
    while (true) { //loop until bad input

        for (int pair = 0; pair < 2; pair++) { //do twice to get poly a and b
            int numTerms;
            if (!(std::cin >> numTerms)) { //check if reading was successfull
                return 0; //if not exit
            }
            for (int i = 0; i < numTerms; i++) {
                int coeff, deg_x, deg_y;
                if (!(std::cin >> coeff >> deg_x >> deg_y)) {
                    return 0; //shouldnt ever be reached assuming proper input
                }
                if (pair == 0) { //check if on first polynomial (a)
                    a.addTerm(coeff, deg_x, deg_y);
                    //std::cout << coeff << " " << deg_x << " " << deg_y << " \n";
                }
                else { //otherwise, on second polynomial (b)
                    b.addTerm(coeff, deg_x, deg_y);
                    //std::cout << coeff << " " << deg_x << " " << deg_y << " \n";
                }
            }
            std::cout << "\n";
        }
        std::cout << "===================================\n";
        std::cout << "unsorted\n";
        std::cout << "poly 1: ";
        a.print();
        std::cout << "poly 2: ";
        b.print();
        a.mergeSort();
        b.mergeSort();
        std::cout << "a: ";
        a.print();
        std::cout << "b: ";
        b.print();
        std::cout << "a + b: ";
        Poly c = (a+b);
        c.print();

        std::cout << "da/dx: ";
        a.ddx();
        a.print();
        std::cout << "da/dy: ";
        a.ddy();
        a.print();
        std::cout << "db/dx: ";
        b.ddx();
        b.print();
        std::cout << "db/dy: ";
        b.ddy();
        b.print();
        std::cout << "===================================\n";

        a.clear();
        b.clear();
    }


    return 0;
}
