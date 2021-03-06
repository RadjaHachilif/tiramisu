#define FEATURE_SIZE 16  // 512
#define BATCH_SIZE 64  // 64
#define NUM_LAYERS 4  // 4
#define SEQ_LENGTH 10  // 100

#define NB_TESTS 2

#if 1  // Flip to use double precision
    #define DATA_TYPE float
    #define DATA_TYPE_P p_float32
    #define DATA_TYPE_CUDNN CUDNN_DATA_FLOAT
#else
    #define DATA_TYPE double
    #define DATA_TYPE_P p_float64
    #define DATA_TYPE_CUDNN CUDNN_DATA_DOUBLE
#endif



#ifdef __cplusplus
double median(std::vector<std::chrono::duration<double, std::milli>> scores)
{
    double median;
    size_t size = scores.size();

    sort(scores.begin(), scores.end());

    if (size % 2 == 0)
    {
        median = (scores[size / 2 - 1].count() + scores[size / 2].count()) / 2;
    }
    else
    {
        median = scores[size / 2].count();
    }

    return median;
}
#else
double median(int n, double x[])
{
    double temp;
    int i, j;

    // The following two loops sort the array x in ascending order
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(x[j] < x[i]) {
                // Swap elements
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

    if(n%2==0) {
        // If there is an even number of elements, return mean of the two elements in the middle
        return((x[n/2] + x[n/2 - 1]) / 2.0);
    } else {
        // Else return the element in the middle
        return x[n/2];
    }
}
#endif
