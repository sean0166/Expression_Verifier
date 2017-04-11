#pragma once
#include "Binding_Controller.h"
class Boolean_Scope : public Binding_Controller
{
public:
	Boolean_Scope();
	~Boolean_Scope();
	void add();
	void mult();
	void compare();
};

