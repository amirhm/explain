#include <stdio.h>
#include <stdlib.h>

void print_mat(int* ptr, int ndims, int* dims){
	int *stride = malloc(sizeof(int)* ndims);
	stride[ndims -1] = dims[ndims - 1];
	for(int j = ndims - 2 ; j >= 0; j--){
		stride[j] = dims[j] * stride[j + 1];
	}
	for(int idx = 0 ; idx < stride[0]; idx++){ 
    	for(int i = 0; i < ndims; i++){
			if (idx % stride[i] == 0){printf("{");}
		}

		printf("%d", ptr[idx]);

    	for(int i = 0; i < ndims; i++){
			if ((idx + 1) % stride[ndims - i - 1] == 0){printf("}");}
		}
		printf(", ");
	}
    printf("\b\b \n");
	free(stride);
}

int main()
{
	int arr3D[2][3][2]  = { {{0, 1}, {2, 3}, {4, 5}}, {{6, 7}, {8, 9}, {10, 11}} };
	int dims[3] = {2, 3, 2};
	print_mat(&arr3D[0][0][0], 3, dims);
	return 0;

}

