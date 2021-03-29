#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
    printf("HAHA! I AM IGNORING SIGINT!\n");
}

int main(int argc, char *argv[])
{
   struct sigaction act;
   memset (&act, 0, sizeof(act));
   act.sa_handler = &handler;
   sigaction(SIGHUP, &act, NULL);
   sigaction(SIGINT, &act, NULL);
   sigaction(SIGKILL, &act, NULL);
   while (1) sleep(5);
   return 0;
} 
