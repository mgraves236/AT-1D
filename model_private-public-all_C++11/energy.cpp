//
// Created by Magda on 17.02.2021.
//

#include "energy.h"
#include "functions.h"


double hamiltonian (int n, int S[], int sigma[], double J_1, double J_2, double K_1, double K_2, double M_0, double R_1, double R_2) {
	double E = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1)
			E += - J_1 * S[i] * S[0] - J_2 * S[i] * S[1]
				 - K_1 * sigma[i] * sigma[0] - K_2 * sigma[i] * sigma[1]
				 - M_0 * S[i] * sigma[i]
				 - R_1 * sigma[i] * S[0] - R_2 * sigma[i] * S[1];
		else if (i == n - 2)
			E += - J_1 * S[i] * S[i + 1] - J_2 * S[i] * S[0]
				 - K_1 * sigma[i] * sigma[i + 1] - K_2 * sigma[i] * sigma[0]
				 - M_0 * S[i] * sigma[i]
				 - R_1 * sigma[i] * S[i + 1] - R_2 * sigma[i] * S[0];

		else
			E += - J_1 * S[i] * S[i + 1] - J_2 * S[i] * S[i + 2]
				 - K_1 * sigma[i] * sigma[i + 1] - K_2 * sigma[i] * sigma[i + 2]
				 - M_0 * S[i] * sigma[i]
				 - R_1 * sigma[i] * S[i + 1] - R_2 * sigma[i] * S[i + 2];
	}
	return E;
}

double calculateEnergySigma (int n, int label, int S[], int sigma[] , double J_1, double J_2, double K_1, double K_2,
							 double M_0, double R_1, double R_2) {
	int sigmaCopy[n];
	copyArray(sigma, sigmaCopy, n);
	sigmaCopy[label] = -sigmaCopy[label];
	double E = hamiltonian(n, S, sigmaCopy, J_1 , J_2, K_1, K_2, M_0, R_1, R_2);
	double E0 = hamiltonian(n, S, sigma, J_1 , J_2, K_1, K_2, M_0, R_1, R_2);
	return E - E0;
}

double calculateEnergyS(int n, int label, int S[], int sigma[] , double J_1, double J_2, double K_1, double K_2,
						double M_0, double R_1, double R_2) {
	int sCopy[n];
	copyArray(S, sCopy, n);
	sCopy[label] = -sCopy[label];
	double E = hamiltonian(n, sCopy, sigma, J_1 , J_2, K_1, K_2, M_0, R_1, R_2);
	double E0 = hamiltonian(n, S, sigma, J_1 , J_2, K_1, K_2, M_0, R_1, R_2);
	return E - E0;
}
