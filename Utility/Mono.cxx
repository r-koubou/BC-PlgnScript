/* =========================================================================

Mono.cxx

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

/*

 0.0: Bypass
~0.9: Solo L
~1.9: Solo R
2.0:  Mono

*/

string name        = "Mono Checker";
string description = "0.0: Bypass, ~0.9: Solo L, ~1.9: Solo R, 2.0: Mono";
string author      = "R-Koubou";

array<string> inputParametersNames = { "Mode" };
array<double> inputParameters( 1 );
array<double> inputParametersMin     = { 0 };
array<double> inputParametersMax     = { 2 };
array<double> inputParametersDefault = { 0 };

double mode   = 0;

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
    const double L = ioSample[ 0 ];
    const double R = ioSample[ 1 ];
    const double v = mode;
    double result  = 0;

    if( v == 0 )
    {
        return;
    }

    // 0.1~0.9: Solo L
    else if( v > 0 && v <= 0.9 )
    {
        result = L;
    }
    // 1.1~1.9: Solo R
    else if( v >= 1.0 && v <= 1.9 )
    {
        result = R;
    }
    // max: Mono
    else
    {
        result = ( L + R ) / 2;
    }
    ioSample[ 0 ] = result;
    ioSample[ 1 ] = result;
}

 void updateInputParameters()
 {
    mode   = inputParameters[ 0 ];
 }
