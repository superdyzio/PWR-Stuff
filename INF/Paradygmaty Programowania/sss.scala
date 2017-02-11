def swap(tab: Array[Int], i: Int, j: Int): Unit =
{
val aux = tab(i)
tab(i) = tab(j)
tab(j) = aux
}

def choose_pivot(tab: Array[Int], m: Int, n: Int): Int =
tab((m + n) / 2)

def partition(tab: Array[Int], l: Int, r: Int): (Int, Int) =
{
var i = l
var j = r
val pivot = choose_pivot(tab, l, r)
while (i <= j) {
while (tab(i) < pivot) i += 1
while (pivot < tab(j)) j -= 1
if (i <= j) {
swap(tab, i, j)
i += 1
j -= 1
}
}
(i, j)
}

def quick(tab: Array[Int], l: Int, r: Int): Unit =
if (l < r) {
val (i, j) = partition(tab, l, r)
if ((j - l) < (r - i)) {
quick(tab, l, j)
quick(tab, i, r)
} else {
quick(tab, i, r)
quick(tab, l, j)
}
}

val x = Array(4,3,5,1,6,7,2)
quick(x,0,x.length-1)



def whileLoop(cond: => Boolean, block: => Unit): Unit =
if (cond) {
block
whileLoop(cond, block)
}

def whileLoop(cond: => Boolean)(block: => Unit): Unit =
if (cond) {
block
whileLoop(cond)(block)
}