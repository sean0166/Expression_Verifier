#include "Set_Scope.h"



Set_Scope::Set_Scope()
{
}


Set_Scope::~Set_Scope()
{
}

string Set_Scope::add(const string& left, const string& right)
{
	vector <int> leftSet = convertToArray(left);
	vector <int> rightSet = convertToArray(right);
}

string Set_Scope::mult(const string& left, const string& right)
{
}

vector<int> convertToArray(const string& myStr) 
{
	vector<string> myAry;

	stringstream stream(myStr);
	string token;

	while (getline(stream, token, ',')) 
	{
		myAry.push_back(token);
	}
}
