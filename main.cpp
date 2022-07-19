// musaab imran
// 20i-1794
// CS-A

#include <iostream>

// including polynomial.cpp

#include "polynomial.cpp"
using namespace std;

int main()
{

    // declaring objects and variables
    Polynomial p1, p2, p3, p4;
    int size = 0, exp = 0, choice = 0;
    double coe = 0.0;

    // main menu for asking for input
finalmenu:
    cout << "\t\t\t\ ::POLYNOMIAL CALCULATOR::" << endl;
    cout << " 1. INPUT: " << endl; \
    cout << " 2. ADD: " << endl;
    cout << " 3. MULTIPLY: " << endl;
    cout << " 4. EVALUATE: " << endl;
    cout << " 5. OUTPUT: " << endl;
    cout << " 6. EXIT: " << endl;
    cout << " ENTER: ";
    cin >> choice;

    switch (choice)
    {

        // asking for the input 
    case 1:
        cout << "\t\t\t\ ::POLYNOMIAL 01::" << endl;

    sub1:
        cout << " Enter the size of the polynomial 01: ";
        cin >> size;
        cout << endl;

        // size should be equal or greater than 0
        if (size <= 0)
        {
            cout << " Enter size again!!! " << endl;
            cout << endl;
            goto sub1;
        }

        // asking for the exponent and coefficient
        for (int i = 0; i < size; i++)
        {
        menu:

            cout << " Enter the exponent of the " << i + 1 << " term: ";
            cin >> exp;


            // exponent of the polynomial cant be less than 0
            if (exp < 0)
            {
                cout << endl;
                cout << " Enter exponent again. " << endl;
                cout << endl;
                goto menu;
            }

            // asking for the coffiecents
            cout << " Enter the coefficient of the " << i + 1 << " term: ";
            cin >> coe;
            cout << endl;
            if (coe == 0)
            {
                p1.add(0, exp);
            }

            else
            {
                p1.add(coe, exp);
            }

        };

        // calling sort function
        p1.sortsample();

        // calling check function which adds the values that
        // the user input which were of same exponent
        p1.check();

        // displaying the polynomial
        cout << " Polynomial 01: ";
        p1.output();
        cout << endl;
        cout << endl;



        // asking for the exponent and cofficent of the second polynomial
        cout << "\t\t\t\ ::POLYNOMIAL 02::" << endl;

    sub2:
        cout << " Enter the size of the polynomial 02: ";
        cin >> size;


        // size check of polynomial 2
        if (size <= 0)
        {
            cout << " Enter size again!!! " << endl;
            cout << endl;
            goto sub2;
        }
        cout << endl;

        // input
        for (int i = 0; i < size; i++)
        {
        menu1:

            cout << " Enter the exponent of the " << i + 1 << " term: ";
            cin >> exp;


            // exponent check
            if (exp < 0)
            {
                cout << endl;
                cout << " Enter exponent again. " << endl;
                cout << endl;
                goto menu1;
            }

            // asking coefficent 
            cout << " Enter the coefficient of the " << i + 1 << " term: ";
            cin >> coe;
            cout << endl;

            if (coe == 0)
            {
                p2.add(0, exp);
            }

            else
            {
                p2.add(coe, exp);
            }

        };

        // sorting the whole link list
        p2.sortsample();

        // calling check function which adds the values that
        // the user input which were of same exponent
        p2.check();


        // displaying the second polynomial
        cout << " Polynomial 02: ";
        p2.output();
        cout << endl;

        // calling the main menu
        goto finalmenu;

        // addition of the two polynomials
    case 2:
        cout << endl;
        cout << " Addition: ";
        p3 = p1 + p2;
        p3.output();
        cout << endl;

        // calling the main menu
        goto finalmenu;

        // multiplying the two polynomials
    case 3:

        cout << endl;
        cout << " Multiplication: ";
        p4 = p1 * p2;

        // sorting the resultant
        p4.sortsample();

        // checking for the same exponents
        p4.check();

        // displaying
        p4.output();
        cout << endl;

        // calling the main menu
        goto finalmenu;

        // evaluting the answer for the both polynomial for real value
    case 4:
        int n1, n2;
        cout << endl;
        cout << " Evalution: " << endl;

        // output of the first polynomial
        cout << " Enter real number for polynomial 01: ";
        cin >> n1;
        cout << " Result 01: ";
        p1.evaluate(n1);


        // output of the seconf polynomial
        cout << " Enter real number for polynomial 02: ";
        cin >> n2;
        cout << " Result 02: ";
        p2.evaluate(n2);

        // calling the main menu
        goto finalmenu;


        // displaying case
    case 5:
        cout << endl;
        cout << " Outputs: " << endl;

        // first polynomial display
        cout << " Polynomial 01: ";
        p1.output();
        cout << endl;


        // second polynomial display
        cout << " Polynomial 02: ";
        p2.output();
        cout << endl;

        // calling the main menu
        goto finalmenu;

        // break case
        // to exit the code
    case 6:
        break;
    }

    return 0;

}
