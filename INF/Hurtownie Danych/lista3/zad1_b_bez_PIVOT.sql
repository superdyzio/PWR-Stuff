select klient, round(sum("2012"),2) as "2012", round(sum("2013"),2) as "2013" from
( 
	select klient ,KwotaSprzedazy as "2012" ,null as "2013" from 
	(
		select sod.CustomerID klient,subtotal KwotaSprzedazy,YEAR(sod.orderdate) rok from sales.SalesOrderHeader sod
	) as p2
	where rok=2012
	union  
	select klient ,null as "2012" ,KwotaSprzedazy as "2013" from 
	(
		select sod.CustomerID klient,subtotal KwotaSprzedazy,YEAR(sod.orderdate) rok from sales.SalesOrderHeader sod
	) as p3
	where rok=2013
) as pAll
group by klient
order by klient