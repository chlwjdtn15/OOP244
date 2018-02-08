
#ifndef SICT_GRAPH_H_
#define SICT_GRAPH_H_
#define MAX_NO_OF_SAMPLES 20
namespace sict {
#define MAX_NO_OF_SAMPLES 20
	int findMax(int samples[], int noOfSamples);

	void printBar(int val, int max);

	void printGraph(int samples[], int noOfSamples);

	void getSamples(int samples[], int noOfSamples);
}

#endif
