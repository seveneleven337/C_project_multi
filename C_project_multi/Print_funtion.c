#include "synaptics.h"

void print_vector(double test_syn[]) {
	for (int i = 0; i < 3; i++) {
		printf("numero %d es %lf\n", i + 1, test_syn[i]);
	}
}

void print_input_mat(double input_mat[][column]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			printf("numero %d es %lf\n", i * 3 + j, input_mat[i][j]);
		}
	}
}

void print_output_mat(double input_mat[][column]) {
	for (int i = 0; i < 4; i++) {
		printf("numero [%d,0] es %lf\n", i, input_mat[i][0]);
	}
}

void print_res(double result[]) {
	for (int i = 0; i < 3; i++) {
		printf("  %f- %f - %f\n", result[0], result[1], result[2]);
	}
}
