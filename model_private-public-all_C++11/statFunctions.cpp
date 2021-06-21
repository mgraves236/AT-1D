//
// Created by Magda on 17.02.2021.
//

#include "statFunctions.h"

double rho (int spin[], int L) {
	int sum = 0;
	for (int i = 0; i < L; i++) {
		if ( i != L - 1) {
			sum += 1 - spin[i] * spin[i + 1];
		} else {
			sum += 1 - spin[i] * spin[0];
		}
	}
	return 1/(2 * (double)L) * sum;
}

double g (int spin[], int L) {
	int sum = 0;
	for (int i = 0; i < L; i++) {
		if ( i != L - 1) {
			sum += spin[i] * spin[i + 1];
		} else {
			sum += spin[i] * spin[0];
		}
	}
	return 1/((double)L) * sum;
}

void chainLength (int S[], int sigma[], int n, std::ofstream &file) {

	int chain[n];
	int i = 0;
	while (i < n) {
		if (S[i] == 1 && sigma[i] == 1) {
			chain[i] = 1;
		} else if (S[i] == 1 && sigma[i] == -1) {
			chain[i] = 2;
		} else if (S[i] == -1 && sigma[i] == 1) {
			chain[i] = 3;
		} else if (S[i] == -1 && sigma[i] == -1) {
			chain[i] = 4;
		}
		i = i + 1;
	}

	int count[n+1];
	for (int i=0; i <= n; i++) {
		count[i] = 0;
	}
	//brzegi
	int iStart = 0;
	int temp = 0;
	int counter = 0;
	i = 0;
	if (chain[0] == chain[n-1]) {
		while (i < n) {
			if (chain[0] == chain[i]) {
				counter++;
			} else {
				break;
			}
			i++;
		}
		iStart = i;
		temp = counter;
		counter = 0;
		i = 0;
		while (true) {
			if (i >= n - iStart) {
				break;
			} else if (chain[n - 1] == chain[n - 1 -i]) {
				counter++;
			} else {
				break;
			}
			i++;
		}
	}
	count[counter+temp] += 1;

	int iEnd = n - i;
	i = iStart;
	counter = 0;
	while ( i < iEnd) {
		if ((chain[i] == chain[i + 1])) {
			counter = counter + 1;
		} else if ((chain[i] != chain[i + 1]) && (chain[i] == chain[i - 1])) {
			counter = counter + 1;
			count[counter] += 1;
			counter = 0;
		} else {
			count[1] += 1;
			counter = 0;
		}
		i++;
	}

	for (int i = 1; i <= n; i++) {
		file << count[i] << std::endl;
	}
}

double dis (int S[], int sigma[], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++){
		sum += 1 - sigma[i] * S[i];
	}
	return 1 / (2 * (double)n) * sum;
}

void mag (std::ofstream &file, int S[], int sigma[], int n ) {
	// liczenie charakterystyk
	int mul_S = 0;
	int mul_si = 0;
	int mul_S1 = 0;
	int mul_S2 = 0;
	int mul_si1 = 0;
	int mul_si2 = 0;
	int mul_Ssi = 0;
	int i = 0;

	while (i < n) {
		// <S_i>
		mul_S += S[i];
		// <sigma_i>
		mul_si += sigma[i];

		if (i == n - 1) {
			// <S_i, S_(i+1)>
			mul_S1 += S[i] * S[0];
			// <S_i, S_(i+2)>
			mul_S2 += S[i] * S[1];
			// <sigma_i, sigma_(i+1)>
			mul_si1 += sigma[i] * sigma[0];
			// <sigma_i, sigma_(i+2)>
			mul_si2 += sigma[i] * sigma[1];
			// <S_i, sigma_i>
			mul_Ssi += S[i] * sigma[i];
		} else if (i == n - 2) {
			// <S_i, S_(i+1)>
			mul_S1 += S[i] * S[i + 1];
			// <S_i, S_(i+2)>
			mul_S2 += S[i] * S[0];
			// <sigma_i, sigma_(i+1)>
			mul_si1 += sigma[i] * sigma[i + 1];
			// <sigma_i, sigma_(i+2)>
			mul_si2 += sigma[i + 1] * sigma[0];
			// <S_i, sigma_i>
			mul_Ssi += S[i] * sigma[i + 1];
		} else {
			// <S_i, S_(i+1)>
			mul_S1 += S[i] * S[i + 1];
			// <S_i, S_(i+2)>
			mul_S2 += S[i] * S[i + 2];
			// <sigma_i, sigma_(i+1)>
			mul_si1 += sigma[i] * sigma[i + 1];
			// <sigma_i, sigma_(i+2)>
			mul_si2 += sigma[i] * sigma[i + 2];
			// <S_i, sigma_i>
			mul_Ssi += S[i] * sigma[i];
		}
		i = i + 1;
	}
	//srednia
	double mean_S = (double) mul_S / (double) n;
	file << mean_S << "\t";

	double mean_si = (double) mul_si / (double) n;
	file << mean_si << "\t";

	double mean_S1 = (double) mul_S1 / (double) n;
	file << mean_S1 << "\t";

	double mean_S2 = (double) mul_S2 / (double) n;
	file << mean_S2 << "\t";

	double mean_si1 = (double) mul_si1 / (double) n;
	file << mean_si1 << "\t";

	double mean_si2 = (double) mul_si2 / (double) n;
	file << mean_si2 << "\t";

	double mean_Ssi = (double) mul_Ssi / (double) n;
	file << mean_Ssi << "\t";

	file << std::endl;

}