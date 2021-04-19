#include "synaptics.h"

//function to generate a random set of inputs(synaptics input to be train)
void create_vector(double test_syn[]) {
	srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		test_syn[i] = (2 * (double)rand() / RAND_MAX) - 1;
	}
}

//function to set inputs to train our synaptics
void training_Set_input(double input_mat[][column]) {
	float a[12] = { 0.0,0.5,1.0,0.5,0.0,0.0,0.9,0.1,0.1,0.5,0.9,0.9 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			input_mat[i][j] = a[i * 3 + j];
		}
	}
}

//function to set outputs to train our synaptics
void training_Set_output(double input_mat[][column]) {
	float a[12] = { 0.0,1.0,1.0,0.0 };
	for (int i = 0; i < 4; i++) {
		input_mat[i][0] = a[i];
	}
}

//dot product function
void dots_product(double dots_mat[][column], double input_mat[][column], double test_syn[]) {
	for (int i = 0; i < 4; i++) {
		dots_mat[i][0] = (input_mat[i][0] * test_syn[0] + input_mat[i][1] * test_syn[1] + input_mat[i][2] * test_syn[2]);
	}
}

//sigmoid function to calculate the desviation of our synaptics respect to a reference values
void sigmoid_function(double sig_value_mat[][column], double dots_mat[][column]) {
	for (int i = 0; i < 4; i++) {
		sig_value_mat[i][0] = ((1.0) / (1 + exp(-dots_mat[i][0])));
	}
}

//sigmoid derivative function to noramlize the sigmoid value of our synaptics respect to a reference values
void sigmoid_derivative_function(double derivative[][column], double sigmoid[][column]) {
	for (int i = 0; i < 4; i++) {
		derivative[i][0] = sigmoid[i][0] * (1.0 - sigmoid[i][0]);
	}
}

//function to calculate the error of our synaptics
void error_calc(double error[][column], double output_mat[][column], double sig_value_mat[][column], double sig_derivative_mat[][column]) {
	for (int i = 0; i < 4; i++) {
		error[i][0] = (output_mat[i][0] - sig_value_mat[i][0]) * sig_derivative_mat[i][0];
	}
}

//transpose of a 3x3 matrix
void transpose_f(double transpose[][4], double input_mat[][column]) {
	
	transpose[0][0] = input_mat[0][0];
	transpose[0][1] = input_mat[1][0];
	transpose[0][2] = input_mat[2][0];
	transpose[0][3] = input_mat[3][0];

	transpose[1][0] = input_mat[0][1];
	transpose[1][1] = input_mat[1][1];
	transpose[1][2] = input_mat[2][1];
	transpose[1][3] = input_mat[3][1];

	transpose[2][0] = input_mat[0][2];
	transpose[2][1] = input_mat[1][2];
	transpose[2][2] = input_mat[2][2];
	transpose[2][3] = input_mat[3][2];

}

//adjustment value respect to the error calculated before
void adjust_f(double adjust[][column], double transpose[][4], double error[][column]) {
	for (int i = 0; i < 3; i++) {
		adjust[i][0] = (transpose[i][0] * error[0][0]) + (transpose[i][1] * error[1][0]) + (transpose[i][2] * error[2][0]) + (transpose[i][3] * error[3][0]);
	}
}

//add teh adjustment value to our synaptics
void result_f(double test_syn[], double adjust[][column]) {
	for (int i = 0; i < 3; i++) {
		test_syn[i] += adjust[i][0];
	}
}




