#include "Algebra_Scope.h"



Algebra_Scope::Algebra_Scope(){
}


Algebra_Scope::~Algebra_Scope(){
}

string Algebra_Scope::add(const string& left, const string& right)
{
	return to_string(stoi(left) + stoi(right));	
}
string Algebra_Scope::sub(const string& left, const string& right)
{
	return to_string(stoi(left) - stoi(right));
}
string Algebra_Scope::mult(const string& left, const string& right)
{
	return to_string(stoi(left) * stoi(right));
}
string Algebra_Scope::exp(const string& left, const string& right)
{
	return to_string(stoi(left) ^ stoi(right));

}