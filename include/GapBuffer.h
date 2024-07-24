#pragma once

#include <iostream>
#include <cstring>

namespace azura
{
    class GapBuffer
    {
    private:
        int bufferSize;
        char *buffer;
        int gapSize;
        int l;
        int r;

        void left();
        void right();
        void left(int position);
        void right(int position);

        void grow();

    public:
        GapBuffer(int newGapSize = 2);
        ~GapBuffer();

        void displayBuffer();

        void moveCursorPosition(int position);

        void moveCursorBack(unsigned times = 1);
        void moveCursorAhead(unsigned times = 1);

        void insert(char c);
        void insert(const char *s, int n);
        void insert(std::string s);

        void backSpace();
        void backSpace(unsigned times);
        void backSpacePosition(int position);
    };
}