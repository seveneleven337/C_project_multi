/*date 19.04.2021
* author: Gonzalo Araya
* Project: trainning of a synaptics red color reference values
* Course: C Programming
* IT-2020
*/

#include "synaptics.h"

typedef struct synaptics_t {
	double array[column];
	double matrix[row][column];

}synaptics;

void main() {
	synaptics test_syn;
	synaptics input_mat;
	synaptics output_mat;
	synaptics dots_mat;
	synaptics sig_value_mat;
	synaptics sig_derivative_mat;
	synaptics error;
	synaptics transpose;
	synaptics adjust;


	create_vector(test_syn.array);
	for (int i = 0; i < iteration; i++) {           // set iteration to 500000
		training_Set_input(input_mat.matrix);														  
		training_Set_output(output_mat.matrix);
		dots_product(dots_mat.matrix, input_mat.matrix, test_syn.array);
		sigmoid_function(sig_value_mat.matrix, dots_mat.matrix);
		sigmoid_derivative_function(sig_derivative_mat.matrix, sig_value_mat.matrix);
		error_calc(error.matrix, output_mat.matrix, sig_value_mat.matrix, sig_derivative_mat.matrix);
		transpose_f(transpose.matrix, input_mat.matrix);
		adjust_f(adjust.matrix, transpose.matrix, error.matrix);
		result_f(test_syn.array, adjust.matrix);
		print_res(test_syn.array);
	}printf("\n\n");


	

	//this is a example to check the training synaptics with a 100% rgb value
	double example1;

	example1 = test_syn.array[0] * 1;
	example1 += test_syn.array[1] * 0;
	example1 += test_syn.array[2] * 0;
	example1 = ((1.0) / (1 + exp(-example1)));

	printf("\n  %f \n", example1);

	return 0;
}

