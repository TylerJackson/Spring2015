;;;; Homework 1
;;; by Tyler Jackson
;;; 2/15/2015

;;;Problem 1

;;find the min and max atom in a hierarchical list
(defun findMinMax(l)
       (loopThrough l '())
)
;;This will loop through each element in a hierarchical list storing the min and max in the cons called result
(defun loopThrough(l result)
			    ;;if the list is empty then our loop has finished going through all the elements so return the current
			    ;;min and max (base case)
      (cond ((null l) result)
      		    ;;if the first element of the list is an atom then call loopthrough with the new list as the cdr of l 
      		    ;;and the min max result cons being updated based on the (car l) -check if its a min against car of  
      		    ;;result and check if its a max against cdr of result
            ((atom (car l)) (loopThrough (cdr l) (cons (compareMin (car result) (car l)) (compareMax (cdr result) (car l)))))
                ;;if the first element in the list is also a list then call loopthrough with the first argument being 
                ;;the list (car l) and the second argument being the result from calling loopthrough with (cdr l) and 
                ;;the current result
            (t (loopThrough (car l) (loopThrough (cdr l) result)))
      )
)
;;had to use this instead of just normal min because of case where the result cons hasn't been set yet
;;you'd be comparing a number to nil
(defun compareMin(resultVal element)
      (cond ((null resultVal) element)
      		((numberp element) (min element resultVal))
            (t nil)
      )
)
;;had to use this instead of just normal max because of case where the result cons hasn't been set yet
;;you'd be comparing a number to nil
(defun compareMax(resultVal element)
      (cond ((null resultVal) element)
      		((numberp element) (max element resultVal))
            (t nil)
      )
)

;;;Problem 2 

;;will count the number of atoms in a list
(defun atomCount(l)
    (cond ((null l) 0)  	;if the list is empty return 0 for the first part of the base case       
          ((atom l) 1)		;if the list is an atom return 1
          ((atom (car l)) (+ 1(atomCount(cdr l)))) 		;if the (car l) is an atom return 1 + atomCount on cdr 
          (t (+ (atomCount(car l))(atomCount(cdr l))))	;if the (car l) is a list call atomCount on car + atomCount cdr
    )
)

;;;Problem 3

;;will find the frequency of each top level instance in a list and return it in a list of conses
(defun frequency (l)
	(frequency1 l '())	;call frequency1 with initial result of an empty frequency list
)
;;will loop through the top level elements in list updating the frequency for each one
(defun frequency1 (l result)
			;; if list is empty then return the result base case
	(cond ((null l) result)		
			;;otherwise return frequency1 with the new list being (cdr l) and the 
			;;result being the updateResult of car l and the current result
	      (t (frequency1 (cdr l) (updateResult (car l) result)))	
	)
)
;;takes an element and either adds it to the frequency list if its a first occurence or increments the frequency if
;;its bucket already exists
(defun updateResult (element result)
					;;if the result is empty then just add the first frequency bucket
			(cond ((null result) (list (cons element '1)))
					;;if the element we're checking = the key of the first bucket then return the same list with that
					;;first bucket's counter incremented 
			      ((equal element(caar result)) (append (list(cons (caar result) (+ 1(cdar result)))) (cdr result)))
			      	;;if we are at the end of the list then return the result list with the added frequency bucket 
			      	;;for the current element
			      ((null (cdr result)) (append (list(car result)) (list (cons element '1))))
			      	;;otherwise return the current first part of result and call updateResult on the rest of the
			        ;;buckets
			      (t (append (list(car result)) (updateResult element (cdr result))))
			)
)

;;;Problem 4

;;same as frequency from problem 3 but calls our new frequency1_prob4
(defun frequency_prob4 (l)
	(frequency1_prob4 l '())
)

;;just uses the same updateResult from problem 3, but now will drill down to the frequency of each atom, not just the 
;;top level elements in the initial list
(defun frequency1_prob4 (l result)
	(cond ((null l) result)
			;;if first element of list is an atom then call frequency1_prob4 with (cdr l) as the first argument and
			;;updateResult (car l and the current result) as the second argument
		  ((atom (car l)) (frequency1_prob4 (cdr l) (updateResult (car l) result)))
		    ;;otherwise car l is a list so call frequency1_prob4 with car l as the first argument with a second
		    ;;argument of frequency1_prob4((cdr l) result)
	      (t (frequency1_prob4 (car l) (frequency1_prob4 (cdr l) result))) 
	)
)





