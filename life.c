#include <stdio.h>
#include <stdlib.h>

void draw_world(int* world, int w, int h) {

    for(int i = 0; i < w; i++) {
        for(int j=0; j < h; j++) {
            int val = world[i * w + j];
            if (val == 1) { 
                printf("* ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

void zero_map(int* world, int w, int h) {
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            world[i * w + j] = 0;
        }
    }
}

int* get_map(int w, int h) {
    return malloc((w * h) * sizeof(int));
}

void update_world(int* map, int w, int h) {

}

int main() {
    int w = 5;
    int h = 5;
    int* map = get_map(w, h);
    
    zero_map(map, w, h);

    while(1) {
        draw_world(map, w, h);
        printf("Press enter to continue");
        getchar();
        update_world(map, w, h);
    }

    return 0;
}