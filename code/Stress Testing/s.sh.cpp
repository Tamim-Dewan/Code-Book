g++ -std=c++17 -O2 -o a a.cpp
g++ -std=c++17 -O2 -o brute brute.cpp
g++ -std=c++17 -O2 -o gen gen.cpp

for ((i = 1; ; ++i)); do
	echo "Test $i"
	./gen $i > in.txt
	./a < in.txt > out_a.txt
	./brute < in.txt > out_brute.txt

	if ! diff -w out_a.txt out_brute.txt > /dev/null; then
		echo "Mismatch found on test $i"
		echo "Input:"
		cat in.txt
		echo "Your output:"
		cat out_a.txt
		echo "Expected output (brute):"
		cat out_brute.txt
		break
	fi
done