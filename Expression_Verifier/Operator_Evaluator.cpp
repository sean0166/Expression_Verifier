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
	while (getline(myFile, instruction))              ///loop through myFile setting instruction equal to each line
	{
		instruction = trimWhiteSpace(instruction);
		if (instruction[0] == '<')
		{
			 scopeType = getScopeType(instruction); 
			 if (scopeType == "strings")            
				 scopes_.push(new String_Scope()); 
			 else if (scopeType == "algebra")
				 scopes_.push(new Algebra_Scope());
			 else if (scopeType == "boolean")
				 scopes_.push(new Boolean_Scope());
			 else if (scopeType == "sets")
				 scopes_.push(new Set_Scope());
			 else {
				 //no point of setting null when vector will go out of scope after pop
				 delete scopes_.top();
				 scopes_.pop();
			 }
		}
		else
		{
			if (instruction != "") 
			{
				scopes_.top()->incrLinenum();
				if (!scopes_.top()->verifyInstruction(instruction))
					cout << "Instruction #" << scopes_.top()->getLinenum() << " in the " << scopes_.top()->getScopeIdentifier() << " scope is invalid!:" << endl << instruction  << endl;
			}
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
