#pragma once
#include <fstream>
#include <stack>
#include <vector>
#include "Binding_Controller.h"
#include "Algebra_Scope.h"
#include "Boolean_Scope.h"
#include "Set_Scope.h"
#include "String_Scope.h"
class Operator_Evaluator 
{
public:
	Operator_Evaluator();
	~Operator_Evaluator();
	bool run(const string&);
private:
	string trimWhiteSpace(const string&);
	string getScopeType(const string&);
	stack<Binding_Controller*> scopes;
};
