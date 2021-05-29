/* Test program for 15-412 project 3 Spring 2003
 * Zach Anderson(zra)
 *
 * an wild pointer access test.
 * wild_test1.c
 * Attempt to access memory in the hold.
 * This process should be killed.
 */

/* Includes */
#include <syscall.h>  /* was for exit */
#include <stdlib.h>   /* for exit */
#include <stdio.h>    /* for lprintf */
#include "410_tests.h"
DEF_TEST_NAME("wild_test1:");

/* Main */
int main(int argc, char *argv[])
{
	int *wild = (int *)0x31337000;

	REPORT_START_ABORT;
	

	*wild = 0x2badd00d;

  REPORT_END_FAIL;

	exit( -1 );
}
