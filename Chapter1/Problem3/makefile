ifeq ($(wildcard IsPermutationSort),)
	CLEAN_PERMSORT =	 
else
	CLEAN_PERMSORT = IsPermutationSort
endif

ifeq ($(wildcard IsPermutation),)
	CLEAN_PERM =
else
	CLEAN_PERM = IsPermutaiton
endif

IsPermutation:
	rm -f CLEAN_PERM
	g++ -g IsPermutation.cpp -o IsPermutation

IsPermutationSort:
	rm -f CLEAN_PERMSORT
	g++ -g IsPermutationSort.cpp -o IsPermutationSort

IsPerumation2:
	g++ -g IsPerumation2.cpp -o IsPerumation2

clean:
	rm -f $(CLEAN_PERM)
	rm -f $(CLEAN_PERMSORT)
	

