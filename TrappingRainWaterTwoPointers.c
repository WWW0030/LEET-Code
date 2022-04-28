#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int trap(int* height, int heightSize){
    //First check for trivial case
    if(heightSize == 1 || heightSize == 2) return 0;
    //Check for first none-zero bar on each side
    int firststart = 0;
    int firstend = heightSize - 1;
    while(height[firststart] == 0 && firststart != heightSize - 1) firststart++;
    while(height[firstend] == 0 && firstend != 0) firstend--;
    //flat surface
    if(firstend - firststart < 2) return 0;
    int ans = 0, prevheight = 0, currentleft = firststart, currentright = firstend, maxheight = fmin(height[firststart], height[firstend]);
    //three cases
    while(currentright - currentleft > 1) {
        if(height[currentleft] < height[currentright]) {
            ans = ans + (currentright - currentleft + 1) * (height[currentleft] - prevheight);
            prevheight = height[currentleft];
            maxheight = prevheight;
            ++currentleft;
            while(height[currentleft] <= prevheight && currentleft != currentright) ++currentleft;
        }
        else if(height[currentright] < height[currentleft]) {
            ans = ans + (currentright - currentleft + 1) * (height[currentright] - prevheight);
            prevheight = height[currentright];
            maxheight = prevheight;
            --currentright;
            while(height[currentright] <= prevheight && currentright != currentleft) --currentright;
        }
        else {
            ans = ans + (currentright - currentleft + 1) * (height[currentright] - prevheight);
            prevheight = height[currentright];
            maxheight = prevheight;
            ++currentleft;
            --currentright;
            while(height[currentleft] <= prevheight && currentleft != currentright) ++currentleft;
            while(height[currentright] <= prevheight && currentright != currentleft) --currentright;
        }
    }
    //We got the amount of water + bars(up to maxheight)
    //We now minus all area of bars(up to maxheight)
    printf("before: %d\n", ans);
    printf("maxheight: %d\n", maxheight);
    for(int i = firststart; i <= firstend; ++i) {
        if(height[i] > maxheight) ans = ans - maxheight;
        else ans = ans - height[i];
    }
    return ans;
}