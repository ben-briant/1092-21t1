#define NBITS 1024
#define NWORDS (NBITS/32)

typedef unsigned int Word;

typedef struct set{
    Word bits[NWORDS];
} Set;

// Initialises a new set
void newSet(Set *s);
// If 'i' is a member of 's', return 1
// else, return 0
int setIsMember(Set s, int i);
// Add 'i' to the set 's'
void setInsert(Set *s, int i);
// Delete 'i' from the set 's'
void setDelete(Set *s, int i);
// Returns the cardinality (size) of s
unsigned int setCardinality(Set s);
// Returns the union of the sets 's' and 't'
Set setUnion(Set s, Set t);
// Returns the intersection of the sets 's' and 't'
Set setIntersection(Set s, Set t);
