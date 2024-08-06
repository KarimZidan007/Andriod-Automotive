## I/O

IO contain till #C++20 standart 
1. cin 
2. cout 
3. cerr

IO conntain #C++23 standart 
1. print() 
2. format()


difference between buffered and unbuffered

1. buffred
data will be buffered first at a specfic buffer 
on c when we scanf a string then i scanf a charachter after it the enter after string will be stored on charachter so i need to clear buffer before scanf again using fflush() 
EX: used with files

2. unbuffered 

data will not be buffered just if i write on console hello   h will be printed then e then l directory i do not pack them or buffer them 
- use it on logging if i want to write log
- used with network UDB protocole

- endl and \n

endl will push the whole buffer so if i use it multiple times it makes overhead
\n -> if i have two cout sequential -> they will merge it and just make a \n between it so if i want to push it using \n use fflush
  
## Manipultors

if iam going to be sw engineer and deal with data base and take data and manipulate it on a style (table for examble)

if i draw the style with my self and the numbers are large it will destory the style

|2223423423.42312312| 
|          |
|          |

like this 


In C++, the <iomanip> header provides a variety of manipulators for formatting input and output, especially for streams like std::cin and std::cout. Let's clarify the manipulators you mentioned and understand what fixed is used for:


1. setw(n)

    Purpose: Sets the width of the next input/output field.
    Usage: cin >> setw(5) >> arr or cout << setw(5) << value
    Effect: When used with cin, it limits the number of characters read to n. When used with cout, it sets the width of the field to n characters for the next output.

2. setfill(ch)

    Purpose: Sets the character ch to be used for filling the unused part of the field width.
    Usage: cout << setfill('*') << setw(5) << value
    Effect: If the value doesn't occupy the entire width set by setw, the remaining space is filled with ch.

3. setprecision(n)

    Purpose: Sets the decimal precision for floating-point numbers.
    Usage: cout << setprecision(3) << value
    Effect: When used alone, it sets the total number of significant digits for floating-point numbers.

4. fixed -> display always the dot

    Purpose: Used to control the format of floating-point output.
    Usage: cout << fixed << setprecision(3) << value
    Effect: When combined with setprecision, it specifies that the precision should be interpreted as the number of
     digits after the decimal point, rather than the total number of significant digits.

5. endl
    Purpose: Inserts a newline character into the output stream and flushes the stream.
    Usage: std::cout << "Hello" << std::endl;
    Effect: Outputs "Hello" followed by a newline and flushes the buffer.

6. hex
    Purpose: Converts numbers to hexadecimal format.
    Usage: std::cout << std::hex << 255;
    Effect: Outputs the number 255 in hexadecimal format (ff).

7. showbase

    Purpose: Shows the base of numeric values (e.g., 0x for hex, 0 for octal).
    Usage: std::cout << std::showbase << std::hex << 255;
    Effect: Outputs 255 in hexadecimal format with a base prefix (0xff).

8. flush
    Purpose: Flushes the output stream buffer.
    Usage: std::cout << "Hello" << std::flush;
    Effect: Ensures that "Hello" is immediately outputted and the buffer is cleared.

9.  left
    Purpose: Left-justifies the output within the field width set by setw.
    Usage: std::cout << std::left << std::setw(10) << 42;
    Effect: The number 42 will be printed left-justified in a field of width 10 (42 ).

10. right

    Purpose: Right-justifies the output within the field width set by setw.
    Usage: std::cout << std::right << std::setw(10) << 42;
    Effect: The number 42 will be printed right-justified in a field of width 10 ( 42).


11. setf 
    The setf function sets one or more format flags for the output stream. This affects how subsequent data is formatted. The setf function can take two parameters:

    Flag: The format flag to set (e.g., std::ios::hex for hexadecimal output).
    Mask: (Optional) A mask to specify which flags to apply the setting to. If omitted, the default is to apply the setting to the entire stream.

12. unsetf 
    The unsetf function clears (or unsets) one or more format flags that were previously set. This allows you to revert to default formatting or apply a different format.

```c++


```
```c++

 char arr[5];
 arr="hello world"
here hello will be stored in arr[5] and if world write on a place that is read only it will give seg fault so it is undefined behaviout 

so c++ intrdouce 
#include <iostream>
#include <iomanip>

int main() {
    // Using endl
    std::cout << "Hello" << std::endl;

    // Using setw and setfill
    std::cout << std::setfill('*') << std::setw(10) << 42 << std::endl;

    // Using setprecision and fixed
    std::cout << std::setprecision(3) << std::fixed << 3.141592 << std::endl;

    // Using hex and showbase
    std::cout << std::showbase << std::hex << 255 << std::endl;

    // Using flush
    std::cout << "Flushing output" << std::flush;

    // Using left and right
    std::cout << std::left << std::setw(10) << 42 << "|" << std::endl;
    std::cout << std::right << std::setw(10) << 42 << "|" << std::endl;
    // Set the format to hexadecimal
    std::cout.setf(std::ios::hex);

    std::cout << "Hexadecimal: " << number << std::endl; // Outputs: 0xff

    std::cout.unsetf(std::ios::hex);
    std::cout << "Decimal: " << number << std::endl; // Outputs: 255

    return 0;
}


```

Explanation of fixed
    Without fixed: setprecision(3) sets the total number of significant digits, so pi is rounded to 3.14 (two digits
     before and one digit after the decimal point).
    With fixed: setprecision(3) specifies the number of digits after the decimal point, so pi is rounded to 3.142. 


## Files I/O

    io/streams 
1. istream (cin ,getline)
2. ostream (cout , printf)


fstreams

1. ifstream -> inputs only 
2. ofstream -> output only 

so i use fstream to take input and display output 


1. fstream file("myFile.txt) 
    i should check if there is myFile if not make it and open it  using above code 

**NOTE** 
1. fstream file("myFile.txt,mode ) -> mode could be in or app or truncate

if i opened file i have to close 
out.close()


2. std::ofstream out ("test.txt");  
out <<"HELLO"

- i can not use input mode with ofstream -> error 
```c++
std::ofstream outfile ("outfile.txt" , std::ios::out); 

std::fs stream fio;

fio.open("example.txt",std::ios::in | std::ios::out); 

//same as 

std::fstream fio("example.txt")
```
mods -> 
in -> open for reading
out -> open for writing 
app -> append
ate -> open and seek to the end of the file 
trunc -> if the file is opened for output and it already existed its previous content wll be deleted 

check if file is  open
```c++
1. if(file.is_open()) or if (file)


move ptr to start file.seekg(0, std::ios::beg);

std::getline(file,str) -> read and increment ptr

while(file.eof() ==false)
{
std::getline(file,str)  -> read and increment
std::cout<<str<<std::endl;
tol mana mawslt4 l a5r el file read more
}
```
if i used an output file in input more 

declaration will pass without error
but if i use a functionallity it will error it because there is no in methods on output stream




