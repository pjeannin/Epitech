#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    char mem[60 * 1024];
    unsigned int pos = 0;
    memset(mem, 0, 60 * 1024);
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    while (mem[pos])
{
    ++pos;
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    --pos;
    --mem[pos];
}
    ++pos;
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    ++mem[pos];
    write(1, &mem[pos], 1);

    return (0);
}