#pragma once
#include "Binding_Controller.h"
class Algebra_Scope : public Binding_Controller
{
public:
	Algebra_Scope();
	~Algebra_Scope();
	int add();
	void sub();
	void mult();
	void exp();
	void compare();

};

