#pragma once
#include "Binding_Controller.h"
class Set_Scope : public Binding_Controller
{
public:
	Set_Scope();
	~Set_Scope();
	string add(const string&, const string&);
	string mult(const string&, const string&);
	vector<string> convertToArray(const string&);
};

