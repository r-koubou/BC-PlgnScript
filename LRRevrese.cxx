/* =========================================================================

LRRevrese.cxx

Copyright (c) 2017 R-Koubou

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

======================================================================== */

string name        = "L/R Revrese";
string description = "L/R Revrese for sound check.";

bool initialize()
{
    // accept only stereo streams
    if( audioInputsCount != 2 )
    {
        print( "Error: this script requires 2 audio channels, not " + audioInputsCount );
        return false;
    }
    return true;
}

void processSample( array<double>& ioSample )
{
    double tmp = ioSample[ 0 ];
    ioSample[ 0 ] = ioSample[ 1 ];
    ioSample[ 1 ] = tmp;
}
