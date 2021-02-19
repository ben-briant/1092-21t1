#include "set.h"
#include <stdio.h>
#include <assert.h>

int main (void) {
    Set s;
    newSet(&s);

    setInsert(&s, 3);
    setInsert(&s, 7);
    setInsert(&s, 123);

    assert(setIsMember(s, 3));
    assert(setIsMember(s, 7));
    assert(setIsMember(s, 123));

    setDelete(&s, 3);

    printf("%d\n", setCardinality(s));
}
