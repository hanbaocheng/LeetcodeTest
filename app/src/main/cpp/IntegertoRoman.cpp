//
// Created by bhan on 12/15/17.
//
#include "Solution.h"

static const auto ____= [](){
    ios::sync_with_stdio(false);
    cin.tie();
    return nullptr;
}();

/**
 * Symbol 	I 	V 	X 	L 	C       D 	    M
 * Value 	1 	5 	10 	50 	100 	500 	1,000
 * @param num
 * @return
 */
string Solution::intToRoman(int num) {
    vector<string> units = {"","I", "II","III","IV","V", "VI","VII","VIII","IX"};
    vector<string> decades = {"","X", "XX","XXX","XL","L", "LX","LXX","LXXX","XC"};
    vector<string> hundreds = {"","C", "CC","CCC","CD","D", "DC","DCC","DCCC","CM"};
    vector<string> thousands = {"","M", "MM","MMM"};

    string roman;

    int thousand = num / 1000;
    roman.append(thousands[thousand]);
    int hundred = (num % 1000) / 100;
    roman.append(hundreds[hundred]);
    int decade = (num % 100) / 10;
    roman.append(decades[decade]);
    int unit = num % 10;
    roman.append(units[unit]);

    return roman;
}

int Solution::romanToInt(string s) {

    map<char, int> roman_to_int = {{'I', 1},
                                   {'V', 5},
                                   {'X', 10},
                                   {'L', 50},
                                   {'C', 100},
                                   {'D', 500},
                                   {'M', 1000}};
    int ret = 0;
    int start = 0;
    while (start < s.size() - 1) {
        int value = roman_to_int[s[start]];
        int next = roman_to_int[s[start + 1]];
        if ( value >= next) {
            ret += value;
        }
        else {
            ret += next - value;
            ++start;
        }
        ++start;
    }
    if(start == s.size() - 1)
        ret += roman_to_int[s[start]];

    return ret;
}