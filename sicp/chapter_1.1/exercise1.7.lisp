(define (sqrt-iter prev-guess guess x)
	(if (good-enough? prev-guess guess)
		guess
		(sqrt-iter guess (improve guess x) x)))

(define (improve guess x)
	(/ (+ guess (/ x guess)) 2))

; We define a tolerance of 0.0001 to state it as "good enough"

(define (good-enough? prev-guess current-guess)
    (< (/ (abs (- current-guess prev-guess)) current-guess) 0.0001))

(define (sqrt x)
	(sqrt-iter 0.0 1.0 x))