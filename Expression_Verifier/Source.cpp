#include <vector>
#include "Algebra_Scope.h"
int main(int argc, char** argv) 
{
	string myStr = "(11+222+333";

	Algebra_Scope* bc = new Algebra_Scope();
	cout << bc->getTokens(myStr).at(2);

	system("pause");
	return 0;
}

