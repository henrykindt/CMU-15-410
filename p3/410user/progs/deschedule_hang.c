/* Test program for 15-410 project 3 Fall 2003
 * Michael Ashley-Rollman(mpa)
 *
 * tests that deschedule does not return if there is no call to make_runnable
 * deschedule_hang.c
 */

#include <syscall.h>
#include <stdlib.h>
#include <stdio.h>
#include "410_tests.h"

static char test_name[] = "deschedule_hang:";

int main()
{
  int error, old, expect, runflag, new;
  lprintf("%s%s%s",TEST_PFX,test_name,TEST_START_4EVER);

  /* fetch current value into "runflag" */
  new = expect = 0;
  if ((error = cas_runflag(gettid(), &runflag, &expect, &new)) < 0) {
    lprintf("cas_runflag() error %d", error);
    goto fail;
  }

  if (expect != 0) {
    lprintf("somebody moved my cheese to %d!", expect);
    goto fail;
  }

  if (runflag != expect) {
    lprintf("runflag is %d, not %d", runflag, expect);
    goto fail;
  }

  /* stop running for quite a while */
  new = -1;
  error = cas_runflag(gettid(), &old, &runflag, &new);

  lprintf("cas_runflag() bad completion %d", error);

fail:
  lprintf("%s%s%s",TEST_PFX,test_name,TEST_END_FAIL);
  exit(1);
}
