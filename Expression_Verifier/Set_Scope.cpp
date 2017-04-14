#include "Set_Scope.h"



Set_Scope::Set_Scope()
{
}


Set_Scope::~Set_Scope()
{
}

string Set_Scope::add(const string& left, const string& right)
{
	vector <string> leftSet = convertToArray(left);
	vector <string> rightSet = convertToArray(right);
	return "";
}

string Set_Scope::mult(const string& left, const string& right)
{
	return "";
}

vector<string> Set_Scope::convertToArray(const string& myStr) 
{
	vector<string> myAry;

	stringstream stream(myStr);
	string token;

	while (getline(stream, token, ',')) 
	{
		myAry.push_back(token);
	}
	return myAry;
}
