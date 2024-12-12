LowestCommonAncestorInBST: LowestCommonAncestorInBST.o
	g++ -g -o LowestCommonAncestorInBST.exe LowestCommonAncestorInBST.o -pthread    

LowestCommonAncestorInBST.o: LowestCommonAncestorInBST/LowestCommonAncestorInBST.cpp
	g++ -g  -c -pthread LowestCommonAncestorInBST/LowestCommonAncestorInBST.cpp
