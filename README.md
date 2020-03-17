# Fractal-Generator
Made Mandelbrot Fractal using complex number (Using C++). Mandelbrot  -> https://en.wikipedia.org/wiki/Mandelbrot_set 

Used Complex numer and Complex Number arithmetic toset pixel values and print Mandelbrot Fractal. 

The Mandelbrot set is a example of a fractal in mathematics. It is named after Benoît Mandelbrot, a Polish-French-American mathematician. The Mandelbrot set is important for chaos theory. The edging of the set shows a self-similarity, which is not perfect because it has deformations.

The Mandelbrot set can be explained with the equation zn+1 = zn2 + c. In that equation, c and z are complex numbers and n is zero or a positive integer (natural number). Starting with z0=0, c is in the Mandelbrot set if the absolute value of zn never becomes larger than a certain number (that number depends on c), no matter how large n gets.

Mandelbrot was one of the first to use computer graphics to create and display fractal geometric images, leading to his discovering the Mandelbrot set in 1979. That was because he had access to IBM's computers. He was able to show how visual complexity can be created from simple rules. He said that things typically considered to be "rough", a "mess" or "chaotic", like clouds or shorelines, actually had a "degree of order". The equation zn+1 = zn2 + c was known long before Benoit Mandelbrot used a computer to visualize it.

Images are created by applying the equation to each pixel in an iterative process, using the pixel's position in the image for the number 'c'. 'c' is obtained by mapping the position of the pixel in the image relative to the position of the point on the complex plane.

The shape of the Mandelbrot Set is represented in black in the image on this page.

For example, if c = 1 then the sequence is 0, 1, 2, 5, 26,…, which goes to infinity. Therefore, 1 is not an element of the Mandelbrot set, and thus is not coloured black.

On the other hand, if c is equal to the square root of -1, also known as i, then the sequence is 0, i, (−1 + i), −i, (−1 + i), −i…, which does not go to infinity and so it belongs to the Mandelbrot set.

When graphed to show the entire Set, the resultant image is striking, pretty, and quite recognizable.

There are many variations of the Mandelbrot set, such as Multibrot, Buddhabrot, and Nebulabrot.

Multibrot is a generalization that allows any exponent: zn+1 = znd + c. These sets are called Multibrot sets. The Multibrot set for d = 2 is the Mandelbrot set.


