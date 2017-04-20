#include "Binding_Controller.h"



Binding_Controller::Binding_Controller():
	linenum_(0),
	scopeIdentifier_(""),
	delims_("()+-*^")
{
}
Binding_Controller::~Binding_Controller()
{
}

string Binding_Controller::sub(const string &, const string &)
{
	return string();
}

string Binding_Controller::exp(const string &, const string &)
{
	return string();
}

bool Binding_Controller::verifyInstruction(const string & instruction)
{
	vector<string>* tokens = new vector<string>();
	vector<string> reducedExpressions;
	vector<string>::iterator it;

	*tokens = tokenizeInstruction(instruction);

	for (it = tokens->begin(); it != tokens->end(); ++it)     
		reducedExpressions.push_back(reduceExpression(*it));  

	delete tokens;
	tokens = NULL;

	for (int i = 0; i < reducedExpressions.size() - 1; ++i)
	{
		if (reducedExpressions.at(i) != reducedExpressions.at(i + 1))
			return false;
	}
	return true;
	
}

bool Binding_Controller::compare(const string& left, const string& right)
{
	if (!left.compare(right))
		return true;
	else
		return false;
}


string Binding_Controller::reduceExpression(const string& myStr)
{
	vector<string> tokens = getTokens(myStr);
	int highestPrecIndex;
	while (tokens.size() > 1) {
		highestPrecIndex = getHighestPrec(tokens);  ///Get index of next highest precedence
		if (tokens.at(highestPrecIndex) == "(")
		{
			string subExpr;
			int i = highestPrecIndex + 1;
			while (tokens.at(i) != ")")             /// For everything in the parenthesis
			{
				subExpr += tokens.at(i);            ///   add tokens to sub expression
				tokens.erase(tokens.begin() + i);   ///   while removing from expression
			}
			subExpr = reduceExpression(subExpr);    /// Recursively reduce the subExpr
			tokens.at(highestPrecIndex) = subExpr;
			tokens.erase(tokens.begin() + i); 
		}
		else  if (tokens.at(highestPrecIndex) == "^")
		{	
			string subExpr;
			subExpr = exp(tokens.at(highestPrecIndex - 1), tokens.at(highestPrecIndex+1));
			tokens.at(highestPrecIndex - 1) = subExpr;
			tokens.erase(tokens.begin() + highestPrecIndex);
			tokens.erase(tokens.begin() + highestPrecIndex );
		}
		else  if (tokens.at(highestPrecIndex) == "*")
		{
			string subExpr;
			subExpr = mult(tokens.at(highestPrecIndex - 1), tokens.at(highestPrecIndex + 1));
			tokens.at(highestPrecIndex - 1) = subExpr;
			tokens.erase(tokens.begin() + highestPrecIndex);
			tokens.erase(tokens.begin() + highestPrecIndex);
		}
		else  if (tokens.at(highestPrecIndex) == "+")
		{
			string subExpr;
			subExpr = add(tokens.at(highestPrecIndex - 1), tokens.at(highestPrecIndex + 1));
			tokens.at(highestPrecIndex - 1) = subExpr;
			tokens.erase(tokens.begin() + highestPrecIndex);
			tokens.erase(tokens.begin() + highestPrecIndex);
		}
		else  if (tokens.at(highestPrecIndex) == "-")
		{
			string subExpr;
			subExpr = sub(tokens.at(highestPrecIndex - 1), tokens.at(highestPrecIndex + 1));
			tokens.at(highestPrecIndex - 1) = subExpr;
			tokens.erase(tokens.begin() + highestPrecIndex);
			tokens.erase(tokens.begin() + highestPrecIndex);
		}
	}
	return tokens.at(0);
}
//Returns vector of tokens delimited by the delims_ string ie. the non-operators
vector<string> Binding_Controller::getTokens(const string& myStr)
{
	vector<string> tokens;
	stringstream stream(myStr);
	string temp;
	char curChar = stream.get();
	while (curChar != EOF) 
	{
		if (!isDelim(curChar,delims_))
			temp += curChar;
		else 
		{
			if (!temp.empty())
				tokens.push_back(temp);
			temp.clear();
			tokens.push_back(string(1,curChar));
		}
		curChar = stream.get();
	}
	if (!temp.empty())
		tokens.push_back(temp);	//Retrieve the last token
	return tokens; 
	
}
//Determines if the supplied string is contained in "delims" string
bool Binding_Controller::isDelim(char c, const string& delims) const
{
	for (int i = 0; i < delims.size(); i++)
		if (delims[i] == c)
			return true;
	return false;
}
//Returns a vector containing expressions delimited by '='
vector<string> Binding_Controller::tokenizeInstruction(const string& myStr)
{
	vector<string> myAry;

	stringstream stream(myStr);
	string token;

	while (getline(stream, token, '='))
	{
		myAry.push_back(token);
	}
	return myAry;
}
//Loop through tokens and return the index of the highest precedence
int Binding_Controller::getHighestPrec(vector<string> tokens)
{
	int maxPrecValue = -1;
	int maxPrecIndex = -1;
	for (int i = 0; i < tokens.size(); ++i)
	{
		if (tokens.at(i) == "(")
		{
			maxPrecValue = 4;
			maxPrecIndex = i;
		}
		else if (tokens.at(i) == "^")
		{
			if (maxPrecValue < 3) 
			{
				maxPrecValue = 3;
				maxPrecIndex = i;
			}
		}
		else if (tokens.at(i) == "*")
		{
			if (maxPrecValue < 2) 
			{
				maxPrecValue = 2;
				maxPrecIndex = i;
			}
		}
		else if (tokens.at(i) == "+")
		{
			if (maxPrecValue < 1) 
			{
				maxPrecValue = 1;
				maxPrecIndex = i;
			}
		}
		else if (tokens.at(i) == "-")
		{
			if (maxPrecValue < 0) 
			{
				maxPrecValue = 0;
				maxPrecIndex = i;
			}
		}
	}
	return maxPrecIndex;
}

string Binding_Controller::trimString(const string& delim, const string& myStr)const
{
	stringstream stream(myStr);
	string retString;
	char curChar = stream.get();
	while (curChar != EOF)
	{
		if (!isDelim(curChar, delim))
			retString += curChar;
		curChar = stream.get();
	}
	return retString;
}


void Binding_Controller::incrLinenum()
{
	linenum_++;
}

int Binding_Controller::getLinenum()
{
	return linenum_;
}

string Binding_Controller::getScopeIdentifier()
{
	return scopeIdentifier_;
}
