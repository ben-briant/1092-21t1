#include "set.h"
#include <string.h>

// Initialises a new set
void newSet(Set *s) {
    memset(s->bits, 0, NWORDS * sizeof(Word));
}
// If 'i' is a member of 's', return 1
// else, return 0
int setIsMember(Set s, int i) {
    int index = i / 32;
    return !!(s.bits[index] & (1u << (i % 32)));
}
// Add 'i' to the set 's'
void setInsert(Set *s, int i) {
    int index = i / 32;
    s->bits[index] |= 1u << (i % 32);
}
// Delete 'i' from the set 's'
void setDelete(Set *s, int i) {
    int index = i / 32;
    s->bits[index] &= ~(1u << (i % 32));
}
// Returns the cardinality (size) of s
unsigned int setCardinality(Set s) {
    unsigned int total = 0;
    for (int i = 0; i < NWORDS; i++) {
        Word word = s.bits[i];
        for (Word j = 1; j; j <<= 1) {
            total += !!(word & j);
        }
    }
    return total;
}
// Returns the union of the sets 's' and 't'
Set setUnion(Set s, Set t) {
    Set new;
    newSet(&s);
    for (int i = 0; i < NWORDS; i++) {
        Word sWord = s.bits[i];
        Word tWord = t.bits[i];
        new.bits[i] = s.bits[i] | t.bits[i];
    }
}
// Returns the intersection of the sets 's' and 't'
Set setIntersection(Set s, Set t) {
    Set new;
    newSet(&s);
    for (int i = 0; i < NWORDS; i++) {
        Word sWord = s.bits[i];
        Word tWord = t.bits[i];
        new.bits[i] = s.bits[i] & t.bits[i];
    }
    return new;
}
