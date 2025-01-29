(define (greater a b c) (cond ((and (> a b) (> b c)) (+ (* a a) (* b b)))
        ((and (> b a) (> c a)) (+ (* b b) (* c c)))
        ((and (> a b) (> c b)) (+ (* a a) (* c c)))))
