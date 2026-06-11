// je order e sort korte chai , oi order return kore dibo
bool cmp(pll a, pll b){
    if(a.ff != b.ff) return a.ff < b.ff; // first increasing
    return a.ss > b.ss; // second decresing
}
