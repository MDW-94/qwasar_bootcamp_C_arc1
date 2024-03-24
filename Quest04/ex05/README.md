
<img width="288" alt="Screenshot 2024-03-24 at 12 57 44" src="https://github.com/MDW-94/qwasar_bootcamp_C_arc1/assets/138756503/4ba380c6-7661-43ee-8ccf-0434e51d5fcb">

Coordinate System in C

Design a simulator for a spaceship.
This simulator create a virtual "space" and kee;s track of the basic movements and directions of a given ship

Your job is to keep track of where the ship is and it's orientation relative to its starting point

The simulator must take in a string of letters that represent a planned flight path for the spaceship

"RRALALAA is interpretted as Turn right, turn right, advance, turn left, advance, advance"

Once given this initial flight path, your program must return the x,y coordinates of a ship's final destination as well as it's orientation relative to the starting point

Orientation is represented as left, right, up or down

Space is infinite, so the x,y coordinates you return could be placed on a seemingly infiinite grid and can be negatieve or positive values

EG upward facing ship at 0,0 - takes "RRALAA" - the finish will be 2, -1 and orientation will be right (facing right)

OUTPUT: "{x: X, y: Y, direction: 'DIRECTION'}" - struct?
This function returns a STRING
you can use 'snprintf'


## Commentary
I’ve been continuing to develop my programming skills through Qwasar’s Elite Software Engineer course on a part-time basis. We’ve been learning C - it’s a lot of fun! 
🛰 - Excited to share one of my favourite functions, which I had previously coded in JS earlier in the course - a coordinate system 
By developing this function first in Javascript and then in C, I’ve learned a lot about the differences between compiled languages like C and interpreted languages like Python and Javascript. Converting my original function to a new language forced me to focus on memory allocation, pointers & structs ⚙️

📝 - What have I learned - 📝

📚 - Our computers are like enormous libraries. With some empty shelves and some full shelves - each character/integer/bit of data lives on one of these shelves, with their own memory address. These addresses are like the locations of books on shelves.

⤴️ - Pointers
Pointers are used when we want to reference these addresses - they store the address of another variable. Like a library catalogue used to locate a book, pointers allow you to work with the data at these addresses.

Pointers are abstracted away from us in Python and Javascript for convenience, making it far simpler and safer (due to memory errors) to focus on the application of the code over its functionality - the trade-off is performance.

Because pointers store memory addresses, they typically look like digits and letters, making it complex to reference them directly:

0x7fff5fbff73c

Imagine writing that all the time when you just want “H”.

A pointer allows us to say “get that” - we can then also increment through memory address. For example, in a character array (a string) “Hello” - a pointer for this array might return the first memory address of “H”. We can then increment through this array using ‘ptr++’ the pointer then traverses the string. It’s like an arrow pointing to a bookshelf; when we move the arrow, we’re pointing to another part of the bookshelf.

Why not just make another variable with “H”?
Do you need two of the same variables in your code? Or can you reference one differently?

🧠 - Memory Management
Because C doesn’t abstract memory management away from the programmer, methods like ‘malloc()’ (memory allocation / m + alloc) mean we can dynamically declare space on the heap - often when we don’t know the size of our data structures at compile time.

An example: I need a string to be outputted from this function. A string is essentially an array of characters (with an extra ‘null-terminator’ at the end).

What is compile time? ⏰
The moment we convert our C language code to machine code.

What is the heap? 🌊
A pool of memory used by the computer - it’s like a “big pile” of data accessed indirectly through references. It must be deallocated (“freed”) after usage if that memory address is to be used again.

In Python and Javascript, “automatic garbage collection” abstracts this away from us 🚮

🧮 - Function and Logic can persist between languages
I wrote this function in Javascript originally. I made an array of directions, two counters and processed them through a for loop with if statements related to the inputted string. The result is the process of updating through the iteration of the for loop. This is the same in the C program, except I had to explicitly allocate memory, define structures and handle pointers to access the data. But at the end of the day, this function returns the coordinates of the ship!

Thanks for reading! Had a lot of fun building this. I’m still looking for an entry-level position to continue my passion for programming. Any C developers see any mistakes, inconsistencies or have a leaner way of building this then feel free to message - I’m always looking to learn and improve.
