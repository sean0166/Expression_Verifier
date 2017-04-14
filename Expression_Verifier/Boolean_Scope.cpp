#include "Boolean_Scope.h"



Boolean_Scope::Boolean_Scope()
{
	scopeIdentifier_ = "Boolean";
}


Boolean_Scope::~Boolean_Scope() {
}
string Boolean_Scope::add(const string& left, const string& right)const{
	return to_string((stoi(left) | stoi(right)));
}
string Boolean_Scope::mult(const string& left, const string& right)const{
	return to_string((stoi(left) & stoi(right)));
}