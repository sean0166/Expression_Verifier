#include "String_Scope.h"



String_Scope::String_Scope()
{
}


String_Scope::~String_Scope()
{
}

string String_Scope::add(const string& left, const string& right)const
{
	return (left + right);
}

string String_Scope::mult(const string& left, const string& right)const
{
	int iter = stoi(right);
	string finalStr;
	for (int i = 0; i < iter; i++)
		finalStr += left;
	return finalStr;
}

