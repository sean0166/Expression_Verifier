#pragma once
#include <vector>
#include "Binding_Controller.h"

class Operator_Evaluator
{
public:
	Operator_Evaluator();
	~Operator_Evaluator();
private:
	vector<Binding_Controller*> scopes;
};

