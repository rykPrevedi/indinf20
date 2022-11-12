#include <stdio.h>
#include <cuda.h>


__global__ void funzione() {
	
	printf("\t\t\t[DEVICE] Hello, World!\n");
	
	int thrId = threadIdx.x;	// thread ID (monodimensional block)
	int blkId = blockIdx.x;		// block ID 
	
	int thrNum = blockDim.x;	// threads quantity 
	int blkNum = gridDim.x;		// blocks quantity
	printf("\t\t\t[DEVICE] Hello, World! I am thread #%d out of %d, and I belong to block #%d out of %d\n",
	thrId, 
	thrNum,
	blkId,
	blkNum);
	
	return;	
}

int main() {

	printf("[HOST] Hello, World!\n");
	
	funzione<<<3,5>>>();  // 3 block with 5 threads on GPU engine
	
	printf("[HOST] Some more work on host\n");
	
	cudaDeviceSynchronize();
	
	printf("[HOST] Device ended its wotk!\n");
	
	return 0;
}