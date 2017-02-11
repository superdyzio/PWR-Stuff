type 'a llist = LNil | LCons of 'a * (unit -> 'a llist)

let ltl = function
LNil -> failwith "ltl"
| LCons (_, xf) -> xf();;

let rec lfrom k = LCons (k, function () -> lfrom (k+1));;

let rec ltake = function
(0, _) -> []
| (_, LNil) -> []
| (n, LCons(x,xf)) -> x::ltake(n-1, xf());;

let rec toLazyList = function
[] -> LNil
| h::t -> LCons(h, function () -> toLazyList t);;

let rec replicateElements (k, list) =
	let rec replicate (n,l) =
		match (n,l) with
		| (_, LNil) -> LNil
		| (0,LCons(_,t)) -> replicate (k,t())
		| (n, LCons(h, _)) -> LCons(h, fun () -> replicate (n-1, l))
	in replicate(k, list)
	
	let lfib =
	let rec fib (number, acc) =
		LCons(number, fun () -> fib(acc, number + acc))
	in fib(0, 1)
