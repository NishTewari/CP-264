Name: Nishant Tewari
ID: 190684430
Email: tewa4430@mylaurier.ca
WorkID: CP264-a2
Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols: A - assignment, Q - question 
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If marker gives different evaluation value say 1, it will show 
[2/2/1] in the marking report. 

Evaluation grid: [self-evaluation/total/marker-evaluation]

A2

Q1 Computing Fibonacci numbers
Q1.1 iterative_fibonacci()                [5/5/*]
Q1.2 recursive_fibonacci()                [3/3/*]

Q2 Array & polynomial
Q2.1 display_polynomial()                 [2/2/*]
Q2.2 horner()                             [5/5/*]
Q2.3 bisection()                          [5/5/*]

Q3 2D array & matrix
Q3.1 sum()                                [2/2/*]
Q3.2 is_magic_square()                    [3/3/*]
Q3.3 transpose_matrix()                   [2/2/*]
Q3.4 multiply_matrix()                    [3/3/*]

Total:                                   [30/30/*]

Copy and paste the console output of your public test in the following. This will help markers to evaluate your program if it fails the testing.  

Q1 output:
**Iterative algorithm measurement**
iterative_fibonacci(40):102334155
high address:4294953892
low address:4294953856
iterative_fibonacci(40) memory span:36
time_span(iterative_fibonacci(40) for 500000 times):110.0 (ms)

**Recursive algorithm measurement**
recursive_fibonacci(40):102334155
high address:4294953892
low address:4294951360
recursive_fibonacci(40) memory span:2532
time_span(recursive_fibonacci(40) for 10 times) in (ms):18015.0

**Comparison of recursive and iterative algorithms**
memory_span(recursive_fibonacci(40))/memory_span(iterative_fibonacci(40)):70.3
time_span(recursive_fibonacci(40))/time_span(iterative_fibonacci(40)):8188636.4



Q2 output:
P(0.00)=1.00*0.00^3+2.00*0.00^2+3.00*0.00^1+4.00*0.00^0=4.00
P(1.00)=1.00*1.00^3+2.00*1.00^2+3.00*1.00^1+4.00*1.00^0=10.00
P(10.00)=1.00*10.00^3+2.00*10.00^2+3.00*10.00^1+4.00*10.00^0=1234.00
P(-2.00)=-2.00
P(2.00)=26.00
root=-1.67
P(-1.67)=-1.00



Q3 output:
m1:
   8   1   6
   3   5   7
   4   9   2
sum(m1):45
is_magic_square(m1):1

m1':
   8   3   4
   1   5   9
   6   7   2
sum(m1'):45
is_magic_square(m1'):1

m1*m1':
 101  71  53
  71  83  71
  53  71 101
sum(m1*m1'):675
is_magic_square(m1*m1'):0

