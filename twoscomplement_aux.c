// CISC 221 A2
// PART A
// returns 1 if x - y doesn't overflow, 0 if it does
int subtract2sc_issafe(int x, int y)
{
    int w = sizeof(int) * 8;                                // bits in an int
    unsigned int diff = (unsigned int) x - (unsigned int) y; // unsigned avoids undefined behaviour

    int sx = ((unsigned int) x >> (w - 1)) & 1;             // sign of x
    int sy = ((unsigned int) y >> (w - 1)) & 1;             // sign of y
    int sd = (diff >> (w - 1)) & 1;                         // sign of result

    // overflow only if x and y differ in sign and the result's sign doesn't match x
    if (sx != sy && sd != sx)
        return 0;
    return 1;
}