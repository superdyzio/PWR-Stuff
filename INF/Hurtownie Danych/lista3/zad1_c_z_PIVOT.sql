select * from 
(
	select pracId,klient,round(sum(KwotaSprzedazy),4) KwotaSprzedazy,rok from
	(
		select sod.SalesPersonID pracId,sod.CustomerID klient,subtotal KwotaSprzedazy,YEAR(sod.orderdate) rok from sales.SalesOrderHeader sod
		where sod.SalesPersonID is not NULL	
	) as a
	group by pracId,klient,rok
) as p 
pivot (sum(KwotaSprzedazy) for rok in ([2011],[2012],[2013],[2014])) pvt
order by pracId