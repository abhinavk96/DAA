Hashing
Write a program that takes words and stores them into a hash table of linked
lists.  When the input has all been read, the program prints statistics about the
hash table:
1.  how many items it contains;
2.  the length of its longest list;
3.  the average number of comparisons needed to  nd each of the items in
the table;
4.  the standard deviation for the number of comparisons needed to  nd each
of the items in the table.
Find  out,  by  testing  each  of  the  three  hash  functions  on  all  hash  table  sizes
between 1040 and 1050, which function performs best and which performs worst
on the strings. In particular,  nd out what table sizes the functions work well for
and what table sizes lead to poor performance.  In general, the lower the average
number of comparisons, the better, and for tables with averages approximately
equal, the lower the standard deviation, the better.
The hash functions are given below.  In the  rst three formulas,
c
k
is the
k
th
character of the word to be hashed, where
k
ranges from 1 to
n
, the length of
the word.
1.  (a variant on the ETH algorithm)
h
0
= 1;
h
k
=
c
k

((
h
k

