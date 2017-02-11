module Macierz =
	struct
	type 'a t
	exception Empty of string

	let utworz((a00, a01, a02, a03), (a10, a11, a12, a13), (a20, a21, a22, a23), (a30, a31, a32, a33)) = [|[|a00;a01;a02;a03|];[|a10;a11;a12;a13|];[|a20;a21;a22;a23|];[|a30;a31;a32;a33|]|]
	
	let suma x y =
		let x0 = Array.length x and y0 = Array.length y in
			let y1 = if y0 = 0 then 0 else Array.length y.(0) in
				let z = Array.make_matrix x0 y1 0 in
				for i = 0 to x0-1 do
					for j = 0 to y1-1 do
						z.(i).(j) <- x.(i).(j) + y.(i).(j)
					done
				done;
		z

	let mnozenie x y =
		let x0 = Array.length x and y0 = Array.length y in
			let y1 = if y0 = 0 then 0 else Array.length y.(0) in
				let z = Array.make_matrix x0 y1 0 in
					for i = 0 to x0-1 do
						for j = 0 to y1-1 do
							for k = 0 to y0-1 do
								z.(i).(j) <- z.(i).(j) + x.(i).(k) * y.(k).(j)
							done
						done
					done;
		z

	let transpozycja x =
		let x0 = Array.length x in
			let x1 = if x0 = 0 then 0 else Array.length x.(0) in
				let z = Array.make_matrix x0 x1 0 in
					for i = 0 to x0-1 do
						for j = 0 to x1-1 do
							z.(i).(j) <- x.(j).(i)
						done
					done;
		z

end;;

let a = utworz((1,1,1,1),(2,2,2,2),(3,3,3,3),(4,4,4,4));;
let b = utworz((4,4,4,4),(3,3,3,3),(2,2,2,2),(1,1,1,1));;

suma a b;;
mnozenie a b;;
transpozycja a;;