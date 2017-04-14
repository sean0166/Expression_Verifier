#pragma once
#include "Binding_Controller.h"
class String_Scope : public Binding_Controller
{
public:
	String_Scope();
	~String_Scope();
	string add(const string&, const string&)const;
	string mult(const string&, const string&)const;
};

