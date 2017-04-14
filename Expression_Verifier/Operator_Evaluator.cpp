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
			 cout << scopeType;
			 if (scopeType == "strings")
				 scopes.push_back(new String_Scope()); 
			 else if (scopeType == "algebra")
				 scopes.push_back(new Algebra_Scope());
			 else if (scopeType == "boolean")
				 scopes.push_back(new Boolean_Scope());
			 else if (scopeType == "sets")
				 scopes.push_back(new Set_Scope());
			 else {
				 //no point of setting null when vector will go out of scope after method
				 delete scopes.back();
				 scopes.pop_back();
			 }
		}
		else
		{
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