
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#define M 512 
#define K 512
#define N 512

void initial(float* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = (float)(rand() % 10 + 1);
	}
}

__global__ void mulitplicateMatrix(float* array_A, float* array_B, float *array_C, int M_p, int K_p, int N_p)
{
	int ix = blockDim.x * blockIdx.x + threadIdx.x;
	int iy = blockDim.y * blockIdx.y + threadIdx.y;
	if (ix < N_p && iy < N_p)
	{
		float sum = 0;
		for (int k = 0; k < K_p; k++)
		{
			sum = array_A[iy * K_p + k] * array_B[ix * N_p + k];
		}
		array_C[iy* M_p + ix] = sum;
	}

}

int main()
{
	int Axy = M * K;
	int Bxy = K * N;
	int Cxy = M * N;
	
	float* h_A, * h_B,*h_C, * hostRef, * deviceRef;
	h_A = (float*)malloc(Axy * sizeof(float));
	h_B = (float*)malloc(Bxy * sizeof(float));
	h_C = (float*)malloc(Cxy * sizeof(float));
	initial(h_A, Axy);
	initial(h_B, Axy);

	float* d_A, *d_B, *d_C;
	cudaMalloc((void**)&d_A, Axy * sizeof(float));
	cudaMalloc((void**)&d_B, Bxy * sizeof(float));
	cudaMalloc((void**)&d_C, Cxy * sizeof(float));

	cudaMemcpy(d_A, h_A, Axy * sizeof(float), cudaMemcpyHostToDevice);
	cudaMemcpy(d_B, h_B, Bxy * sizeof(float), cudaMemcpyHostToDevice);

	dim3 block(2,2);
	dim3 grid((M + block.x - 1) / block.x, (N + block.y - 1) / block.y);
	
	mulitplicateMatrix <<<grid, block >>> (d_A, d_B, d_C,M,K,N);
	cudaMemcpy(h_C, d_C, Cxy * sizeof(float), cudaMemcpyDeviceToHost);
	
	cudaFree(d_A);
	cudaFree(d_B);
	cudaFree(d_C);

	free(h_A);
	free(h_B);
	free(h_C);
	return 0;
}