int totalMoney(int n) {
    int total = 0;
    int weeks = n / 7;
    int remainingDays = n % 7;

    for (int i = 0; i < weeks; ++i) {
        total += (i + 1) * 7 + 21;
    }

    for (int i = 0; i < remainingDays; ++i) {
        total += weeks + i + 1;
    }

    return total;
}
