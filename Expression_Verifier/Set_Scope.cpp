#include "Set_Scope.h"



Set_Scope::Set_Scope()
{
	scopeIdentifier_ = "Set";
}


Set_Scope::~Set_Scope()
{
}

string Set_Scope::add(const string& left, const string& right)const
{
	string trimmedL, trimmedR, finalSet;
	trimmedL = trimString("{", left);
	trimmedL = trimString("}", trimmedL);
	trimmedR = trimString("{", right);
	trimmedR = trimString("}", trimmedR);


	set <int> leftSet = convertToSet(trimmedL);
	set <int> rightSet = convertToSet(trimmedR);

	leftSet.insert(rightSet.begin(), rightSet.end());
	set<int>::iterator it;

	finalSet = "{";

	for (it = leftSet.begin(); it != leftSet.end(); ++it) 
	{
		finalSet += to_string(*it);
		finalSet += ",";
	}
	if (finalSet != "{")
		finalSet.erase(finalSet.size() - 1);
	finalSet += "}";
	return finalSet;

}
	

string Set_Scope::mult(const string& left, const string& right)const
{
	string trimmedL, trimmedR;
	trimmedL = trimString("{", left);
	trimmedL = trimString("}", trimmedL);
	trimmedR = trimString("{", right);
	trimmedR = trimString("}", trimmedR);


	set <int> leftSet = convertToSet(trimmedL);
	set <int> rightSet = convertToSet(trimmedR);
	string finalSet;

	finalSet = "{";
	for (set<int>::iterator i = leftSet.begin(); i != leftSet.end(); ++i)
		for (set<int>::iterator j = rightSet.begin(); j != rightSet.end(); ++j) 
			if (*i == *j)
			{
				finalSet += to_string(*i);
				finalSet += ",";
			}
	if(finalSet != "{")
		finalSet.erase(finalSet.size() - 1); 
	finalSet += "}";

	return finalSet;


	

}

set<int> Set_Scope::convertToSet(const string& myStr) const
{
	set<int> myAry;

	stringstream stream(myStr);
	string token;

	while (getline(stream, token, ',')) 
	{
		myAry.insert(stoi(token));
	}
	return myAry;
}
