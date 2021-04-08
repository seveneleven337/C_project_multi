#pragma once
#ifndef FUNCIONESH
#define	FUNCIONESH
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define sys 30
#define row 4
#define column 4


void create_vector(double[]);
void training_Set_input(double[][column]);
void training_Set_output(double[][column]);
void dots_product(double[][column], double[][column], double[]);
void sigmoid_function(double[][column], double[][column]);
void sigmoid_derivative_function(double[][column], double[][column]);
void error_calc(double[][column], double[][column], double[][column], double[][column]);
void transpose_f(double[][column], double[][column]);
void adjust_f(double[][column], double[][column], double[][column]);
void result_f(double[], double[][column]);






void print_vector(double[]);
void print_input_mat(double[][column]);
void print_res(double[]);



#endif



