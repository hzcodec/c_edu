/*
    Auther       : Heinz Samuelsson
    Date         : 2018-03-21
    File         : cb_with_irq2.c
    Reference    : -
    Description  : Callback function with struct as pointer parameter. Nested structs.
                   Function pointer in struct.
*/ 
 
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void f1(void)
{
        printf("%s() - Hello\n", __func__);
}

void f2(void)
{
        printf("%s() - There\n", __func__);
}

void f3(void)
{
        printf("%s() - Good Day\n", __func__);
}

//typedef void (*gg)(void);
struct Clock {
       int x;
       int y;
       //gg g;
       void (*g)(void);
};

typedef void (*ff)(void);
struct Block {
       int a;
       int b;
       struct Clock c;
       void (*func)(void);
       ff f;
};


static uint8_t brk_flag;
 
static void break_callback(struct Block *b)
{
	brk_flag = 1;
        printf("%s() - brk_flag=%d, b.a=%d, b.b=%d, b->c.x=%d, b->c.y=%d\n", 
	        __func__, brk_flag, b->a, b->b, b->c.x, b->c.y);

	b->a = 200;
	b->c.y = 900;
	
	b->func();  /* call f1 */
	b->f();     /* call f2 */

	b->c.g();   /* call f3 */
}

static void (*break_cb)(struct Block *b);

// callback is called at interrupt
void TIM8_BRK_IRQHandler(struct Block *b)
{
        printf("%s() - \n", __func__);

	if (break_cb != NULL) {
		break_cb(b);
	}
	else {
	        printf("Callback not registered\n");
	}
}

// register callback function
void register_callback(void (*cb)(struct Block *b))
{
        printf("%s() - \n", __func__);
	break_cb = cb;
}

int main(int argc, char *argv[])
{
        struct Block block = {11, 22,       /* a, b */
	                      {1, 2, f3},   /* x, y, function f3() */
			      f1,           /* function f1() */
			      f2            /* function f2() */
			     };

        printf("%s() - brk_flag=%d\n", __func__, brk_flag);

        register_callback(break_callback);

        TIM8_BRK_IRQHandler(&block);

	printf("block.a=%d, block.c.y=%d\n", block.a, block.c.y);

        return 0;
}

/*
        main() - brk_flag=0
        register_callback() - 
        TIM8_BRK_IRQHandler() - 
        break_callback() - brk_flag=1, b.a=11, b.b=22, b->c.x=1, b->c.y=2
        f1() - Hello
        f2() - There
        f3() - Good Day
        block.a=200, block.c.y=900
*/

