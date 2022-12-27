#include "WFOpt.h"
#include <string.h>
#include <iostream>
using namespace std;

/// <summary>
/// Алгоритм Вагнера-Фишера (оптимизированный)
/// </summary>
/// <param name="s">Первая строка</param>
/// <param name="t">Вторая строка</param>
/// <returns>Расстояние между строками</returns>
int Distance(const char* s, const char* t) {
	int M = strlen(s) + 1;
	int N = strlen(t) + 1;

	int* p1 = new int[N];
	int* p2 = new int[M];
	for (int j = 0; j < N; j++) {
		p1[j] = j;
		cout << p1[j] << " ";
	}
	cout << endl;

	for (int count = 1; count < M; count++) {
		for (int i = 0; i < N; i++) {

			if (i == 0) {
				p2[i] = count;
			}
			else {
				int currentValues[3];
				currentValues[0] = p2[i - 1] + 1;
				currentValues[1] = p1[i] + 1;
				int s1 = s[count - 1] == t[i - 1] ? 0 : 1;
				currentValues[2] = p1[i - 1] + s1;

				int min = currentValues[0];
				for (int k = 0; k < 3; k++) {
					if (currentValues[k] < min) {
						min = currentValues[k];
					}
				}
				p2[i] = min;
			}
			cout << p2[i] << " ";
		}
		cout << endl;
		swap(p1, p2);
	}

	int result = p1[M];
	delete[]p1;
	//delete[]p2;

	return result;
}