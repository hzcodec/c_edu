/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-10-10
    File        : regmap.c
    Reference   : -
    Description : Test of mmap function. The result can be viewed in
                  /tmp/dummy16.txt
*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// misc defines
#define FILE_NAME16 "/tmp/dummy16.txt"

// size is determined by TOP_INST_BASE+BLOCK and CH_4
#define MMAP_SIZE 100  // (0x0a + 0x0a + 0x05) *4 = 100

// define base addresses
#define TOP_INST_BASE     0x0a
#define BLOCK             0x0a
#define BLOCK_INST_BASE   TOP_INST_BASE+BLOCK

#define CH_0 0x0000
#define CH_1 0x0001
#define CH_2 0x0002
#define CH_3 0x0003
#define CH_4 0x0004


static volatile uint16_t* reg_map16 = (uint16_t*)MAP_FAILED;  // mapped array of uint16_t
int fd16;


// open memory
void open_mem() {

    fd16 = open(FILE_NAME16, O_RDWR|O_CREAT,(mode_t)0666); // file descriptor - index into an array

    if (fd16 == -1) {
        printf("*** Open Failed! ");
        puts(strerror(errno));
    }

    // move pointer to the last position
    int retCode = lseek(fd16, MMAP_SIZE-1, SEEK_SET);
    if (retCode < 0) {
        puts(strerror(errno));
    }

    if (write(fd16, "Q", 1) < 0) {
        puts(strerror(errno));
    }

    reg_map16 = (uint16_t*)mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd16, 0);

    if (reg_map16 == MAP_FAILED) {
        printf("*** mmap() Failed! ");
        puts(strerror(errno));
        close(fd16);
        printf("*** File closed.\n");
        exit(-1);
    }
    printf(".........................................................\n");
}


// clear memory
void reset_mem() {
    memset((uint16_t*)reg_map16,0,MMAP_SIZE);
}


// close memory
void close_mem() {

    munmap((void*)reg_map16,MMAP_SIZE);
    close(fd16);
}


// 32 bit write access
void write32(uint32_t reg, uint32_t data) {

    printf("*** Data write access (32 bit): %08x\n", data);

    printf("reg:  %08x\n", reg);
    printf("data: %08x\n", data);

    uint32_t lo = reg * 2;
    uint32_t hi = lo + 1;

    reg_map16[lo]   = (uint16_t)(data & 0xffff);
    reg_map16[hi] = (uint16_t)(data>>16);
}


// 32 bit read access
uint32_t read32(int reg) {

    printf("*** Data read access (32 bit)\n");

    uint32_t lo = reg * 2;
    uint32_t hi = lo + 1;

    uint16_t lo_data = reg_map16[lo];
    uint16_t hi_data = reg_map16[hi];

    printf("hi: %04x\n", lo_data);
    printf("lo: %04x\n", hi_data);

    uint32_t data = (hi_data << 16) | lo_data;
    return data;
}


int main () {

   open_mem();
   reset_mem();

   // write data at the beginning of the file, ascii A,B,C,D
   write32(0, 0x41424344);
   uint32_t data32 = read32(0);
   printf("@32 bit read - data: %08x\n", data32);

   // write data at the second place in the file, ascii H,I,J,K
   write32(1, 0x48494a4b);
   data32 = read32(1);
   printf("@32 bit read - data: %08x\n", data32);

   write32(BLOCK_INST_BASE+CH_0, 0x7778797a); // ascii w,x,y,z
   data32 = read32(BLOCK_INST_BASE+CH_0);
   printf("@32 bit read - data: %08x\n", data32);

   // write data to the last position, ascii h,j,k,l 
   write32(BLOCK_INST_BASE+CH_4,0x68696a6b);
   data32 = read32(BLOCK_INST_BASE+CH_4);
   printf("@32 bit read - data: %08x\n", data32);

   close_mem();

   return(0);
}

