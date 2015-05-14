;Tyler Jackson
;HW 3 
;AI
;3/26/15


;GCD-------------------------------------

(defun GCD_E(A B)
      (cond ((= A 0) B)
            ((= B 0) A)
            (t (GCD_E B (rem A B) ) )
      )

;;If A = 0 then GCD(A,B)=B, since the GCD(0,B)=B, and we can stop.  
;;If B = 0 then GCD(A,B)=A, since the GCD(A,0)=A, and we can stop.  
;;Write A in quotient remainder form (A = B⋅Q + R)
;;Find GCD(B,R) using the Euclidean Algorithm since GCD(A,B) = GCD(B,R)
;;copied from https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm
)

(defun GCD_D(A B)
      (cond ((= A B) A)
            ((> A B) (GCD_D (- A B) B))
            (t (GCD_D A (- B A)))
      )

;;int gcd(int m, int n) {
;;  if(m == n)
;;      return m;
;;   else if (m > n)
;;      return gcd(m-n, n);
;;   else
;;      return gcd(m, n-m);
;;}
;;copied from https://sketchingdream.wordpress.com/gcd4/
)

;ISPRIME--------------------------------------------
(defun isPrime(N)
      (isPrime2 N (- N 1))
)

(defun isPrime2(N D)
      (cond ((= D 1) t)
            ((= 0 (rem N D)) nil)
            (t (isPrime2 N (- D 1)))
      )
)
;ISPALINDROME---------------------------------------
(defun ispalindrome (l)
      (cond ((atom l) t)
            ((and (atom (cadr l)) (eq (car l) (cadr l))) t)
            ((eq (car l) (car (last l))) (ispalindrome (allbutlast (cdr l))))
      )
)

(defun allbutlast (l)

      (cond ((null (cdr l)) nil)
            (t (append (list (car l)) (allbutlast (cdr l))))
      )
)
;Traverse Tree--------------------------------------
(defun traverseTree (l type)
      (cond ((string= type "pre") (traversePre l))
            ((string= type "post") (traversePost l))
            ((string= type "in") (traverseIn l))
            (t "Invalid traverse type")
      )
)
(defun traversePre (l)
      (cond ((and (null (cadr l)) (null (caddr l))) (list (car l)))
            ((null (cadr l)) (append (list (car l)) (traversePre (caddr l))))
            ((null (caddr l)) (append (list (car l)) (traversePre (cadr l))))
            (t (append (list (car l)) (traversePre (cadr l)) (traversePre (caddr l))))
      )
)

(defun traverseIn (l)
      (cond ((and (null (cadr l)) (null (caddr l))) (list (car l)))
            ((null (cadr l)) (append (list (car l)) (traverseIn (caddr l))))
            ((null (caddr l)) (append (traverseIn (cadr l)) (list (car l))))
            (t (append (traverseIn (cadr l)) (list (car l)) (traverseIn (caddr l))))
      )
)

(defun traversePost (l)
      (cond ((and (null (cadr l)) (null (caddr l))) (list (car l)))
            ((null (cadr l)) (append (traversePost (caddr l)) (list (car l))))
            ((null (caddr l)) (append (traversePost (cadr l)) (list (car l))))
            (t (append (traversePost (cadr l)) (traversePost (caddr l)) (list (car l))))
      )
)
;Insertion Sort-------------------------------------
(defun insertionSort (l)
      (cond ((null (cdr l)) l)
            (t (insertionHelper '() l))
      )
)

;;call initially with sorted empty --- '()
(defun insertionHelper (sorted unsorted)
      (cond  ((null unsorted) sorted)
             ((null sorted) (insertionHelper (list (car unsorted)) (cdr unsorted)))
             ((null (cdr unsorted)) (insert '() sorted (car unsorted)))
             (t (insertionHelper  (insert '() sorted (car unsorted)) (cdr unsorted)))
      )            
)

;;call with left as empty -- '()
(defun insert(left right num)
            ;;if right has only 1 element and it is < num
            ;;return left right num
      (cond ((and (null (cdr right)) (> num (car right))) (append left right (list num)))
            ;;if right only has 1 element and it is bigger than num
            ((and (or (< num (car right)) (= (car right) num)) (null (cdr right))) (append left (list num) right))
            ;;if left is empty and num is < car right
            ((and (null left) (< num (car right))) (append (list num) right))
            ;;if left is empty and num is > car right - just recall it moving car right to left
            ((null left) (insert (list (car right)) (cdr right) num))
            ;;if  left < = num < right
            ((and (or (< (car (last left)) num) (= (car (last left)) num)) (< num (car right))) (append left (list num) right))
            ;;move the first element from right over to the end of left and repeat
            (t (insert (append left (list (car right))) (cdr right) num))
      )
)

;MERGE SORT
(defun mergeSort (l)
  (cond
    ((not (= (length l) 1)) (append (mergeLists (mergeSort (subseq l 0 (floor (/ (length l) 2)))) (mergeSort (subseq l (floor (/ (length l) 2)))))))
    (t (list (car l)))
  )
)

(defun mergeLists (a b)
    (cond ((null b) a)
          ((null a) b)
          ((< (car b) (car a)) (append (list (car b)) (mergeLists a (cdr b))))
          (t (append (list (car a)) (mergeLists (cdr a) b)))
    )
)    













