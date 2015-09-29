# Monophonic Pitch Tracking

Monophonic Pitch Tracking includes [A Robust Algorithm for Pitch Tracking (RAPT)](https://github.com/dem123456789/Monophonic-Pitch-Tracking/blob/master/fxrapt/A%20Robust%20Algorithm%20for%20Pitch%20Tracking%20(RAPT).pdf) and [Yet Another Algorithm for Pitch Tracking (YAAPT)](https://github.com/dem123456789/Monophonic-Pitch-Tracking/blob/master/yaapt/Zahorian2008spectral.pdf) algorithms source code.   Rewrite RAPT for practice in src diretory.


 
## Instruction

1. `URL.md` contains micellaneous monophonic pitch tracking algorithms resources
2. `fxrapt` contains source code of RAPT
3. `yaapt` contains source code of YAAPT
4. `resources` includes all compressed files for download
5. `Evaluation Code` includes Audio Melody Extration evaluation code based on MIREX metrics
6. `src` contains my effort to rewrite RAPT

## Resources

* [RAPT](http://www.ee.ic.ac.uk/hp/staff/dmb/voicebox/doc/voicebox/fxrapt.html)
* [YAAPT](http://ws2.binghamton.edu/zahorian/yaapt.htm)
* [SAcC] (http://labrosa.ee.columbia.edu/projects/SAcC/)
* [YIN] (https://github.com/JorenSix/TarsosDSP/blob/master/src/core/be/tarsos/dsp/pitch/Yin.java)
* [mir-1k dataset](https://sites.google.com/site/unvoicedsoundseparation/mir-1k)
* [Peak detection using parabolic interpolation](https://ccrma.stanford.edu/~jos/parshl/Peak_Detection_Steps_3.html)

## Contributing

1. Fork
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request

## Source

*A spectral/temporal method for robust fundamental frequency tracking*  
Stephen A. Zahorian, Hongbing Hu  
The Journal of the Acoustical Society of America, 123, 4559-4571

*A Robust Algorithm For Pitch Tracking*  
D. Talkin  
Speech Coding and Synthesis, pp-495-518, 1995

## Credits

*Enmao Diao*

## License

The MIT License (MIT)

Copyright (c) [2015] [Enmao Diao]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
