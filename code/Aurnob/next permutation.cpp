int main() {
vector<int> nums = {1, 2, 3};
// Sort first to ensure we get every single permutation
sort(nums.begin(), nums.end());
do{
for(int n:nums) {
    cout << n << " ";}
    cout << "\n";
}while(next_permutation(nums.begin(),nums.end()));
return 0;}