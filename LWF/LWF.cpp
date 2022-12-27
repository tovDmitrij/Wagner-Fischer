#include <iostream>
#include "WF.h"
#include "WFOpt.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	WF* wf = new WF();

	const char* first = "no";
	const char* second = "ono";

	wf->Init(first, second);
	for (int i = 0; i < wf->Rows(); i++) {
		for (int j = 0; j < wf->Columns(); j++) {
			cout << wf->Get(i, j) << " ";
		}
		cout << endl;
	}
	cout << "Расстояние: " << wf->Distance() << endl;
	delete wf;

	cout << "Расстояние (оптимизированный расчёт): " << Distance(first, second);
}