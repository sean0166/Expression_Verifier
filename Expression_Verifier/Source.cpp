#include <string>
#include <iostream>
#include "Operator_Evaluator.h"
using namespace std;
int main(int argc, char** argv) 
{
	string fileName;
	cout << "Enter the name of your file:" << endl;
	cin >> fileName; 

	Operator_Evaluator* oe = new Operator_Evaluator();
	oe->run(fileName);

	delete oe;
	oe = NULL;

	system("pause");
	return 0;
}

