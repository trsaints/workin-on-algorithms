(define (cube x)
    (* x x x))

(define (improve guess x)
    (/ (+ (/ x (square guess))
        (* 2 guess))
        3))

(define (good-enough? guess x)
    (< (abs (- (cube guess) x)) 0.0001))

(define (cube-root-iter guess x)
    (if (good-enough? guess x)
        guess
        (cube-root-iter (improve guess x) x)))

(define (cube-root x)
    (cube-root-iter 1.0 x))