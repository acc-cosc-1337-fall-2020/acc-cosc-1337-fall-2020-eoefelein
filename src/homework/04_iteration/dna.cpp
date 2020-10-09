#include "dna.h"
#include<string>
#include<iostream>

using std::string; using std::cout;
/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const std::string& dna){
    // declare accumulator
    double gc = 0;
    for (int i=0; i<dna.length(); i++)
    {
        if( dna[i] == 'G' || dna[i] == 'C')
        {
            gc++;
        }
    }
    return gc/dna.length();
}

/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
// may have to start from the beginning but test this first...
std::string get_reverse_string(std::string dna)
{
    string revDNA = "";
    for(int i=dna.length()-1; i>=0; i--)
    {
        revDNA.push_back(dna[i]);
    }
    return revDNA;
}


/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string

*/
string get_dna_complement(string dna)
{
    string rev_str = get_reverse_string(dna);
    for (int i=0; i<rev_str.length(); i++)
    {
        switch(rev_str[i])
        {
        case 'A':
            rev_str[i] = 'T';
            break;
        case 'T':
            rev_str[i] = 'A';
            break;
        case 'C':
            rev_str[i] = 'G';
            break;
        case 'G':
            rev_str[i] = 'C';
            break;
        }
    }
    return rev_str;
}