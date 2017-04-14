#include <iostream>
#include "Set_Scope.h"
int main(int argc, char** argv) 
{
	string s1 = "{1,2,5,1}";
	string s2 = "{1,2,3,7,5,3,100}";
	Set_Scope* ss = new Set_Scope();
	cout << ss->mult(s1, s2);
	
	system("pause");
	return 0;
}

