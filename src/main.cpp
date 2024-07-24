#include "SFML/Graphics.hpp"
#include "GapBuffer.h"

int main()
{
    azura::GapBuffer gapBuffer(2);

    // Display initial buffer
    gapBuffer.displayBuffer();

    // Insert characters one by one
    gapBuffer.insert('H');
    gapBuffer.displayBuffer();
    gapBuffer.insert('e');
    gapBuffer.displayBuffer();
    gapBuffer.insert('l');
    gapBuffer.displayBuffer();
    gapBuffer.insert('l');
    gapBuffer.displayBuffer();
    gapBuffer.insert('o');
    gapBuffer.displayBuffer();

    // Insert a string
    gapBuffer.insert(" World", 6);
    gapBuffer.displayBuffer();

    // Move cursor back and insert a character
    gapBuffer.moveCursorBack(6);
    gapBuffer.displayBuffer();
    gapBuffer.insert('!');
    gapBuffer.displayBuffer();

    // Move cursor ahead and insert another string
    gapBuffer.moveCursorAhead(3);
    gapBuffer.displayBuffer();
    gapBuffer.insert(" Everyone", 9);
    gapBuffer.displayBuffer();

    // Backspace a few times
    gapBuffer.backSpace(5);
    gapBuffer.displayBuffer();

    // Move cursor position directly
    gapBuffer.moveCursorPosition(5);
    gapBuffer.displayBuffer();

    // Insert another character
    gapBuffer.insert('X');
    gapBuffer.displayBuffer();

    return 0;
}