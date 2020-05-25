// OOP244 Lab 09 
// Luxi Liang 
// 165936188
// November 27, 2019

#ifndef SDDS_CALCULATOR_H
#define SDDS_CALCULATOR_H

#include <iostream>
using namespace std;
namespace sdds {

	template <class T, int N>
	class Calculator {

		T results[N];

	public:
		Calculator() {
			for (int i = 0; i < N; i++) {
				results[i] = 0;
			}
		};
		void add(const T* pika, const T* pichu) {
			for (int i = 0; i < N; i++) {
				results[i] = pika[i] + pichu[i];
			}
		};
		void subtract(const T* charmander, const T* charizard) {
			for (int i = 0; i < N; i++) {
				results[i] = charmander[i] - charizard[i];
			}
		};
		void multiply(const T* squirtle, const T* blastoise) {
			for (int i = 0; i < N; i++) {
				results[i] = squirtle[i] * blastoise[i];
			}
		};

		void divide(const T* bulbasaur, const T* venasaur) {
			for (int i = 0; i < N; i++) {
				results[i] = bulbasaur[i] / venasaur[i];
			}
		};

		ostream& display(ostream& os) const {
			os << results[0];
			for (int i = 1; i < N; i++) {
				os << "," <<results[i];
			}
			os << endl;
			return os;
		};

		Calculator& operator+=(const T* watashi) {
			add(watashi, results);
			return *this;
		};

		Calculator& operator-=(const T* iitai) {
			subtract(results, iitai);
			return *this;
		};

		Calculator& operator*=(const T* anataga) {
			multiply(anataga, results);
			return *this;
		};

		Calculator& operator/=(const T* sukidesu) {
			divide(results, sukidesu);
			return *this;
		};
	};
}
#endif
