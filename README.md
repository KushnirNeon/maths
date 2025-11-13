# maths

1. Newton-Raphson Method

This program finds a root of a cubic function using the Newton-Raphson iterative method. It calculates successive approximations until the function value is within a specified precision. Users can input their own precision or use the default value.

2. Simple Iteration Method

The program solves a cubic equation using the simple iteration (fixed-point) method. Iterations continue until the difference between successive approximations is smaller than the chosen precision. Users can also specify a custom precision.

3. Chord (Secant) Method

This program finds a root of a nonlinear equation using the chord method. The iteration formula updates estimates until the absolute difference between successive approximations is less than a given tolerance. It efficiently approximates the root without requiring derivative calculations.

4. Gradient Descent for Linear Systems (4x4)

This program solves a 4x4 system of linear equations using the gradient descent method. It iteratively updates the solution vector until convergence within a specified tolerance. The step size is controlled by a predefined tau parameter.

5. Gradient Descent for Another 4x4 System

Similar to the previous program, this one uses gradient descent to solve a 4x4 linear system. The algorithm iteratively improves the solution vector until the norm of the change falls below a tolerance. It demonstrates convergence for a different system matrix and vector.

6. Doolittle Decomposition & Condition Number

The program checks matrix symmetry, performs Doolittle decomposition, solves a 3x3 linear system, and computes determinant and condition number. It illustrates how decomposition can simplify solving linear equations. Additionally, it evaluates matrix stability through its condition number.

7. Gauss-Seidel Method

This program implements the Gauss-Seidel iterative method for solving a 4x4 linear system. Each variable is updated using the latest available values until the overall error falls below a threshold. The program also checks for matrix symmetry to ensure method applicability.

8. Simple Iteration Method with Condition Number

The program solves a 5x5 linear system using the simple iteration method and computes the condition number of the system. It also calculates and prints the inverse of the matrix. This demonstrates iterative solution and analysis of numerical stability.

9. Power Method for Eigenvalues

This program finds the largest and smallest eigenvalues of a matrix using the power method. The algorithm iteratively approximates the dominant eigenvalue and eigenvector. It provides a simple technique to study spectral properties of a matrix.

10. Jacobi Method for Eigenvalues

The program computes all eigenvalues of a symmetric matrix using the Jacobi rotation method. Off-diagonal elements are iteratively zeroed to diagonalize the matrix. It demonstrates a numerical approach to finding eigenvalues without using built-in functions.

11. Modified Newton Method for Systems

This program solves a nonlinear system of two equations using a modified Newton method. The Jacobian matrix is computed and inverted to iteratively update the solution. Iterations continue until changes in the variables are smaller than the desired precision.

12. Newton Polynomial Approximation

This program evaluates the maximum deviation between a function and its Newton interpolating polynomial over a range of x-values. It illustrates polynomial approximation of a nonlinear function. The step size can be adjusted to improve accuracy.

13. Newton Polynomial Coefficients

The program calculates divided differences and constructs the Newton interpolating polynomial from given data points. It prints the polynomial in standard form. This demonstrates interpolation for approximating functions based on discrete points.

14. Quadratic Spline Approximation

This program approximates a nonlinear function using piecewise quadratic splines. It computes the maximum deviation between the spline and the original function. This method allows smooth interpolation across different intervals.

15. Quadratic Spline with Derivatives

The program constructs quadratic splines for a set of points using derivative information at interval boundaries. Coefficients for each spline segment are computed and printed. This approach provides a more accurate piecewise approximation of the function.

16. Linear Spline Approximation

This program approximates a function with piecewise linear splines over a specified interval. It calculates slopes for each segment and outputs the linear spline equations. It demonstrates a simple method for linear interpolation.

17. Quadrature Formula (Numerical Integration)

The program computes weights for a quadrature formula and approximates the integral of a nonlinear function. Nodes and weights are calculated to achieve numerical integration accuracy. The final approximate integral value is printed.

18. Trapezoidal and Simpson Rules

This program estimates the integral of a nonlinear function using the trapezoidal and Simpson rules. It handles automatic adjustment of subintervals for Simpson’s method. The results demonstrate the difference between two common numerical integration techniques.
