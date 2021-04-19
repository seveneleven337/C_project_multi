#include "synaptics.h"

void print_res(double result[]) {
	for (int i = 0; i < 3; i++) {
		printf("  %f- %f - %f\n", result[0], result[1], result[2]);
	}
}
