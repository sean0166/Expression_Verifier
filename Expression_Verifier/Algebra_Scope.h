#pragma once
#include "Binding_Controller.h"
class Algebra_Scope : public Binding_Controller
{
public:
	Algebra_Scope();
	~Algebra_Scope();
	string add(const string&, const string&);
	string sub(const string&, const string&);
	string mult(const string&, const string&);
	string exp(const string&, const string&);

};

