select * from 
(
	select klient,round(sum(KwotaSprzedazy),2) KwotaSprzedazy,rok from
	(
	select sod.CustomerID klient,subtotal KwotaSprzedazy,YEAR(sod.orderdate) rok from sales.SalesOrderHeader sod
	) as a
	group by klient,rok
) as p 
pivot (avg(KwotaSprzedazy) for rok in ([2012],[2013])) pvt
order by klient