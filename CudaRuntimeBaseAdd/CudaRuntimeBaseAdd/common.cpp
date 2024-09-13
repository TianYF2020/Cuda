#include "common.h"


void cudaConfigTest()
{
    int iDeviceCount = 0;
    cudaError error = cudaGetDeviceCount(&iDeviceCount);
    if (error != cudaSuccess || iDeviceCount == 0)
    {
        printf("No CUDA campatable GPU found!\n");
        exit(-1);
    }
    else
    {
        printf("The count of GPUs is %d.\n", iDeviceCount);
    }
    int iDev = 0;
    error = cudaSetDevice(iDev);
    if (error != cudaSuccess || iDeviceCount == 0)
    {
        printf("No CUDA campatable GPU found!\n");
        exit(-1);
    }
    else
    {
        printf("The count of GPUs is %d.\n", iDeviceCount);
    }
}



void cudaConfig()
{
    int iDeviceCount = 0;
    cudaError error = cudaGetDeviceCount(&iDeviceCount);
    if (error != cudaSuccess || iDeviceCount == 0)
    {
        printf("No CUDA campatable GPU found!\n");
        exit(-1);
    }
    else
    {
        printf("The count of GPUs is %d.\n", iDeviceCount);
    }
    int iDev = 0;
    error = cudaSetDevice(iDev);
    if (error != cudaSuccess || iDeviceCount == 0)
    {
        printf("No CUDA campatable GPU found!\n");
        exit(-1);
    }
    else
    {
        printf("The count of GPUs is %d.\n", iDeviceCount);
    }
}

bool check(float* out, float* res, int n) 
{
    for (int i = 0; i < n; i++) {
        if (out[i] != res[i])
            return false;
    }
    return true;
}