#include "synaptics.h"

void main() {
    double test_syn[sys];
    double input_mat[row][column];
    double output_mat[row][column];
    double dots_mat[row][column];
    double sig_value_mat[row][column];
    double sig_derivative_mat[row][column];
    double error[row][column];
    double transpose[row][column];
    double adjust[row][column];



    create_vector(test_syn);
    for (int i = 0; i < 500000; i++) {
        training_Set_input(input_mat);
        training_Set_output(output_mat);
        dots_product(dots_mat, input_mat, test_syn);
        sigmoid_function(sig_value_mat, dots_mat);
        sigmoid_derivative_function(sig_derivative_mat, sig_value_mat);
        error_calc(error, output_mat, sig_value_mat, sig_derivative_mat);
        transpose_f(transpose, input_mat);
        adjust_f(adjust, transpose, error);
        result_f(test_syn, adjust);
        print_res(test_syn);
    }





    //print_vector(test_syn);
    //print_input_mat(input_mat);
    //print_output_mat(output_mat);
    printf("\n\n");








    double por;

    por = test_syn[0] * 1;
    por += test_syn[1] * 0;
    por += test_syn[2] * 0;

    por = ((1.0) / (1 + exp(-por)));


    printf("\n  %f \n", por);

    return 0;
}

