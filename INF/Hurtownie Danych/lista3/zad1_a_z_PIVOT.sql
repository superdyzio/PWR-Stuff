select * from 
(
	select sod.SalesPersonID pracId,round(subtotal,2) KwotaSprzedazy,YEAR(sod.orderdate) rok from sales.SalesOrderHeader sod
) as p 
pivot (sum(KwotaSprzedazy) for rok in ([2011],[2012],[2013],[2014])) pvt