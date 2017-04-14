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

bool Binding_Controller::compare(const string& left, const string& right)
{
	if (!left.compare(right))
		return true;
	else
		return false;
}

bool Binding_Controller::reduceExpression(string& myStr)
{
	vector<string> tokens = getTokens(myStr);
	return 0;
}

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
		}
		curChar = stream.get();
	}
	if (!temp.empty())
		tokens.push_back(temp);	//Retrieve the last token
	return tokens; 
	
}
bool Binding_Controller::isDelim(char c, const string& delims) const
{
	for (int i = 0; i < delims.size(); i++)
		if (delims[i] == c)
			return true;
	return false;
}

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

int Binding_Controller::getHighestPrec(vector<string> tokens)
{
	int maxPrecValue = -1;
	int maxPrecIndex;
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
