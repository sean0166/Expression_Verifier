#pragma once
#include "Binding_Controller.h"
class Algebra_Scope : public Binding_Controller
{
public:
	Algebra_Scope();
	~Algebra_Scope();
	string add(const string&, const string&)const;
	string sub(const string&, const string&)const;
	string mult(const string&, const string&)const;
	string exp(const string&, const string&)const;

};

