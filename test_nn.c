#include <unistd.h>
#include <stdio.h>
#include "fann.h"

int main()
{
    int i;
    int acc_x, acc_y, acc_z, location;
    float max;
    fann_type *calc_out;
    fann_type input[3];
    struct fann *ann;
    ann = fann_create_from_file("TEST.net");

    while (1) {
        max = -100;
        printf("Enter acc_x, acc_y, and acc_z\n");
        printf("Use space to seperate each input\n");
        scanf("%d %d %d", &acc_x, &acc_y, &acc_z);

        input[0] = acc_x;
        input[1] = acc_y;
        input[2] = acc_z;
        calc_out = fann_run(ann, input);

        for (i = 0; i < 3; i++) {
            if (calc_out[i] > max) {
                max = calc_out[i];
                location = i;
            }
        }

        printf("Acc_x: %d, Acc_y: %d, Acc_z: %d -> Orientation %d\n", acc_x, acc_y, acc_z, location+1);
        sleep(1);

    }
    fann_destroy(ann);
    return 0;
}