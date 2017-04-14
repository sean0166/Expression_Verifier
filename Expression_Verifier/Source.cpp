#include <string>
#include <iostream>
#include "Operator_Evaluator.h"
using namespace std;
int main(int argc, char** argv) 
{
	string s1 = " {  1,2,5,1} 1 ";
	string s2 = "{1,2,3,7,5,3,100}";

	Operator_Evaluator* oe = new Operator_Evaluator();
	oe->run("testFile.txt");
	

	system("pause");
	return 0;
}

