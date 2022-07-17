#include <stdio.h>
#include <stdlib.h>

void draw_world(int* world, int w, int h) {

    for(int y = 0; y < w; y++) {
        for(int x=0; x < h; x++) {
            int val = world[y * w + x];
            if (val == 1) { 
                printf("* ");
            } else if (val == 0) {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

void zero_map(int* world, int w, int h) {
    for(int y = 0; y < w; y++) {
        for(int x = 0; x < h; x++) {
            world[y * w + x] = 0;
        }
    }
}

int* get_map(int w, int h) {
    return malloc((w * h) * sizeof(int));
}

void update_world(int* map, int w, int h) {

    int nb_map[25];
    //for each
    //count neighbors
    //update neighbor count
    //kill all lowbies
    //birth all babbys

    //need a neighbor location algorithm

    for(int y = 0; y < w; y++) {
        for(int x = 0; x < h; x++) {

		int ul = map[(y-1)*w + (x-1)];
		int uc = map[(y-1)*w + x];
		int ur = map[(y-1)*w + (x+1)];

		int l = map[(y)*w + (x-1)];
		int r = map[(y)*w + (x+1)];

		int ll = map[(y+1)*w + (x-1)];
		int lc = map[(y+1)*w + x];
		int lr = map[(y+1)*w + (x+1)];

		int num_neighbors = ul + uc + ur + l + r + ll + lc + lr;
		printf("%d ", num_neighbors);
		//printf("%d %d %d\n", ul, uc, ur);
		//printf("%d %d %d\n", l, map[y*w + x], r);
		//printf("%d %d %d\n", ll, lc, lr);

        }
	printf("\n");
    }
}

void simple_start(int* map, int w, int h) {

   /* 0,0,0,0,0
      0,0,1,1,0,
      0,0,1,0,0,
      0,0,1,0,0,
      0,0,1,0,0,
   */
    
    int desired[] = {0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0};
    for(int y = 0; y < w; y++) {
        for(int x = 0; x < h; x++) {
            map[y * w + x] = desired[y * w + x];
        }
    }
}

int main() {
    int w = 5;
    int h = 5;
    int* map = get_map(w, h);
    
    zero_map(map, w, h);
    simple_start(map, w, h);

    while(1) {
        draw_world(map, w, h);
        printf("Press enter to continue");
        getchar();
        update_world(map, w, h);
    }

    return 0;
}
