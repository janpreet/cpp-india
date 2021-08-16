// Inspired from https://www.geeksforgeeks.org/code-to-generate-the-map-of-india-with-explanation/
// Inspired from https://github.com/itsksaurabh/go-india
// Author: LinkedIn: http://linkedin.com/in/janpreet , Github: https://github.com/janpreet/

#include <iostream>
#include <string>
#include <cmath>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define WHITE   "\033[37m" 

std::string genFlag();
int getRows(std::string);
void color(std::string, std::string, int, int);

int main()
{
    std::string map = genFlag();
    int rows = getRows(map);
    int first = floor(rows/3);
    int third = first;
    int second = rows - (first + third);    
    int newLine = map.find('\n', 0)+1;

    color(map, RED, 1, (first*newLine));
    color(map, WHITE, (first*newLine), ((first+second)*newLine));
    color(map, GREEN, ((first+second)*newLine), ((first+second+third)*newLine));       
    
    std::cout << std::endl;

    return 0;
}

std::string genFlag()
{
    int a = 10, b = 0, c = 10;
 
    // The encoded string after removing first 31 characters
    // Its individual characters determine how many spaces
    // or exclamation marks to draw consecutively.
    char const* str = "TFy!QJu ROo TNn(ROo)SLq SLq ULo+UHs UJq "
                "TNn*RPn/QPbEWS_JSWQAIJO^NBELPeHBFHT}TnALVlBL"
                "OFAkHFOuFETpHCStHAUFAgcEAelclcn^r^r\\tZvYxXyT|S~Pn SPm "
                "SOn TNn ULo0ULo#ULo-WHq!WFs XDt!";
    std::string flag = "";
    
    while (a != 0)
    {
        // read each character of encoded string
        a = str[b++];
        while (a-- > 64)
        {
            if (++c == 90) // 'Z' is 90 in ascii
            {
                // reset c to 10 when the end of line is reached
                c = 10;        // '\n' is 10 in ascii
 
                // print newline
                flag += '\n'; // or putchar(c);
            }
            else
            {
                // draw the appropriate character
                // depending on whether b is even or odd
                if (b % 2 == 0)
                    flag += '!';
                else
                    flag += ' ';
            }
        }
    }
    return flag;    
}

int getRows(std::string str)
{   
    int rows = 0;
    rows = count(str.begin(), str.end(), '\n');
    return rows;
}

void color(std::string str, std::string col, int start, int end)
{
    for(int i=start; i<=end; ++i)
    {
        std::cout << col << str.at(i) << RESET;
    }      
}