#pragma once
#pragma warning( disable : 4996 )
#include <algorithm>
#include <set>
#include "Binding_Controller.h"
class Set_Scope : public Binding_Controller
{
public:
	Set_Scope();
	~Set_Scope();
	string add(const string&, const string&)const;
	string mult(const string&, const string&)const;
private:
	set<int> convertToSet(const string&)const;
};
