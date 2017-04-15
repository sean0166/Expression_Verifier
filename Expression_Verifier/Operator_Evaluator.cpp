#include "Operator_Evaluator.h"



Operator_Evaluator::Operator_Evaluator()
{
}


Operator_Evaluator::~Operator_Evaluator()
{
}


bool Operator_Evaluator::run(const string& fileName)
{
	ifstream myFile(fileName);
	string instruction, scopeType;
	while (getline(myFile, instruction)) 
	{
		instruction = trimWhiteSpace(instruction);
		if (instruction[0] == '<')
		{
			 scopeType = getScopeType(instruction); 
			 if (scopeType == "strings")
				 scopes.push(new String_Scope()); 
			 else if (scopeType == "algebra")
				 scopes.push(new Algebra_Scope());
			 else if (scopeType == "boolean")
				 scopes.push(new Boolean_Scope());
			 else if (scopeType == "sets")
				 scopes.push(new Set_Scope());
			 else {
				 //no point of setting null when vector will go out of scope after pop
				 delete scopes.top();
				 scopes.pop();
			 }
		}
		else
		{
			scopes.top()->reduceExpression(instruction);
		}
	}

	return false;
}
string Operator_Evaluator::trimWhiteSpace(const string& myStr)
{
	stringstream stream(myStr);
	string retString;
	char curChar = stream.get();
	while (curChar != EOF)
	{
		if (curChar != ' ')
			retString += curChar;
		curChar = stream.get();
	}
	return retString;
}

string Operator_Evaluator::getScopeType(const string& myInstr)
{
	stringstream stream(myInstr);
	string scopeType;
	char curChar = stream.get();
	curChar = stream.get();
	while (curChar != EOF)
	{
		if (curChar != '>')
			scopeType += curChar;
		curChar = stream.get();
	}
	return scopeType;

	return 0;
}
