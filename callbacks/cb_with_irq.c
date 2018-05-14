/*
    Auther       : Heinz Samuelsson
    Date         : 2018-03-21
    File         : cb_with_irq.c
    Reference    : -
    Description  : Callback function without parameter.
*/ 
 
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

static uint8_t brk_flag;
 
static void break_callback(void)
{
	brk_flag = 1;
        printf("%s() - brk_flag=%d\n", __func__, brk_flag);
}

static void (*break_cb)(void);

// callback is called at interrupt
void TIM8_BRK_IRQHandler(void)
{
        printf("%s() - \n", __func__);

	if (break_cb != NULL) {
		break_cb();
	}
	else {
	        printf("Callback not registered\n");
	}
}

// register callback function
void bsp_set_break_callback(void (*cb)(void))
{
        printf("%s() - \n", __func__);
	break_cb = cb;
}

int main(int argc, char *argv[])
{
        printf("%s() - brk_flag=%d\n", __func__, brk_flag);

	#if 1 // set/unset to register callback function
        bsp_set_break_callback(break_callback);
	#endif

        TIM8_BRK_IRQHandler();

        return 0;
}

/*
       main() - brk_flag=0
       bsp_set_break_callback() - 
       TIM8_BRK_IRQHandler() - 
       break_callback() - brk_flag=1


       main() - brk_flag=0
       TIM8_BRK_IRQHandler() - 
       Callback not registered
*/

