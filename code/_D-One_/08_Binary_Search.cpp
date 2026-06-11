auto check = [&](int x) -> bool {
    return /* condition using mid */;
};

int low = 0, high = n - 1, ans = -1;
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (check(mid)) {
        ans = mid;
        low = mid + 1;
    } else {
        high = mid - 1; // lower bound
    }
}