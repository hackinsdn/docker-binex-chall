/* 
 * Compile without some mitigations:
 * - RELRO
 * - Stack Canary
 * - PIE
 * - NX / Executable Stack
 *
 * gcc binexp_bof_01.c -o binexp_bof_01 -no-pie -z execstack -fno-stack-protector -z norelro
 *
 *     Arch:       amd64-64-little
 *     RELRO:      No RELRO
 *     Stack:      No canary found
 *     NX:         NX unknown - GNU_STACK missing
 *     PIE:        No PIE (0x400000)
 *     Stack:      Executable
 *     RWX:        Has RWX segments
 *     Stripped:   No
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void timeout (int n) {
    puts("Timeout");
    exit(-1);
}

void initialize (void) {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    signal(SIGALRM, timeout);
    alarm(30);
}

int main (int argc, char ** argv) {
    char buffer[0x80];

    initialize();

    printf("[*] buffer is on: %p\n", buffer);
    puts("[*] Now send data to buffer: ");
    scanf("%180s", buffer);

    return 0;
}
