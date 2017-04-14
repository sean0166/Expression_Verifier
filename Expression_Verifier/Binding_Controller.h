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
	virtual string sub(const string&, const string&) const = 0;
	virtual string exp(const string&, const string&) const = 0;
	bool compare(const string&, const string&);
	bool reduceExpression(string&);
	vector<string> getTokens(const string& myStr);

	string tokenizeInstruction(const string&);
protected:
	int linenum_;
	int scopeIdentifier_;

};
