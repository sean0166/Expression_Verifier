#include "Binding_Controller.h"
#pragma once
class Algebra_Scope : public Binding_Controller
{
public:
	Algebra_Scope();
	~Algebra_Scope();
	void add();
	void sub();
	void mult();
	void exp();
	void compare();

};

