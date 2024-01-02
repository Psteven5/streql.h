# streql.h - fast string equality for C/C++
Simple C header file containing the function streql(), that checks for equality between two null-terminated strings.

Alternative to strcmp() from the C standard library that performs a lexicographical comparison. 
Instead, streql() simply returns 1/true if the two strings are equal, else 0/false.
Keep in mind that streql() only provides a benefit for sufficiently large strings, as there is no competing with the compiler.
