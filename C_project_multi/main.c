#include "synaptics.h"

typedef struct synaptics_t {                 
    double array[column];
    double matrix[row][column];
   
}synaptics;

void main() {
    synaptics test_syn;
    //double test_syn[sys];
    synaptics input_mat;
    //double input_mat[row][column];
    synaptics output_mat;
    //double output_mat[row][column];
    synaptics dots_mat;
    //double dots_mat[row][column];
    synaptics sig_value_mat;
    //double sig_value_mat[row][column];
    synaptics sig_derivative_mat;
    //double sig_derivative_mat[row][column];
    synaptics error;
    //double error[row][column];
    synaptics transpose;
    //double transpose[row][column];
    synaptics adjust;
    //double adjust[row][column];



    create_vector(test_syn.array);
    for (int i = 0; i < iteration; i++) {
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
    }





    //print_vector(test_syn);
    //print_input_mat(input_mat);
    //print_output_mat(output_mat);
    printf("\n\n");








    double por;

    por = test_syn.array[0] * 1;
    por += test_syn.array[1] * 0;
    por += test_syn.array[2] * 0;

    por = ((1.0) / (1 + exp(-por)));


    printf("\n  %f \n", por);

    return 0;
}

