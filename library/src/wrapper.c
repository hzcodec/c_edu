#include <stdio.h>
#include <stdlib.h>

#include "plot.h"
#include "status.h"

int main() {

    printf("Wrapper started\n");
    plot_coordinates();

    read_status(33);

    return 0;
}
