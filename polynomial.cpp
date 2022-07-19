// musaab imran
// 20i-1794
// CS-A

#include <iostream>
#include <cmath>

// including term cpp file

using namespace std;

// polynomial class accessing terms
class Polynomial
{
public:
	class Term
	{
	public:

		// data members for the term of polynomial
		int expo;   // exponent of polynomial
		double coef;  // coefficient pf polynomial
		Term* next;  // term pointer


		// default constructor
		Term()
		{
			expo = 0;
			coef = 0.0;
			next = NULL;
		}


		// paramitrized constructor
		Term(int e, double c, Term* n)
		{
			expo = e;
			coef = c;
			next = n;
		}

		// destructor
		~Term()
		{
			next = NULL;
			delete next;
		}

	};

	// head pointer
	Term* head;

	// size of the each polynomial
	int size;


	// detault constructor
	Polynomial()
	{
		head = NULL;
		size = 0;
	}

	// paramitrized constructor
	Polynomial(int s, Term* h)
	{
		head = h;
		size = s;
	}

	// copy cunstructor
	Polynomial(Polynomial& p)
	{
		Term* current = new Term;
		Term* point = new Term;

		// check for empty list
		if (p.isEmpty())
		{
			this->head = NULL;
		}

		else
		{
			// if not empty
			this->head = NULL;
			current = p.head;
			while (current != NULL)
			{
				// calling add function
				this->add(current->coef, current->expo);
				current = current->next;
			}
		}

	}

	// gives error while multiplying
	// that is why it is commented
	/*
	~Polynomial()
	{
		Term* temp = NULL;
		while (head != NULL)
		{
			temp = head->next;
			delete head;
			
		}

	}
	*/


	// overloading = operator
	Polynomial& operator= (Polynomial& p)
	{
		Term* current = new Term;
		Term* point = new Term;


		// empty list check
		if (p.isEmpty())
		{
			this->head = NULL;
		}

		// if list is not empty
		else
		{
			this->head = NULL;
			current = p.head;
			while (current != NULL)
			{
				// calling add function to make the list
				this->add(current->coef, current->expo);
				current = current->next;
			}
		}
		return *this;
	}


	// function to check if the link list is empty
	// or not
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;

	}

	// add function to make link list
	// parameters as coeefiecent and exponent
	void add(double c, int e)
	{
		// creating a temp type node
		Term* temp = new Term;
		temp->coef = c;
		temp->expo = e;
		temp->next = NULL;

		// if no nodes
		if (head == NULL)
		{
			head = temp;
		}

		// if head is not null
		else
		{
			Term* curr = head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}

	}

	// overloading the * operator
	Polynomial& operator*(Polynomial& obj1)
	{
		// making a polynomial type object and storing the 
		// output of multiplication of the  parameter object 
		// and caller object
		Polynomial temp;
		Term* curr = head;
		Term* ltemp = obj1.head;
		Term* ftemp = NULL;

		double cval = 0.0;
		int eval = 0;

		// nested loop
		while (ltemp != NULL)
		{
			ftemp = curr;

			while (ftemp != NULL)
			{
				// multiplying the polynomials and making link list 
				// by calling add function

				cval = ftemp->coef * ltemp->coef;
				eval = ftemp->expo + ltemp->expo;
				temp.add(cval, eval);
				ftemp = ftemp->next;
			}

			// increment
			ltemp = ltemp->next;

		};

		return temp;
	}


	// overloading + operator
	Polynomial& operator+(Polynomial& obj1)
	{
		// making a polynomial type object and storing the 
		// output of addition of the parameter object and caller object
		Polynomial temp;
		Term* curr = head;

		Term* ltemp = obj1.head;
		Term* ftemp = curr;

		double val = 0.0;

		// loop till the smallest polynomial reaches NULL
		while (ltemp != NULL && ftemp != NULL)
		{

			// if the value of poly 1 is greater than poly 2
			// add poly 1 by calling add function
			if (ltemp->expo > ftemp->expo)
			{
				temp.add(ltemp->coef, ltemp->expo);

				// increment
				ltemp = ltemp->next;
			}

			// if the value of poly 2 is greater than poly 2
			// add poly 2 by calling add function
			else if (ltemp->expo < ftemp->expo)
			{
				temp.add(ftemp->coef, ftemp->expo);

				// increment
				ftemp = ftemp->next;
			}

			// if the exponents are same then add the 
			// coefficents and call the add function
			// send the added cofficent and the 
			// value of exponent
			else
			{
				val = ftemp->coef + ltemp->coef;
				temp.add(val, ftemp->expo);

				// increment
				ltemp = ltemp->next;
				ftemp = ftemp->next;

			}
		}

		// to print all the left values of the bigger
		// polynomial (link list)

		// if its the first one
		if (ftemp == NULL)
		{
			while (ltemp != NULL)
			{
				// add all the remaining values
				temp.add(ltemp->coef, ltemp->expo);

				// increment
				ltemp = ltemp->next;
			}
		}

		// if its the second one
		else if (ltemp == NULL)
		{
			while (ftemp != NULL)
			{
				// add all the remaining values
				temp.add(ftemp->coef, ftemp->expo);

				// increment
				ftemp = ftemp->next;
			}
		}

		// return the polynomial object used to 
		// stored the values of mutplication
		return temp;

	}

	/*
	=> . (memmber selector) operator overloading

	=>in the assignment we were asked to overload
	. operator but in c++ this operator cant
	be overloaded

	=>this operator is not suported by c++

	=> as i declared this it says
	" expected operator " at the place where i wrote "."

	Polynomial& operator.(Polynomial& obj1)
	{

	}
	*/

	// evaluate function 
	// to calculate the value of polymnomials
	// against a real nuber
	void evaluate(int val)
	{
		Term* temp = head;
		double finalval = 0.0;

		// loop
		while (temp != NULL)
		{
			//if the exponent is zero just add the coefficent
			if (temp->expo == 0)
			{
				finalval = finalval + temp->coef;

			}

			else
			{
				// using pow to calculate the vale
				finalval = finalval + (temp->coef * pow(val, temp->expo));
			}

			// increment
			temp = temp->next;
		}

		// displaying the result
		cout << finalval << endl;
		cout << endl;
	}

	// deleteing value
	void deleteval(Term* temp)
	{
		// deleteing the pointer
		// passed in the function

		Term* final = NULL;
		final = temp->next;
		temp->next = temp->next->next;

		// delete
		final = NULL;
		delete final;
	}

	// check function too add all the same 
	// exponent values
	void check()
	{
		Term* curr = head;
		Term* temp = NULL;

		while (curr->next != NULL)
		{
			// checking exponents
			if (curr->expo == curr->next->expo)
			{
				curr->coef = curr->coef + curr->next->coef;
				deleteval(curr);
			}

			// else keep incrementing
			else
			{
				curr = curr->next;
			}
		}

	}

	// swap function
	void swap(Term* a, Term* b)
	{
		// swaping coeffcient
		double cval;
		cval = a->coef;
		a->coef = b->coef;
		b->coef = cval;

		// swapping exponent
		int eval;
		eval = a->expo;
		a->expo = b->expo;
		b->expo = eval;
	}

	// function to call the actual sorting function
	// keep head safe
	void sortsample()
	{
		if (head == NULL)
		{
			cout << " NO INPUT!!! " << endl;

		}
		else
		{
			sort(head);
		}
	}


	// sorting 
	void sort(Term* temp)
	{
		Term* p = temp;

		while (p->next != NULL)
		{
			Term* q = temp;

			while (q->next != NULL)
			{
				// sorting based on the  exponent
				if (q->expo < q->next->expo)
				{
					// swap function
					swap(q, q->next);

				}

				// increment
				q = q->next;

			}

			// increment
			p = p->next;
		}

	}

	// function to output the polynomial
	void output()
	{
		Term* temp = head;

		// check if the link list is empty
		if (isEmpty())
		{
			return;
		}


		// if not empty print
		while (temp != NULL)
		{
			if (temp->coef == 0)
			{

			}

			// for positive vale
			if (temp->coef > 0)
			{
				cout << "+";

				if (temp->expo > 0)
				{
					cout << temp->coef << "n^" << temp->expo << " ";

				}

				else
				{
					cout << temp->coef << " ";

				}
			}

			// negative values
			if (temp->coef < 0)
			{
				if (temp->expo > 0)
				{
					cout << temp->coef << "n^" << temp->expo << " ";

				}

				else
				{
					cout << temp->coef << " ";

				}
			}

			// increment
			temp = temp->next;
		}

		cout << endl;

	}
};
