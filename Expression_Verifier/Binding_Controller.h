#ifndef BINDING_CONTROLLER__
#define BINDING_CONTROLLER__

#include <string>
#include <iostream>
using namespace std;
class Binding_Controller
{
public:
	Binding_Controller();
	~Binding_Controller();
	virtual void add() const = 0;
	virtual void mult() const = 0;
	virtual void sub() const = 0;
	virtual void exp() const = 0;
	virtual void compare() const = 0;
	void reduceExpression();

	string tokenizeInstruction(string);


	int linenum_;
	int scopeIdentifier_;

};

#endif