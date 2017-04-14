#pragma once
#include "Binding_Controller.h"
class Boolean_Scope : public Binding_Controller
{
public:
	Boolean_Scope();
	~Boolean_Scope();
	string add (const string&, const string&)const;
	string mult (const string&, const string&)const;
};

