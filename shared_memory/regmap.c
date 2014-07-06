
#include <stdio.h>      // puts()
#include <fcntl.h>      // open()
#include <sys/mman.h>   // mmap()
#include <stdint.h>     // uint32_t
#include <unistd.h>     // close()
#include <stdlib.h>     // exit()
#include <errno.h>      // errno
#include <string.h>     // strerror

// misc defines
#define FILE_NAME "/tmp/dummy.txt"
#define MMAP_SIZE 20

// define base addresses
#define BLOCK0_INST_BASE 0
#define BLOCK1_INST_BASE 5
int BLOCK_BASE[2] = {BLOCK0_INST_BASE, BLOCK1_INST_BASE};

// define registes
#define REG_a   0
#define REG_b   1
#define REG_c   2
#define REG_d   3
#define REG_e   4
#define REG_p   0
#define REG_q   1
#define REG_r   2
#define REG_s   3
#define REG_t   4
#define REG_x   90


static volatile int* reg_map = (int*)MAP_FAILED;  // mapped array of int's
int fd;


// open memory
void open_mem() {

    fd = open(FILE_NAME, O_RDWR);
    if (fd == -1) {
        printf("*** Open Failed! ");
        puts(strerror(errno));
    }

    reg_map = (int*)mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (reg_map == MAP_FAILED) {
        printf("*** mmap() Failed! ");
        puts(strerror(errno));
        close(fd);
        printf("*** File closed.\n");
        exit(-1);
    }
}


// close memory
void close_mem() {
    munmap((void*)reg_map,MMAP_SIZE);
    close(fd);
    printf("*** Memory unmapped and file closed.\n");
}


// write data to register
void write_data(int reg, int data) {

    printf("Data written to memory: %d\n",data);
    reg_map[reg] = data;

}


// read data from register
int read_data(int reg) {

    printf("REG%d  - data: %d\n",reg+1,reg_map[reg]);

    return 1;
}


int main () {

   int d;

   printf("Size of memory map: %d\n\n",MMAP_SIZE);
   open_mem();

   write_data(BLOCK_BASE[0]+REG_a,99);
   write_data(BLOCK_BASE[0]+REG_b,88);
   write_data(BLOCK_BASE[0]+REG_e,4);

   d = read_data(BLOCK_BASE[0]+REG_a);
   d = read_data(BLOCK_BASE[0]+REG_b);
   d = read_data(BLOCK_BASE[0]+REG_e);
   d = read_data(BLOCK_BASE[0]+REG_c);

   write_data(BLOCK_BASE[1]+REG_p,255);
   d = read_data(BLOCK_BASE[1]+REG_p);

   write_data(BLOCK_BASE[1]+REG_x,77);
   d = read_data(BLOCK_BASE[1]+REG_x);

   close_mem();

   return(0);
}
