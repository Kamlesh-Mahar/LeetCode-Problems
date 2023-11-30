int minimumOneBitOperations(int n) {
    int result = 0;
    bool toggle = true;

    while (n > 0) {
        result ^= n;
        n >>= 1;
        toggle = !toggle;
    }

    return toggle ? result : result;
}
