#ifndef _VOODOO_ASSERT_H
#define _VOODOO_ASSERT_H

#include <kern/debug.h>

#define ASSERT(expr) do { if (!(expr)) panic("%s: failed assertion '%s'", \
                                                      __FUNCTION__, #expr); } while (0)

#define BUG(msg) panic("%s: %s\n", __FUNCTION__, #msg)

#endif