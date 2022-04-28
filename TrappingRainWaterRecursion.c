#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int trapHelper(int* height, int start, int stop) {
    if((stop - start) == 1 || (stop - start) == 0) return 0;
    int maxheight;
    int maxindex;
    int subheight;
    int subindex;
    if(height[start] > height[start + 1]) {
        maxheight = height[start];
        maxindex = start;
        subheight = height[start + 1];
        subindex = start + 1;
    }
    else {
        maxheight = height[start + 1];
        maxindex = start + 1;
        subheight = height[start];
        subindex = start;
    }
    for (int i = start + 2; i <= stop; ++i) {
        if (height[i] > maxheight) {
            subheight = maxheight;
            subindex = maxindex;
            maxheight = height[i];
            maxindex = i;
        }
        else if (height[i] > subheight) {
            subheight = height[i];
            subindex = i;
        }
    }
    if(subindex < maxindex) {
        int ans = 0;
        for (int i = subindex + 1; i <= maxindex -  1; ++i) ans = ans + (subheight - height[i]);
        return ans + trapHelper(height, start, subindex) + trapHelper(height, maxindex, stop);
    }
    else {
        int ans = 0;
        for (int i = maxindex + 1; i <= subindex - 1; ++i) ans = ans + (subheight - height[i]);
        return ans + trapHelper(height, start, maxindex) + trapHelper(height, subindex, stop);
    }
}

int trap(int* height, int heightSize){
    return trapHelper(height, 0, heightSize - 1);
}