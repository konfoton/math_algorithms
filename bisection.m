function [x] = bisection(func, a, b, tol)
while(b-a) > tol
    c = (a + b)/2;
    if func(c) * func(b) < 0
        a = c;
    else
        b = c;
    end
end
x = b;
end

