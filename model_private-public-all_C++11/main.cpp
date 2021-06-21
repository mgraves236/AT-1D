/*
 * public - private
 * kolejnosc aktualizacji S, sigma (publiczna, prywatna)
 * wybieramy jeden wezel i zmieniamy S, a pozniej sigma
 */

#include <iostream>

#include "lib.h"
#include "functions.h"
#include "statFunctions.h"
#include "energy.h"

int main() {
	//obsluga pliku ini
	/*std::ifstream ini("ini.txt");
	if (! ini.is_open()){
		std::cout << "Nie udalo sie otworzyc pliku.";
		exit (1);
	}
	double data[12];
	for (int i = 0; i < 13; i++){
		ini >> data[i];
	}
	ini.close();*/

	//wczytywanie parametrow
	/*int n = (int) data[0]; //dlugosc ukladu
	int MCS = (int) data[1];
	double J_1 = data[2];
	double J_2 = data[3];
	double K_1 = data[4];
	double K_2 = data[5];
	double M_0 = data[6];
	double R_1 = data[7];
	double R_2 = data[8];
	double T = data[9];
	double d = data[10];
	double re = data[11]; //ilosc powtorzen
	int reInt = (int) re;*/

	double tabA[7];
	tabA[0] = 0.01;
	tabA[1] = 0.03;
	tabA[2] = 0.1;
	tabA[3] = 0.3;
	tabA[4] = 1.0;
	tabA[5] = 3.0;
	tabA[6] = 10.0;

	for (int reA = 0; reA < 1; reA++) {
		double A = tabA[reA];

		const int n = 100; //dlugosc ukladu
		int MCS = 1000;
		double J_1 = -1.0;
		double J_2 = 1.0;
		double K_1 = 0;
		double K_2 = 0;
		double M_0 = 1.0 + A;
		double R_1 = 1.0 + A;
		double R_2 = 0;
		double T = 0.01;
		double d = 0.0;
		int re = 50; //ilosc powtorzen

		//obluga generatora liczb losowych
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		std::mt19937 mt_rand(seed);
		std::uniform_int_distribution<int> intDist(0, n - 1);
		std::uniform_real_distribution<double> doubleDist(0.0, 1.0);

		T = 0.01;
		//petla po temperaturze
		while (T < 1.) {
			std::stringstream stream;
			stream << std::fixed << std::setprecision(2) << T;
			std::string s = stream.str();

			std::string time = "TIMEmodel2-L=" + str_i(n) + "-J_1=" + DoubleToString(J_1) + "-J_2=" + DoubleToString(J_2)
							   + "-K_1=" + DoubleToString(K_1) + "-K_2=" + DoubleToString(K_2)
							   + "-T=" + s + "-M_0=" + DoubleToString(M_0)
							   + "-R_1=" + DoubleToString(R_1) + "-R_2=" + DoubleToString(R_2)
							   + "-d=" + DoubleToString(d) + ".txt";
			std::ofstream avergeTimeFile(time.c_str());
			std::string diss = "DISmodel2-dis-L=" + str_i(n) + "-J_1=" + DoubleToString(J_1) + "-J_2=" +
								   DoubleToString(J_2) + "-K_1=" + DoubleToString(K_1) + "-K_2=" + DoubleToString(K_2) +
								   "-T=" + s + "-M_0=" + DoubleToString(M_0)
								   + "-R_1=" + DoubleToString(R_1) + "-R_2=" + DoubleToString(R_2)
								   + "-d=" + DoubleToString(d) + ".txt";

			std::ofstream dis_file(diss.c_str());
		//petla powtorzen
		for (int repeat = 0; repeat < re; repeat++) {

				/*std::string maps = str_i(repeat) + "model2-L=" + str_i(n) + "-J_1=" + DoubleToString(J_1) + "-J_2=" +
								   DoubleToString(J_2)
								   + "-K_1=" + DoubleToString(K_1) + "-K_2=" + DoubleToString(K_2)
								   + "-T=" + DoubleToString(T) + "-M_0=" + DoubleToString(M_0)
								   + "-R_1=" + DoubleToString(R_1) + "-R_2=" + DoubleToString(R_2)
								   + "-d=" + DoubleToString(d) + ".txt";

				std::string SMaps = str_i(repeat) + "Smodel2-L=" + str_i(n) + "-J_1=" + DoubleToString(J_1) + "-J_2=" +
									DoubleToString(J_2)
									+ "-K_1=" + DoubleToString(K_1) + "-K_2=" + DoubleToString(K_2)
									+ "-T=" + DoubleToString(T) + "-M_0=" + DoubleToString(M_0)
									+ "-R_1=" + DoubleToString(R_1) + "-R_2=" + DoubleToString(R_2)
									+ "-d=" + DoubleToString(d) + ".txt";

				std::string sigmaMaps =
						str_i(repeat) + "sigmamodel2-L=" + str_i(n) + "-J_1=" + DoubleToString(J_1) + "-J_2=" +
						DoubleToString(J_2)
						+ "-K_1=" + DoubleToString(K_1) + "-K_2=" + DoubleToString(K_2)
						+ "-T=" + DoubleToString(T) + "-M_0=" + DoubleToString(M_0)
						+ "-R_1=" + DoubleToString(R_1) + "-R_2=" + DoubleToString(R_2)
						+ "-d=" + DoubleToString(d) + ".txt";

				std::ofstream maps_file(maps.c_str());
				std::ofstream SMaps_file(SMaps.c_str());
				std::ofstream sigmaMaps_file(sigmaMaps.c_str());*/

				std::string magnetization =
						str_i(repeat) + "model2-magnetization-L=" + str_i(n) + "-J_1=" + DoubleToString(J_1) + "-J_2=" +
						DoubleToString(J_2) + "-K_1=" + DoubleToString(K_1) + "-K_2=" + DoubleToString(K_2) + "-T=" +
						DoubleToString(T) + "-M_0=" + DoubleToString(M_0)
						+ "-R_1=" + DoubleToString(R_1) + "-R_2=" + DoubleToString(R_2)
						+ "-d=" + DoubleToString(d) + ".txt";

				std::ofstream mag_file(magnetization.c_str());

				/*std::string diss = str_i(repeat) + "model2-dis-L=" + str_i(n) + "-J_1=" + DoubleToString(J_1) + "-J_2=" +
								   DoubleToString(J_2) + "-K_1=" + DoubleToString(K_1) + "-K_2=" + DoubleToString(K_2) +
								   "-T=" + DoubleToString(T) + "-M_0=" + DoubleToString(M_0)
								   + "-R_1=" + DoubleToString(R_1) + "-R_2=" + DoubleToString(R_2)
								   + "-d=" + DoubleToString(d) + ".txt";

				std::ofstream dis_file(diss.c_str());*/

				/*std::string cor = str_i(repeat) + "model2-cor-L=" + str_i(n) + "-J_1=" + DoubleToString(J_1) + "-J_2=" +
								  DoubleToString(J_2) + "-K_1=" + DoubleToString(K_1) + "-K_2=" + DoubleToString(K_2) +
								  "-T=" + DoubleToString(T) + "-M_0=" + DoubleToString(M_0)
								+ "-R_1=" + DoubleToString(R_1) + "-R_2=" + DoubleToString(R_2)
								  + "-d=" + DoubleToString(d) + ".txt";

				std::ofstream cor_file(cor.c_str());*/

				/*std::string chain =
						str_i(repeat) + "LENGTH-model2-L=" + str_i(n) + "-J_1=" + DoubleToString(J_1) + "-J_2=" +
						DoubleToString(J_2)
						+ "-K_1=" + DoubleToString(K_1) + "-K_2=" + DoubleToString(K_2)
						+ "-T=" + DoubleToString(T) + "-M_0=" + DoubleToString(M_0)
						+ "-R_1=" + DoubleToString(R_1) + "-R_2=" + DoubleToString(R_2)
						+ "-d=" + DoubleToString(d) + ".txt";

				std::ofstream chain_file(chain.c_str());*/


				//tworzenie ukladu
				int S[n];
				int sigma[n];

				int order[n];
				for (int i = 0; i < n; i++) {
					order[i] = i;
				}
				//stan poczatkowy
				for (int i = 0; i < n; i++) {
					double randS = doubleDist(mt_rand);
					if (randS >= 0.5)
						S[i] = 1;
					else
						S[i] = 1;
				}
				for (int i = 0; i < n; i++) {
					double randD = doubleDist(mt_rand);
					if (d < randD) {
						sigma[i] = S[i];
					} else {
						sigma[i] = -S[i];
					}
				}

				//wpisywanie stanu poczatkowego do pliku
				int i = 0;
				/*while (i < n) {
					if (S[i] == 1 && sigma[i] == 1) {
						maps_file << "1" << " ";
						SMaps_file << "1" << " ";
						sigmaMaps_file << "1" << " ";
					} else if (S[i] == 1 && sigma[i] == -1) {
						maps_file << "2" << " ";
						SMaps_file << "1" << " ";
						sigmaMaps_file << "-1" << " ";
					} else if (S[i] == -1 && sigma[i] == 1) {
						maps_file << "3" << " ";
						SMaps_file << "-1" << " ";
						sigmaMaps_file << "1" << " ";
					} else if (S[i] == -1 && sigma[i] == -1) {
						maps_file << "4" << " ";
						SMaps_file << "-1" << " ";
						sigmaMaps_file << "-1" << " ";
					}
					i = i + 1;
				}
				maps_file << std::endl;
				SMaps_file << std::endl;
				sigmaMaps_file << std::endl;*/

				int stepKeep = 0;
				//MCS
				for (int step = 0; step < MCS; step++) {
					//dis_file << dis(S, sigma, n) << std::endl;
					/*cor_file << g(S, n) << "\t" << g(sigma, n) << std::endl;*/
					mag(mag_file, S, sigma, n);
					stepKeep = step + 1;

					//shuffleArray(order,n);
					//przejscie po wszystkich wezlach
					for (int j = 0; j < n; j++) {
						int randIndex = intDist(mt_rand);
						/*std::cout << "INDEX S" << order[j] << std::endl;
						std::cout << calculateEnergyS(n, order[j], S, sigma, J_1, J_2, K_1, K_2, M_0, R_1, R_2) << std::endl;*/
						//enrgia ukladu po zmianie spinu S na przeciwny
						if (calculateEnergyS(n, randIndex, S, sigma, J_1, J_2, K_1, K_2, M_0, R_1, R_2) <= 0) {
							S[randIndex] = -S[randIndex];
						} else if (T != 0.0) {
							double x = doubleDist(mt_rand);
							if (x < exp(-calculateEnergyS(n, randIndex, S, sigma, J_1, J_2, K_1, K_2, M_0, R_1, R_2) / T)) {
								S[randIndex] = -S[randIndex];
							}
						}
						//sigmai
						/*std::cout << "INDEX SIGMA " << order[j] << std::endl;
						std::cout << calculateEnergySigma(n, order[j], S, sigma, J_1, J_2, K_1, K_2, M_0, R_1, R_2) << std::endl;*/
						//enrgia ukladu po zmianie spinu na przeciwny
						if (calculateEnergySigma(n, randIndex, S, sigma, J_1, J_2, K_1, K_2, M_0, R_1, R_2) <= 0) {
							sigma[randIndex] = -sigma[randIndex];
						} else if (T != 0.0) {
							double x = doubleDist(mt_rand);
							if (x <
								exp(-calculateEnergySigma(n, randIndex, S, sigma, J_1, J_2, K_1, K_2, M_0, R_1, R_2) / T)) {
								sigma[randIndex] = -sigma[randIndex];
							}
						}
					}

					//wpisywanie stanow do plikow
					/*i = 0;
					while (i < n) {
						if (S[i] == 1 && sigma[i] == 1) {
							maps_file << "1" << " ";
							SMaps_file << "1" << " ";
							sigmaMaps_file << "1" << " ";
						} else if (S[i] == 1 && sigma[i] == -1) {
							maps_file << "2" << " ";
							SMaps_file << "1" << " ";
							sigmaMaps_file << "-1" << " ";
						} else if (S[i] == -1 && sigma[i] == 1) {
							maps_file << "3" << " ";
							SMaps_file << "-1" << " ";
							sigmaMaps_file << "1" << " ";
						} else if (S[i] == -1 && sigma[i] == -1) {
							maps_file << "4" << " ";
							SMaps_file << "-1" << " ";
							sigmaMaps_file << "-1" << " ";
						}
						i = i + 1;
					}
					maps_file << std::endl;
					SMaps_file << std::endl;
					sigmaMaps_file << std::endl;*/

					//warunek zatrzymania gs, v = rho
					if (g(sigma, n) * g(sigma, n) == 1.0 && g(S, n) * g(S, n) == 1.0) {
						break;
					}
				}//koniec MCS
				avergeTimeFile << stepKeep << "\t" << g(S, n) << "\t" << g(sigma, n) << std::endl;
				dis_file << dis(S, sigma, n) << std::endl;
				/*maps_file.close();
				sigmaMaps_file.close();
				sigmaMaps_file.close();*/
				mag_file.close();
				/*cor_file.close();*/
				/*chainLength(S, sigma, n, chain_file);
				chain_file.close();*/
			}//koniec petli powtorzen
			avergeTimeFile.close();
			dis_file.close();
			T += 0.01;
		}//koniec petli po T
	}//koniec petli po A
	return 0;
}
