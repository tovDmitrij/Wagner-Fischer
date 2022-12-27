#pragma once
#include <list>
using namespace std;

/// <summary>
/// �������� �������-������
/// </summary>
class WF
{
private:
	/// <summary>
	/// ������������� �������
	/// </summary>
	int* pm;

	/// <summary>
	/// ���������� �����
	/// </summary>
	int M;

	/// <summary>
	/// ���������� ��������
	/// </summary>
	int N;

	/// <summary>
	/// ������ ��� ��������� ���������� ����� ����
	/// </summary>
	const char* s;
	const char* t;

	/// <summary>
	/// ���������� ����� ��������
	/// </summary>
	int distance;
public:
	WF() {}

	WF(const WF&) = delete;

	~WF() {
		delete[]pm;
	}

	/// <summary>
	/// ������������� ������� � �����
	/// </summary>
	/// <param name="sc">������ ������</param>
	/// <param name="tc">������ ������</param>
	void Init(const char* sc, const char* tc) {
		s = sc;
		t = tc;
		M = strlen(s) + 1;
		N = strlen(t) + 1;
		pm = new int[M * N];



#pragma region �������� �������-������

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
					//������-�� � ��������� ������� ����� � 3-� �������� �� ����������� � ������ + 1 ������ + 0, � �� �����������, ��� �������� ����, ��������. ��������, ��� �������� � ��������� ���������...
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
	/// �������� ���������� ����� �������
	/// </summary>
	int Rows() const {
		return M;
	}

	/// <summary>
	/// �������� ���������� �������� �������
	/// </summary>
	int Columns() const {
		return N;
	}

	/// <summary>
	/// ��������� �������� �������, ������������ �� ����������� i-������ � j-�������
	/// </summary>
	/// <param name="i">����� ������</param>
	/// <param name="j">����� �������</param>
	int Get(int i, int j)const {
		if (i > M || j > N) {
			throw out_of_range("An error occured when the program tried to get the value!");
		}
		return pm[i * N + j];
	}

	/// <summary>
	/// ������ �������� �������� �������
	/// </summary>
	/// <param name="i">����� ������</param>
	/// <param name="j">����� �������</param>
	/// <param name="val">��������</param>
	void Set(int i, int j, int val) {
		if (i > M || j > N) {
			throw out_of_range("An error occured when the program tried to get the value!");
		}
		pm[i * N + j] = val;
	}

	/// <summary>
	/// �������� ���������� ����� ��������
	/// </summary>
	int Distance() const{
		return distance;
	}

	void operator = (const WF&) = delete;
};