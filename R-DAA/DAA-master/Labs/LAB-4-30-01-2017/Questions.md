#Radix Sort on Strings
In the last classes you learnt about Radix Sort.  It is a sorting algorithm which
looks at the speci c digits of an integer and sorts them in a stable manner.
In this exercise,  you are required to apply the idea of Radix Sort for sorting
strings, under the following assumptions,
1.  There are
n
strings and every one of them is of length
k
.
2.  The strings are composed of any printable characters, i.e.  starting from
ASCII value 32 to 126, any character could be there.
3.  For comparison you can use the ASCII values of the characters.
Given  the  value  of
n
,
k
and  the  strings  themselve  in  an  \input"  array,  you
are required to implement
Two
versions of the Radix Sort algorithm with the
following restrictions,
1.  For the  rst version, you are allowed to declare only one \output" char-
acter array with the dimensions of \input" and a one-dimensional integer
array with maximum dimension 100.
2.  For the second version, you are only allowed to declare only one 1-dimensional
integer array with maximum dimension 100.
Try revisiting the radix sort algorithm and think how it can be implemented
within this constraints.  You may consider that the number of strings (
n
) will
be less than 2
64
and length of each string is less than 10.
Notes:

You are allowed to use the string library functions of C.

The  \input"  array  is  already  declared  and  populated  in  the  template.
The  constraints  on  the  two  versions  speci es  the  extra  arrays  that  you
can declare.  You can declare as many individual variables as you like.

Any  new  array  that  you  create  within  the  given  constraints,  should  be
created  only  once  throughout  the  program  (no  declaration  in  recursive
function) and may be reused.

You can write as many auxalliary functions as you like.
