#include "test.h"
#include "lexicalAnalyzer.h"

bool areTestsPassed()
{
    bool isTestOne = lexicalAnalyzer("q10");
    return
        !lexicalAnalyzer("q10") &&
        lexicalAnalyzer("12323") &&
        !lexicalAnalyzer("1234.E+10") &&
        lexicalAnalyzer("123.123E-1023") &&
        lexicalAnalyzer("5343E+100") &&
        !lexicalAnalyzer("32323E++") &&
        !lexicalAnalyzer("32323A") &&
        lexicalAnalyzer("123.00") &&
        !lexicalAnalyzer("1234.A");
}
