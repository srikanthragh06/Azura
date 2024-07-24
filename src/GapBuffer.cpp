#include "GapBuffer.h"

namespace azura
{
    void GapBuffer::left()
    {
        if (l > 0)
        {
            l--;
            r--;
            buffer[r + 1] = buffer[l];
            buffer[l] = ' ';
        }
    }

    void GapBuffer::right()
    {
        if (r < bufferSize - 1)
        {
            l++;
            r++;
            buffer[l - 1] = buffer[r];
            buffer[r] = ' ';
        }
    }

    void GapBuffer::left(int position)
    {
        while (position < l)
        {
            left();
        }
    }

    void GapBuffer::right(int position)
    {
        while (l < position)
        {
            right();
        }
    }

    void GapBuffer::grow()
    {
        int newGapSize = gapSize * 2;
        char *newBuffer = new char[newGapSize * 20];

        std::memcpy(newBuffer, buffer, l);
        std::fill(newBuffer + l, newBuffer + r + 1, ' ');
        std::memcpy(newBuffer + l + newGapSize, buffer + r + 1, bufferSize - r - 1);

        delete[] buffer;

        r = l + newGapSize - 1;
        bufferSize = bufferSize + newGapSize - gapSize;
        buffer = newBuffer;
        gapSize = newGapSize;
    }

    GapBuffer::GapBuffer(int newGapSize)
    {
        gapSize = newGapSize;
        l = 0;
        r = l + gapSize - 1;
        bufferSize = newGapSize * 20;
        buffer = new char[bufferSize];

        std::fill(buffer, buffer + bufferSize, ' ');
    }

    GapBuffer::~GapBuffer()
    {
        delete[] buffer;
    }

    void GapBuffer::displayBuffer()
    {
        for (int i = 0; i < bufferSize + gapSize; ++i)
        {
            if (i < l || i > r)
            {
                if (buffer[i] == ' ')
                {
                    std::cout << '_';
                }
                else
                {
                    std::cout << buffer[i];
                }
            }
            else if (i == l)
            {
                std::cout << '[';
            }
            else if (i == r)
            {
                std::cout << ']';
            }
            else
            {
                std::cout << 'G';
            }
        }
        std::cout << std::endl;
    }

    void GapBuffer::moveCursorPosition(int position)
    {
        if (position >= bufferSize || position < 0)
        {
            return;
        }

        if (position < l)
        {
            this->left(position);
        }
        else
        {
            this->right(position);
        }
    }

    void GapBuffer::moveCursorBack(unsigned times)
    {
        int newPos = l - times;
        if (newPos < 0)
        {
            newPos = 0;
        }
        this->left(newPos);
    }

    void GapBuffer::moveCursorAhead(unsigned times)
    {
        int newPos = l + times;
        if (newPos + gapSize > bufferSize)
        {
            newPos = bufferSize - gapSize;
        }

        this->right(newPos);
    }

    void GapBuffer::insert(char c)
    {
        if (l == r)
        {
            this->grow();
        }
        buffer[l] = c;
        l++;
    }

    void GapBuffer::insert(const char *s, int n)
    {
        for (int i = 0; i < n; i++)
        {
            this->insert(s[i]);
        }
    }

    void GapBuffer::insert(std::string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            this->insert(s[i]);
        }
    }

    void GapBuffer::backSpace()
    {
        if (l > 0)
        {
            l--;
            buffer[l] = ' ';
        }
    }
    void GapBuffer::backSpace(unsigned times)
    {
        while (times > 0 && l > 0)
        {
            this->backSpace();
            times--;
        }
    }

    void GapBuffer::backSpacePosition(int position)
    {
        if (position < 0 || position >= bufferSize)
            return;

        while (position < l)
        {
            backSpace();
        }
    }
}
