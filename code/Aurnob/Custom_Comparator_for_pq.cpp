auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;  // Min-heap based on 'first'
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);