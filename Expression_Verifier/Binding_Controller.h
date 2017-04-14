#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Binding_Controller
{
public:
	virtual string add(const string&, const string&) const = 0;
	virtual string mult(const string&, const string&) const = 0;
	virtual string sub(const string&, const string&) ;
	virtual string exp(const string&, const string&) ;
	bool compare(const string&, const string&);
	bool reduceExpression(string&);
protected:
	Binding_Controller();
	~Binding_Controller();
	string scopeIdentifier_;
	string delims_;
	string trimString(const string&, const string&)const;
private:
	vector<string> getTokens(const string&);	//Get tokens of subexpressions
	vector<string> tokenizeInstruction(const string&);	//tokenize based off of "="
	bool isDelim(char,const string&)const;
	int linenum_;

};
