/*
 *	Authored 2022, Damien Zufferey.
 *
 *	Copyright (c) 2022, Signaloid.
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in all
 *	copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#include <stdio.h>
#include <uncertain.h>
#include "uniform.h"

int
main(int argc, char * argv[])
{
	/*
	 *	Create an uniform distribution. This operation does two things.
	 *
	 *	1. It creates the distribution and associate it with x.
	 *
	 *	2. We take the mean from the distribution and store it in x. We call
	 *	   this the particle value of x. The particle is a normal 'double' value.
	 *
	 *	We use the particle to provide seamless compatibility without requiring
	 *	to change already existing code. By default, we take the mean of the
	 *	samples used to create the distribution.
	 */
	double x = uniformDistribution(0, 2);

	/*
	 *	When computing with x, the operation happens (1) on the level of the
	 *	particle and (2) on the distribution. So the particle value for x2 is
	 *	the particle value of x squared and the distribution associated with
	 *	x2 is the distribution of x squared.
	 */
	double x2 = x * x;

	/*
	 *	Prints the particle x2.
	 */
	printf("E[X]² = %.2lf\n", x2);

	/*
	 *	Use the libUncertain API to query the distribution associated with x2.
	 *	We want to print the expected value which, in technical terms, is also
	 *	called the 1st moment of the distribution.
	 */
	printf("E[X²] = %.2lf\n", libUncertainDoubleNthMoment(x2, 1));

	return 0;
}

