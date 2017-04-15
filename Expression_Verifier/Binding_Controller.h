#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Binding_Controller
{
public:
	Binding_Controller();
	~Binding_Controller();
	virtual string add(const string&, const string&) const = 0;
	virtual string mult(const string&, const string&) const = 0;
	virtual string sub(const string&, const string&) ;
	virtual string exp(const string&, const string&) ;
	bool verifyInstruction(const string&);
	bool compare(const string&, const string&);
	void incrLinenum();
	int getLinenum();
	string getScopeIdentifier();
protected:
	string trimString(const string&, const string&)const;
	bool isDelim(char c, const string&) const;
	string scopeIdentifier_;
	string delims_;
private:
	vector<string> getTokens(const string&);			//Get tokens of subexpressions
	vector<string> tokenizeInstruction(const string&);	//tokenize based off of '='
	string reduceExpression(const string&);				//reduce expression based off of precedence of operators
	int getHighestPrec(vector<string> tokens);
	int linenum_;

};
