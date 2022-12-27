#pragma once
#include <list>
using namespace std;

/// <summary>
/// Алгоритм Вагнера-Фишера
/// </summary>
class WF
{
private:
	/// <summary>
	/// Целочисленная матрица
	/// </summary>
	int* pm;

	/// <summary>
	/// Количество строк
	/// </summary>
	int M;

	/// <summary>
	/// Количество столбцов
	/// </summary>
	int N;

	/// <summary>
	/// Строки для сравнения расстояния между ними
	/// </summary>
	const char* s;
	const char* t;

	/// <summary>
	/// Расстояние между строками
	/// </summary>
	int distance;
public:
	WF() {}

	WF(const WF&) = delete;

	~WF() {
		delete[]pm;
	}

	/// <summary>
	/// Инициализация матрицы и строк
	/// </summary>
	/// <param name="sc">Первая строка</param>
	/// <param name="tc">Вторая строка</param>
	void Init(const char* sc, const char* tc) {
		s = sc;
		t = tc;
		M = strlen(s) + 1;
		N = strlen(t) + 1;
		pm = new int[M * N];



#pragma region Алгоритм Вагнера-Фишера

		int count = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (i == 0 && j == 0) {
					Set(i, j, 0);
				}
				else if (j == 0 && i > 0) {
					Set(i, j, i);
				}
				else if (i == 0 && j > 0) {
					Set(i, j, j);
				}
				else {
					int currentValues[3] /*{
						Get(i, j - 1) + 1,
						Get(i - 1, j) + 1,
						Get(i - 1, j - 1) + s[i - 1] == t[j - 1] ? 0 : 1
					}*/;	
					//Почему-то в некоторых случаях сумма в 3-м элементе не срабатывает и вместо + 1 делает + 0, а по отдельности, как написано ниже, работает. Возможно, что проблема в тернарном операторе...
					currentValues[0] = Get(i, j - 1) + 1;
					currentValues[1] = Get(i - 1, j) + 1;
					int s1 = s[i - 1] == t[j - 1] ? 0 : 1;
					currentValues[2] = Get(i - 1, j - 1) + s1;

					int min = currentValues[0];
					for (int k = 0; k < 3; k++) {
						if (currentValues[k] < min) {
							min = currentValues[k];
						}
					}
					Set(i, j, min);
				}
			}
		}
		distance = pm[M * N - 1];

#pragma endregion



	}

	/// <summary>
	/// Получить количество строк матрицы
	/// </summary>
	int Rows() const {
		return M;
	}

	/// <summary>
	/// Получить количество столбцов матрицы
	/// </summary>
	int Columns() const {
		return N;
	}

	/// <summary>
	/// Получение элемента матрицы, находящегося на пересечении i-строки и j-столбца
	/// </summary>
	/// <param name="i">Номер строки</param>
	/// <param name="j">Номер столбца</param>
	int Get(int i, int j)const {
		if (i > M || j > N) {
			throw out_of_range("An error occured when the program tried to get the value!");
		}
		return pm[i * N + j];
	}

	/// <summary>
	/// Задать значение элемента матрицы
	/// </summary>
	/// <param name="i">Номер строки</param>
	/// <param name="j">Номер столбца</param>
	/// <param name="val">Значение</param>
	void Set(int i, int j, int val) {
		if (i > M || j > N) {
			throw out_of_range("An error occured when the program tried to get the value!");
		}
		pm[i * N + j] = val;
	}

	/// <summary>
	/// Получить расстояние между строками
	/// </summary>
	int Distance() const{
		return distance;
	}

	void operator = (const WF&) = delete;
};