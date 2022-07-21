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

void print_nb_map(int* nb_map, int w, int h) {
    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            printf("%d ", nb_map[y*w + x]);
        }
        printf("\n");
    }
}

void update_world(int* map, int w, int h) {

    int nb_map[25];
    
    //Update neighbor map
    for(int y = 0; y < w; y++) {
        for(int x = 0; x < h; x++) {

            int ul, u, ur, l, r, dl, d, dr;

            //check ul
            if (x-1 >= 0 && y-1 >= 0) {
                ul = map[(y-1)*w + (x-1)];
            } else { ul = 0;}

            //check u edge
            if (y-1 >= 0) {
                u = map[(y-1)*w + x];
            } else { u = 0;}
        
            //check ur
             if (x+1 < w && y-1 >= 0) {
                 ur = map[(y-1)*w + (x+1)];
            } else { ur = 0; }

		    //check r
            if (x+1 < w) {
                r = map[(y)*w + (x+1)];
            } else { r = 0; }

            //check dr
            if(y+1 < h && x+1 < w) {
                dr = map[(y+1)*w + (x+1)];
            } else { dr = 0; }

            //check d
            if (y+1 < h) {
            d = map[(y+1)*w + x];
            } else { d = 0; }

            //check dl
            if (y+1 < h && x-1 >= 0) {
                dl = map[(y+1)*w + (x-1)];
            } else { dl = 0; }
		
            //check l
            if (x-1 >= 0) {
                l = map[(y)*w + (x-1)];
            } else { l = 0; }
		
		    int num_neighbors = ul + u + ur + l + r + dl + d + dr;
            nb_map[y*w + x] = num_neighbors;
        }
    }

    print_nb_map(nb_map, w, h);

    //update map based on neighbors
    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            if(map[y*w + x] == 1)
            {
                int n = nb_map[y*w + x];
                if ( n == 2 || n == 3) {
                    map[y*w + x] = 1;
                } else {
                    map[y*w + x] = 0;
                }

            } else if(map[y*w+x] == 0 ) {
                if (nb_map[y*w +x] == 3) {
                    map[y*w + x] = 1;
                }
            }
        } 
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

int main(int argc, char** argv) {
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
